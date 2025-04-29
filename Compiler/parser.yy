%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.1"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    # include <string>
    # include <vector>
    # include <cstdint>
    # include <cctype>
    #include <iomanip>
    class driver;

    enum AddressingTypes : uint8_t {
        REG                     = 0b00000000,
        REG_INDIRECT            = 0b00110000,
        AUTO_INCREMENT          = 0b01110000,
        AUTO_INCREMENT_INDIRECT = 0b01110001,
        AUTO_DECREMENT          = 0b00110100,
        AUTO_DECREMENT_INDIRECT = 0b00110101,
        INDEXED                 = 0b00111000,
        INDEXED_INDIRECT        = 0b00111001,
        IMMEDIATE               = 0b00000101,
        ABSOLUTE                = 0b00001011,
        RELATIVE                = 0b10000000,
    };

    enum TokenFlags : uint8_t {
        NONE = 0b00000000,
        AT_F = 0b00000001, // @
        HASH = 0b00000010, // #
        MIN  = 0b00000100, // -
        NUM  = 0b00001000, // numbers
        LPAR = 0b00010000, // (
        RPAR = 0b00100000, // )
        PLS  = 0b01000000, // +
    };


    struct Operand {
        uint16_t value;
        int16_t offset = 0;
        AddressingTypes type = AddressingTypes::REG;
        uint8_t token_flags = NONE;

        Operand() : value(0), offset(0), type(REG), token_flags(NONE) {};
        Operand(uint16_t val, AddressingTypes t, int16_t disp = 0) 
            : value(val),offset(disp), type(t)  {};
    };

    struct Instruction {
      std::string mnemonic;
      std::vector<Operand> operands;
      uint16_t adress;
      uint8_t size;
    };

    struct LabelInfo {
        uint16_t    value;         // Значение LC
        bool        is_defined;    // Определена ли метка
        std::vector<uint16_t> refs;// Адреса ссылок на эту метку
    };
    

    int calculate_instr_size(const std::vector<Operand>& operands);
    void process_label(const std::string& name,driver& drv);
    void add_instruction(const std::string& mnemonic, 
                         const std::vector<Operand>& operands,driver& drv);
    
    void print_instr(driver& drv);
    void print_symbol_table(driver& drv);
    AddressingTypes determine_adressing_type();
    const char* addressingTypeToString(AddressingTypes type);
    int16_t parse_oct(const std::string& s);
    int16_t parse_hex(const std::string& s);


}// code requieres

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
  #include "driver.hh"
    int ilc = 0;
    uint8_t current_addressing_flags = NONE;
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
%token <std::string> DIRECTIVE "directive"
%token <std::string> AT "at"
%token <std::string> NUMSIGN  "numsign"
%token <std::string> LPAREN "lparen"
%token <std::string> RPAREN "rparen"
%token <std::string> MINUS "minus"
%token <std::string> PLUS "plus"
%token <std::string> HEX_NUM "hexnum"
%token <std::string> OCT_NUM "octnum"
%token <int> DEC_NUM "decnum"

%type <int16_t> number notreg prelp prereg
%type <Operand> adressingS adressingD


%%

%start program1;
program1: input YYEOF {
    print_instr( drv);
    print_symbol_table(drv);
    std::cout<<"ILC: "<<ilc<<std::endl;
    };

input:
    %empty  {};
    | input line {};

line:
     expr NEWLINE
    |expr COMMENT NEWLINE {std::cout << "comment : "<<$2 <<std::endl;};
    | NEWLINE {};

expr:
        INSTRUCTION adressingS COMMA adressingD {
            add_instruction($1,{$2,$4},drv);
        };
    |
        INSTRUCTION adressingD { 
            add_instruction($1,{$2},drv);
        };
    |
        INSTRUCTION {
            add_instruction($1, {},drv);
        };
    |
        LABEL expr {
            process_label($1,drv);
        };
    |
        BRANCH LABEL {
            add_instruction($1,{Operand(0,RELATIVE)},drv);
            process_label($2,drv);
        };
    |
        LABEL {
            process_label($1,drv);
        };    

