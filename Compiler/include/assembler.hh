#ifndef ASSEMBLER_HH
#define ASSEMBLER_HH
#include <bitset>
#include <cstdint>
#include <fstream>
#include <map>
#include <unordered_map>

#include "binary_writer.hh"
#include "instruction_set.hh"
#include "listmaker.hh"
#include "program_storage.hh"
#include "structure.hh"
#include "validator.hh"

class BinaryFileWriter;

class Assembler {
   public:
    Assembler(const ProgramStorage& storage) : storage(storage) {}

    void generate_machine_code(const std::vector<Instruction>& program);
    uint16_t encode_opcode(const std::string&);
    uint16_t encode_operand(Operand, uint16_t, int&, bool,
                            std::vector<uint16_t>&, uint16_t);

   private:
    const ProgramStorage& storage;
    static constexpr uint16_t DATA_SEGMENT_START = 01000;
    static constexpr uint16_t CODE_SEGMENT_START = 02000;
    std::vector<uint8_t> generate_program_code(
        const std::vector<Instruction>& program, uint16_t start_address);
    bool has_two_op = false;
    InstructionSet instruction_set;
    Validator validator;
    ListMaker list_maker;
};

#endif  // ! ASSEMBLER_HH