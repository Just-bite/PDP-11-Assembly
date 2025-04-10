%skeleton "lalr1.cc"
%define api.parser.class {conj_parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define parse.error verbose
%locations

%code requires{
#include <iostream>
#include <cstdint>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

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


void yyerror(const char* s);

struct Operand {
    uint16_t value;
    int16_t displacement = 0;
    AddressingTypes type = AddressingTypes::REG;
    uint8_t token_flags = NONE;

    Operand() : value(0), displacement(0), type(REG), token_flags(NONE) {};
    Operand(uint16_t val, AddressingTypes t, int16_t disp = 0) 
        : value(val),displacement(disp), type(t)  {};
};

struct Instruction {
    std::string mnemonic;
    std::vector<Operand> operands;
    uint16_t address;
    uint8_t size;
};

struct Symbol {
    uint16_t address;
    bool is_label;
    std::string name;
};

std::map<std::string, Symbol> symbol_table;
std::vector<Instruction> program;
uint16_t pl = 0;  // Program counter
uint8_t current_addressing_flags = NONE;

// Output files
std::ofstream sym_table_file("symbol_table.txt");
std::ofstream code_file("generated_code.bin");

void process_label(const std::string& name) {
    if (symbol_table.count(name)) {
        std::cerr << "Error: Duplicate label '" << name << "'\n";
        exit(1);
    }
    symbol_table[name] = {pl, true, name};
    sym_table_file << name << ": " << pl << "\n";
}

AddressingTypes determine_addressing_type() {
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
}

void add_instruction(const std::string& mnemonic, 
                    const std::vector<Operand>& operands) {
    Instruction instr;
    instr.mnemonic = mnemonic;
    instr.operands = operands;
    instr.address = pl;
    
    // Calculate instruction size
    uint8_t size = 2;  // Base instruction size
    for (const auto& op : operands) {
        if (op.type == IMMEDIATE || op.type == ABSOLUTE || 
            op.type == INDEXED || op.type == INDEXED_INDIRECT) {
            size += 2;
        }
    }
    instr.size = size;
    pl += size;
    
    program.push_back(instr);
    
    // Write to code file
    code_file << "[" << std::hex << instr.address << "] " 
              << mnemonic << " (size: " << (int)size << ")\n";
}

} //code requires


%token<int> HEX_NUM OCT_NUM DEC_NUM
%token<std::string> NUMSIGN AT MINUS PLUS
%token<std::string> LPAREN RPAREN
%token<std::string> COMMA NEWLINE
%token<std::string> COMMENT LABEL
%token<std::string> DIRECTIVE 
%token<Operand>     REGISTER
%token<std::string> INSTRUCTION BRANCH

%type<int> number
%type<Operand> adressingS adressingD notreg  postreg prereg prelp

%code {
    extern FILE* yyin; 
}
%%

input:
    | input line
;

line: 
    expr NEWLINE
    | expr COMMENT
;

expr:
    INSTRUCTION adressingS COMMA adressingD { 
        add_instruction($1, {$2, $4}); 
        current_addressing_flags = NONE;
    }
    | INSTRUCTION adressingD { 
        add_instruction($1, {$2}); 
        current_addressing_flags = NONE;
    }
    | INSTRUCTION { 
        add_instruction($1, {}); 
    }
    | LABEL expr { 
        process_label($1); 
    }
    | BRANCH LABEL { 
        add_instruction($1, {Operand(0, RELATIVE)}); 
    }
    | DIRECTIVE number { 
        // Handle assembler directives 
    }
;

number:
    HEX_NUM     { $$ = $1; }
    | OCT_NUM   { $$ = $1; }
    | DEC_NUM   { $$ = $1; }
;

adressingS: 
    REGISTER    { $$ = $1; }
    | prereg REGISTER postreg { 
        $$ = Operand($2.value, determine_addressing_type(), $1.displacement); 
    }
    | notreg    { $$ = $1; }
;

adressingD: 
    REGISTER    { $$ = $1; }
    | prereg REGISTER postreg { 
        $$ = Operand($2.value, determine_addressing_type(), $1.displacement); 
    }
;

notreg:
    NUMSIGN number { 
        current_addressing_flags |= HASH|NUM;
        $$ = Operand($2, IMMEDIATE); 
    }
    | AT NUMSIGN number { 
        current_addressing_flags |= AT_F|HASH|NUM;
        $$ = Operand($3, ABSOLUTE); 
    }
;

prereg:
    LPAREN { 
        current_addressing_flags |= LPAR; 
    }
    | prelp LPAREN { 
        current_addressing_flags |= LPAR;
        $$ = $1; 
    }
;

prelp:
    AT { 
        current_addressing_flags |= AT_F; 
    }
    | MINUS { 
        current_addressing_flags |= MIN; 
    }
    | number { 
        current_addressing_flags |= NUM;
        $$.displacement = $1; 
    }
;

postreg:
    RPAREN { 
        current_addressing_flags |= RPAR; 
    }
    | RPAREN PLUS { 
        current_addressing_flags |= RPAR|PLS; 
    }
;

%%