adressingS:
        REGISTER {
            $$ = Operand(atoi($1.substr(1).c_str()), REG);
            current_addressing_flags &=REG;
        };
    |
        prereg REGISTER postreg {
            $$ = Operand(atoi($2.substr(1).c_str()),determine_adressing_type(),$1);
            current_addressing_flags &=REG;
        };
    | 
        notreg {
            $$ = Operand(-1,determine_adressing_type(),$1);    
            current_addressing_flags &=REG;
        };
     
adressingD:
        REGISTER {
            $$ = Operand(atoi($1.substr(1).c_str()), REG);
            current_addressing_flags &=REG;
        };
    |
        prereg REGISTER postreg {
            $$ = Operand(atoi($2.substr(1).c_str()),determine_adressing_type(),$1);
            current_addressing_flags &=REG;
        };


notreg:
        NUMSIGN number { 
            current_addressing_flags |= HASH|NUM; 
            $$ = $2;
        };
    | 
        AT NUMSIGN number { 
            current_addressing_flags |= AT_F|HASH|NUM; 
            $$ = $3;
        };

number:
        HEX_NUM     { $$ = parse_hex($1); }
    |   OCT_NUM     { $$ = parse_oct($1); }
    |   DEC_NUM     { $$ = static_cast<int16_t>($1); }


prereg:
        LPAREN { 
            current_addressing_flags |= LPAR; 
        };
    |   prelp LPAREN { 
            current_addressing_flags |= LPAR;
            $$ = $1;
        };

postreg:
        RPAREN { 
            current_addressing_flags |= RPAR; 
        };
    |   RPAREN PLUS { 
            current_addressing_flags |= RPAR|PLS; 
        };

prelp:
        AT MINUS {
            current_addressing_flags |= AT_F|MIN; 
        };
    |
        AT number {
            current_addressing_flags |= AT_F|NUM; 
            $$ = $2;   
        };
    |
        AT { 
            current_addressing_flags |= AT_F; 
        };
    | 
        MINUS { 
            current_addressing_flags |= MIN; 
        };
    | 
        number {
            current_addressing_flags |= NUM;
            $$ =$1;
        };
    
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}


    AddressingTypes determine_adressing_type() {
        switch(current_addressing_flags) {
            case HASH|NUM: return IMMEDIATE;
            case AT_F|HASH|NUM: return ABSOLUTE;
            case LPAR|RPAR: return REG_INDIRECT;
            case LPAR|RPAR|PLS: return AUTO_INCREMENT;
            case AT_F|LPAR|RPAR|PLS: return AUTO_INCREMENT_INDIRECT;
            case MIN|LPAR|RPAR: return AUTO_DECREMENT;
            case AT_F|MIN|LPAR|RPAR: return AUTO_DECREMENT_INDIRECT;
            case NUM|LPAR|RPAR: return INDEXED;
            case AT_F|NUM|LPAR|RPAR: return INDEXED_INDIRECT;
            default: return REG;
        }
        return REG;
    }

    void add_instruction(const std::string& mnemonic, 
                    const std::vector<Operand>& operands,driver& drv) {
        Instruction instr;
        instr.mnemonic = mnemonic;
        instr.operands = operands;
        instr.adress = ilc;
        instr.size = calculate_instr_size(operands);
        ilc += instr.size;
        drv.program.push_back(instr);
    }

    int calculate_instr_size(const std::vector<Operand>& operands) {
        int size = 2;
        for(const auto& op : operands) {
            if( op.type != REG)
                size += 2;
            if( op.type == RELATIVE){
                return 0;
            }
        }
        return size;
    }
    
void print_instr(driver& drv) {
    for(const auto& instr : drv.program) {
        std::cout<< instr.mnemonic << std::endl;
        for( const auto& op : instr.operands) {
            std::cout <<"op value: " << op.value << " ";
            std::cout <<"op offset: " << op.offset << " ";
            std::cout <<"op adressing type: " << addressingTypeToString(op.type)<< std::endl;
        }
    }
}

