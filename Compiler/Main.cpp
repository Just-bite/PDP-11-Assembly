#include <iostream>
#include <fstream>
#include "parser.tab.hh"

extern FILE* yyin;
extern int yyparse();
extern std::map<std::string, Symbol> symbol_table;
extern std::vector<Instruction> program;

void print_symbol_table() {
    std::cout << "\nSymbol Table:\n";
    std::cout << "-------------\n";
    for (const auto& [name, symbol] : symbol_table) {
        std::cout << name << ":\t" << std::hex << symbol.address << "\n";
    }
}

void print_generated_code() {
    std::cout << "\nGenerated Code:\n";
    std::cout << "---------------\n";
    for (const auto& instr : program) {
        std::cout << "[" << std::hex << instr.address << "] " 
                  << instr.mnemonic << "\t";
        
        for (const auto& op : instr.operands) {
            switch (op.type) {
                case AddressingTypes::REG:
                    std::cout << "R" << op.value << " ";
                    break;
                case AddressingTypes::IMMEDIATE:
                    std::cout << "#" << op.value << " ";
                    break;
                case AddressingTypes::REG_INDIRECT:
                    std::cout << "(R" << op.value << ") ";
                    break;
                case AddressingTypes::AUTO_INCREMENT:
                    std::cout << "(R" << op.value << ")+ ";
                    break;
                case AddressingTypes::INDEXED:
                    std::cout << op.displacement << "(R" << op.value << ") ";
                    break;
                default:
                    std::cout << "[unknown] ";
            }
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input.asm>\n";
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Error: Cannot open file " << argv[1] << "\n";
        return 1;
    }
    yy::conj_parser parser;


    std::cout << "Assembling " << argv[1] << "...\n";
    int result = parser.parse();
    fclose(yyin);
    if(result){
        std::cout<<"parsing failed..";
        exit(-1);
    }

    print_symbol_table();
    print_generated_code();


    std::ofstream sym_file("symbol_table.txt");
    for (const auto& [name, symbol] : symbol_table) {
        sym_file << name << ":\t" << std::hex << symbol.address << "\n";
    }
    sym_file.close();

    std::ofstream code_file("generated_code.bin", std::ios::binary);
    for (const auto& instr : program) {
        
        // temporary:
        code_file << instr.mnemonic << " at " << std::hex << instr.address << "\n";
    }
    code_file.close();

    std::cout << "\nAssembly complete. Results saved to:\n"
              << "- symbol_table.txt\n"
              << "- generated_code.bin\n";

    return 0;
}