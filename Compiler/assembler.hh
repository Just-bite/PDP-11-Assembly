#ifndef ASSEMBLER_HH
#define ASSEMBLER_HH
#include <cstdint>
#include <unordered_map>

class assembler {
   public:
    assembler();
    void write_to_file();
    std::vector<uint8_t> generate_machine_code(
        // const std::vector<Instruction>&,
        /*const std::map<std::string, LabelInfo>&*/);
    uint8_t encode_opcpde(const std::string&);
};

/*std::vector<uint8_t> assembler::generate_machine_code(
    const std::vector<Instruction>& program,
    const std::map<std::string, LabelInfo>& symbol_table) {
    std::vector<uint8_t> output;

    for (const auto& instr : program) {
        uint8_t opcode = encode_opcode(instr.mnemonic);
        output.push_back(opcode);

        for (const auto& operand : instr.operands) {
            encode_operand(operand, output, symbol_table);
        }
    }

    return output;
}*/

#endif  // ! DRIVER_HH