const char* addressingTypeToString(AddressingTypes type) {
    switch(type) {
        case REG:                      return "REG";
        case REG_INDIRECT:             return "REG_INDIRECT";
        case AUTO_INCREMENT:           return "AUTO_INCREMENT";
        case AUTO_INCREMENT_INDIRECT:  return "AUTO_INCREMENT_INDIRECT";
        case AUTO_DECREMENT:           return "AUTO_DECREMENT";
        case AUTO_DECREMENT_INDIRECT:  return "AUTO_DECREMENT_INDIRECT";
        case INDEXED:                  return "INDEXED";
        case INDEXED_INDIRECT:         return "INDEXED_INDIRECT";
        case IMMEDIATE:                return "IMMEDIATE";
        case ABSOLUTE:                 return "ABSOLUTE";
        case RELATIVE:                return "RELATIVE";
        default:                       return "UNKNOWN";
    }
}

int16_t parse_oct(const std::string& s) {
    if (s.empty()) {
        throw std::invalid_argument("Empty octal string");
    }
    if (s[0] != '0') {
        throw std::invalid_argument("Octal number must start with 0");
    }
    for (char c : s) {
        if (c < '0' || c > '7') {
            throw std::invalid_argument("Invalid octal digit: " + std::string(1, c));
        }
    }
    long val = strtol(s.c_str(), nullptr, 8);
    if (val > INT16_MAX || val < INT16_MIN) {
        throw std::out_of_range("Octal number out of int16_t range");
    }

    return static_cast<int16_t>(val);
}

int16_t parse_hex(const std::string& s) {
    if (s.size() < 3 || s[0] != '0' || (s[1] != 'x' && s[1] != 'X')) {
        throw std::invalid_argument("Hex number must start with 0x or 0X");
    }
    if (s.size() == 2) {
        throw std::invalid_argument("Empty hex number");
    }
    for (size_t i = 2; i < s.size(); ++i) {
        char c = s[i];
        if (!isxdigit(c)) {
            throw std::invalid_argument("Invalid hex digit: " + std::string(1, c));
        }
    }
    long val = strtol(s.c_str(), nullptr, 16);
    if (val > INT16_MAX || val < INT16_MIN) {
        throw std::out_of_range("Hex number out of int16_t range");
    }

    return static_cast<int16_t>(val);
}

void process_label(const std::string& name,driver& drv) {
    if (name.empty()) {
        std::cerr << "Error: Empty label name\n";
        exit(1);
    }
    bool is_definition = (name.back() == ':');
    
    std::string normalized_name = name;
    if (is_definition) {
        normalized_name.pop_back();
        
      
        if (normalized_name.empty()) {
            std::cerr << "Error: Label definition cannot be just ':'\n";
            exit(1);
        }
    }

    if (is_definition) {
        if (drv.symbol_table.count(normalized_name)) {
            if (drv.symbol_table[normalized_name].is_defined) {
                std::cerr << "Error: Duplicate label '" << normalized_name << "'\n";
                exit(1);
            }
            drv.symbol_table[normalized_name].value = ilc;
            drv.symbol_table[normalized_name].is_defined = true;
            
        } else {
            drv.symbol_table[normalized_name] = {ilc, true, {}};
        }
    } 
    else {
        if (!drv.symbol_table.count(normalized_name)) {
            drv.symbol_table[normalized_name] = {0, false, {}};
        }
        drv.symbol_table[normalized_name].refs.push_back(ilc);
    }
}

void print_symbol_table(driver& drv) {
    std::cout << "\nSymbol Table (decimal format):\n";
    std::cout << "+-----------------+---------+---------+---------------------+\n";
    std::cout << "| Label           | Address | Defined | References          |\n";
    std::cout << "+-----------------+---------+---------+---------------------+\n";
    
    for (const auto& [name, info] : drv.symbol_table) {
        std::cout << "| " << std::left << std::setw(15) << name << " | ";
        std::cout << std::setw(7) << info.value << " | ";
        std::cout << std::setw(7) << (info.is_defined ? "Yes" : "No") << " | ";

        if (info.refs.empty()) {
            std::cout << "None               |";
        } else {
            std::string refs_str;
            for (size_t i = 0; i < info.refs.size(); ++i) {
                if (i > 0) refs_str += ", ";
                refs_str += std::to_string(info.refs[i]);
                if (i == 3 && info.refs.size() > 4) {
                    refs_str += ", ...";
                    break;
                }
            }
            std::cout << std::setw(19) << refs_str << " |";
        }
        
        std::cout << "\n";
    }
    
    std::cout << "+-----------------+---------+---------+---------------------+\n";
    std::cout << "Total symbols: " << drv.symbol_table.size() << "\n\n";
}