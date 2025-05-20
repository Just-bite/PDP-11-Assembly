%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.1"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <cctype>
    #include <iomanip>
    #include <fstream>
    #include "structure.hh"
    class Mediator;
    class Validator;
    class ListMaker;
  
    int16_t parse_oct(const std::string&);
    int16_t parse_hex(const std::string&);
    std::string check_for_listing_flags(int16_t);


}// code requieres

// The parsing context.
%param { Mediator& m }
%param { Validator& valid}
%param { ListMaker& list}

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
  #include "mediator.hh"
  #include "validator.hh"
  #include "listmaker.hh"
    bool is_at;
    bool is_numsign;
    bool is_left;
    bool is_right;
    bool is_minus;
    const int DATA_SEGMENT = 01000;
    const int CODE_SEGMENT = 02000;
}

%define api.token.prefix {TOK_}
%token
  COMMA   ","
;

%token <std::string> INSTRUCTION "instruction"
%token <std::string> COMMENT "comment"
%token <std::string> NEWLINE "newline"
%token <std::string> BRANCH "branch"
%token <std::string> REGISTER "register"
%token <std::string> LABEL "label"
%token <std::string> PORT "port"
%token <std::string> EQU_DIRECTIVE "directive_EQU"
%token <std::string> BYTE_DIRECTIVE "directive_BYTE"
%token <std::string> WORD_DIRECTIVE "directive_WORD"
%token <std::string> DATA_S "data_seg"
%token <std::string> CODE_S "code_seg"

%token <std::string> CHAR_LITERAL "char_literal"
%token <std::string> AT "at"
%token <std::string> NUMSIGN  "numsign"
%token <std::string> LPAREN "lparen"
%token <std::string> RPAREN "rparen"
%token <std::string> MINUS "minus"
%token <std::string> PLUS "plus"
%token <std::string> HEX_NUM "hexnum"
%token <std::string> OCT_NUM "octnum"
%token <std::string> MULT "mult"
%token <std::string> DIV "div"
%token <std::string> MOD "mod"
%token <std::string> LSHIFT "lshift"
%token <std::string> RSHIFT "rshift"
%token <std::string> BAND "band"
%token <std::string> BOR "bor"
%token <std::string> BXOR "bxor"
%token <std::string> ASCII_DIRECTIVE "ascii"
%token <std::string> ASCIIZ_DIRECTIVE "asciiz"
%token <std::string> STRING_LITERAL "string_literal"
%token <int> DEC_NUM "decnum"

%type <int16_t> number notreg prelp prereg equ_expr word_value
%type <std::vector<int16_t>> word_expr
%type <std::vector<int8_t>> byte_expr 
%type <int8_t> byte_value
%type <Operand> adressingS adressingD
%type <std::string> expr postreg

%left PLUS MINUS
%left MULT DIV MOD
%left LSHIFT RSHIFT
%left BAND BOR BXOR
%left UMINUS

%%

%start program1;

program1: input YYEOF {
            list.print_symbol_table(m.program().get_symbol_table());
            if(m.create_listing)
                list.print_listing_to_file("listing.txt");
        };

input:
        %empty  {};
    | 
        input line {};

line:
        expr NEWLINE {
            if (m.create_listing)
                list.add_to_listing($1, m.program().getILC());
        };
    |   
        expr COMMENT NEWLINE { 
            if (m.create_listing)
                list.add_to_listing($1, m.program().getILC(), $2);
        };
    | 
        COMMENT NEWLINE {
            if (m.create_listing)
                list.add_to_listing($1, m.program().getILC());
        }
    |
        NEWLINE {};
    | 
        expr YYEOF { 
            if(m.create_listing) 
                list.add_to_listing($1, m.program().getILC());
        };

expr:
        INSTRUCTION adressingS COMMA adressingD {
            m.program().add_instruction($1, {$2, $4});
            $$ = $1 + " " + $2.string_form + ", " + $4.string_form;
        };
    |
        INSTRUCTION adressingD { 
            m.program().add_instruction($1, {$2});
            $$ = $1 + " " + $2.string_form;
        };
    |
        INSTRUCTION {
            m.program().add_instruction($1, {});
            $$ = $1;
        };
    |
        LABEL expr {
            m.program().process_label($1, false, 0);
            $$ = $1 + " " + $2;
        };
    |
        BRANCH LABEL {
            if($1 != "JMP"){
                m.program().add_instruction($1, {Operand(0, RELATIVE, $1, 0, $2)});
            }
            else
                m.program().add_instruction($1, {Operand(0, ABSOLUTE, $1, 0, $2)});
            m.program().process_label($2, false, 0);
            $$ = $1 + " " + $2;
        };
    |
        BRANCH DEC_NUM {
            if($1 != "JMP")
                m.program().add_instruction($1,{Operand(0,RELATIVE, $1, $2, "numof")});
            else 
                m.program().add_instruction($1,{Operand(0,ABSOLUTE, $1, $2, "numof")});
            $$ = $1 + " " + std::to_string($2);
        };   
    |    
        LABEL WORD_DIRECTIVE word_expr {
            std::string listing = " ";
            m.program().process_label($1, false, m.program().getILC());
            for (auto val : $3) {
                m.program().set_word_table(m.program().getILC(), val); 
                m.program().addILC(2);
                listing += std::to_string(val);
            }
            $$ = $1 + " " + $2 + listing;
        };
    |    
        LABEL BYTE_DIRECTIVE byte_expr {
            std::string listing = " ";
            m.program().process_label($1, false, m.program().getILC());
            for (auto val : $3) {
                m.program().set_byte_table(m.program().getILC(), val);
                m.program().addILC(); 
                listing += std::to_string(val) + " ";
            }
            $$ = $1+ " " + $2 + listing;
        };
    |
        LABEL ASCII_DIRECTIVE STRING_LITERAL {
            if ($3.size() >= 2) { 
                m.program().process_label($1, true, m.program().getILC());
                for (size_t i = 1; i < $3.size() - 1; i++) {
                    char c = $3[i];
                    m.program().set_byte_table(m.program().getILC(), static_cast<uint8_t>(c));
                    m.program().addILC();
                }
            } 
            else 
                m.program().process_label($1, true,m.program().getILC());
            $$ = $1 + " " + $2 + " " + $3;
        };
    |
        LABEL ASCIIZ_DIRECTIVE STRING_LITERAL { 
            if ($3.size() >= 2) {  
                m.program().process_label($1.substr(0, $1.size() - 1), true, m.program().getILC());
                for (size_t i = 1; i < $3.size() - 1; i++) {
                    char c = $3[i];
                    m.program().set_byte_table(m.program().getILC(), static_cast<uint8_t>(c));
                    m.program().addILC();
                }
                m.program().set_byte_table(m.program().getILC(), 0);
                m.program().addILC();
            } else {
                m.program().process_label($1, true,m.program().getILC());
                m.program().set_byte_table(m.program().getILC(),  0);
                m.program().addILC();
            }
            $$ = $1 + " " + $2 + " " + $3;
        };
    |
        LABEL EQU_DIRECTIVE equ_expr {
            m.program().process_label($1.substr(0, $1.size() - 1), true, $3);
            $$ = $1 + " " + $2 + " " + std::to_string($3) ;
        }
    |
        LABEL {
            m.program().process_label($1, false, 0);
            $$ = $1;
        }; 
    |
        DATA_S {
            m.program().setILC(DATA_SEGMENT);
            $$ = $1;
        }
    |
        CODE_S {
            m.program().setILC(CODE_SEGMENT);
            $$ = $1;
        }

adressingS:
        REGISTER {
            $$ = Operand(atoi($1.substr(1).c_str()), REG, $1);
            valid.current_addressing_flags &= REG;
        };
    |
        prereg REGISTER postreg {
            std::string spec_signs = check_for_listing_flags($1);
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else {
                $$ = Operand(atoi($2.substr(1).c_str()), adr_type, spec_signs + $2 + " " +$3, $1);
                valid.current_addressing_flags &= REG;
            }
        };
    | 
        notreg {
            std::string spec_signs = check_for_listing_flags($1);
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else {
                $$ = Operand(-1, adr_type, spec_signs, $1);    
                valid.current_addressing_flags &= REG;
            }
        };
    |
        NUMSIGN LABEL {
                valid.current_addressing_flags |= HASH|NUM; 
                $$ = Operand(m.program().get_symbol_table()[$2].value, valid.determine_adressing_type(), 
                                          $1 + " " +  $2, m.program().get_symbol_table()[$2].value, $2); 
        };
    |   
        PORT { $$ = Operand(0,ABSOLUTE,$1,0,$1); };
     
adressingD:
        REGISTER {
            $$ = Operand(atoi($1.substr(1).c_str()), REG, $1);
            valid.current_addressing_flags &= REG;
        };
    |
        prereg REGISTER postreg {
            std::string spec_signs = check_for_listing_flags($1);
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR; 
            else {
                $$ = Operand(atoi($2.substr(1).c_str()), adr_type, spec_signs + $2 + " " + $3 , $1);
                valid.current_addressing_flags &= REG;
            }
        };
    | 
        notreg {
            std::string spec_signs = check_for_listing_flags($1);  
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else {
                $$ = Operand(-1, adr_type, spec_signs, $1);    
                valid.current_addressing_flags &= REG;
            }
        };
    |
        NUMSIGN LABEL {
            valid.current_addressing_flags |= HASH|NUM;
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else $$ = Operand(0, adr_type, $1 + " " + $2, 0, $2);
        };
    |   
        PORT { $$ = Operand(0, ABSOLUTE, $1, 0, $1); };


notreg:
        NUMSIGN number { 
            valid.current_addressing_flags |= HASH|NUM; 
            $$ = $2;
            is_numsign = true;
        };
    | 
        AT NUMSIGN number { 
            valid.current_addressing_flags |= AT_F|HASH|NUM; 
            $$ = $3;
            is_numsign = true;
            is_at = true;
        };

equ_expr: number
    | 
        LABEL {
            if (m.program().get_symbol_table().count($1) && m.program().get_symbol_table()[$1].is_defined) 
                $$ = m.program().get_symbol_table()[$1].value;
            else $$ = 0; 
        };
    | 
        equ_expr PLUS equ_expr { $$ = $1 + $3; };
    | 
        equ_expr MINUS equ_expr { $$ = $1 - $3; };
    | 
        equ_expr MULT equ_expr { $$ = $1 * $3; };
    | 
        equ_expr DIV equ_expr {
            if ($3 != 0) 
                $$ = $1 / $3;
            else {
                valid.display_error_message("Division by zero in equ expression");
                YYERROR;
            }
        };
    | 
        equ_expr MOD equ_expr {
            if ($3 != 0)
                $$ = $1 % $3;
            else {
                valid.display_error_message("Division by zero in equ expression");
                YYERROR;
            }
        };
    | 
        equ_expr LSHIFT equ_expr { $$ = $1 << $3; };
    | 
        equ_expr RSHIFT equ_expr { $$ = $1 >> $3; };
    |   
        equ_expr BAND equ_expr { $$ = $1 & $3; };
    | 
        equ_expr BOR equ_expr { $$ = $1 | $3; };
    | 
        equ_expr BXOR equ_expr { $$ = $1 ^ $3; };
    | 
        MINUS equ_expr %prec UMINUS { $$ = -$2; };
    | 
        LPAREN equ_expr RPAREN { $$ = $2; };

byte_expr:
        byte_value { $$ = {$1}; }
    | 
        byte_expr COMMA byte_value { 
            $1.push_back($3);
            $$ = $1;
         };

byte_value:
        number {$$ = static_cast<uint8_t>($1); };
    | 
        CHAR_LITERAL { $$ = static_cast<uint8_t>($1[1]); };
    | 
        LABEL {
            if (m.program().get_symbol_table().count($1) && m.program().get_symbol_table()[$1].is_defined) 
                $$ = static_cast<uint8_t>(m.program().get_symbol_table()[$1].value);
            else $$ = 0; 
        };
word_expr:
        word_value { $$ = {$1};}
    | 
        word_expr COMMA word_value {
            $1.push_back($3);
            $$ = $1;
        };

word_value:
        number
    | 
        LABEL {
            if (m.program().get_symbol_table().count($1) && m.program().get_symbol_table()[$1].is_defined) 
                $$ = static_cast<uint8_t>(m.program().get_symbol_table()[$1].value);
             else $$ = 0;
        };
number:
        HEX_NUM     { $$ = parse_hex($1); };
    |   
        OCT_NUM     { $$ = parse_oct($1); };
    |   
        DEC_NUM     { $$ = static_cast<int16_t>($1); };


prereg:
        LPAREN { 
            valid.current_addressing_flags |= LPAR; 
            is_left = true;
        };
    |   
        prelp LPAREN { 
            valid.current_addressing_flags |= LPAR;
            is_left = true;
        };

postreg:
        RPAREN { 
            valid.current_addressing_flags |= RPAR; 
            $$ = $1;
        };
    |   
        RPAREN PLUS { 
            valid.current_addressing_flags |= RPAR|PLS; 
            $$ = $1 + $2;
        };

prelp:
        AT MINUS {
            valid.current_addressing_flags |= AT_F|MIN; 
            is_at = true;
            is_minus = true;
        };
    |
        AT number {
            valid.current_addressing_flags |= AT_F|NUM;
            is_at = true; 
            $$ = $2;   
        };
    |
        AT { 
            valid.current_addressing_flags |= AT_F;
            is_at = true; 
        };
    | 
        MINUS { 
            valid.current_addressing_flags |= MIN;
            is_minus = true;

        };
    | 
        number {
            valid.current_addressing_flags |= NUM;
            $$ =$1;
        };
    
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}

int16_t parse_oct(const std::string& s) {
    size_t start = 0;
    bool negative = false;
    if (s.empty()) {
        throw std::invalid_argument("Empty octal string");
    }
    
    if (s[0] == '-') {
        negative = true;
        start = 1;
    } else if (s[0] == '+') {
        start = 1;
    }
    
    for (size_t i = start; i < s.size(); ++i) {
        char c = s[i];
        if (c < '0' || c > '7') 
            throw std::invalid_argument("Invalid octal digit: " + std::string(1, c));
        
    }
    
    long val = strtol(s.c_str(), nullptr, 8);
    if (val > INT16_MAX || val < INT16_MIN) 
        throw std::out_of_range("Octal number out of int16_t range");
    

    return static_cast<int16_t>(val);
}

int16_t parse_hex(const std::string& s) {
    size_t start = 0;
    bool negative = false;
    if (s.size() < 3) {
        throw std::invalid_argument("Hex number too short");
    }

    if (s[0] == '-') {
        negative = true;
        start = 1;
    } else if (s[0] == '+') {
        start = 1;
    }
    
    if (s[start] != '0' || (s[start+1] != 'x' && s[start+1] != 'X')) {
        throw std::invalid_argument("Hex number must start with 0x or 0X");
    }
    
    if (s.size() == start + 2) {
        throw std::invalid_argument("Empty hex number");
    }
    
    for (size_t i = start + 2; i < s.size(); ++i) {
        char c = s[i];
        if (!isxdigit(c)) 
            throw std::invalid_argument("Invalid hex digit: " + std::string(1, c));
    }
    
    long val = strtol(s.c_str(), nullptr, 16);
    if (val > INT16_MAX || val < INT16_MIN) 
        throw std::out_of_range("Hex number out of int16_t range");
    

    return static_cast<int16_t>(val);
}

std::string check_for_listing_flags(int16_t number) {
    std::string spec_signs = " ";
    if(is_at)
        spec_signs += "@";
    if(is_numsign)
        spec_signs += "#";
    if(is_minus)
        spec_signs += "-";
    if(number)
        spec_signs += std::to_string(number);
    if(is_left)
        spec_signs += "(";
    is_at = is_numsign = is_minus = is_left =  false;
    
    return spec_signs;
}