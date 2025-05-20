#ifndef INSTRUCTION_SET_HH
#define INSTRUCTION_SET_HH

#include <cstdint>
#include <string>
#include <vector>

#include "structure.hh"

typedef struct Instructin_set_instr {
    std::string mnemonic;
    uint16_t opcode;
    std::vector<AddressingTypes> src_operands;
    std::vector<AddressingTypes> dest_operands;
    bool has_two_op;
} Instructin_set_instr;

class InstructionSet {
   public:
    InstructionSet();
    Instructin_set_instr findInstruction(const std::string& mnemonic) const;

   private:
    static std::vector<AddressingTypes> unar_op;
    static std::vector<AddressingTypes> binary_op_src;
    static std::vector<AddressingTypes> binary_op_dst;
    static std::vector<AddressingTypes> arythmetic_op_src;
    static std::vector<AddressingTypes> jmp_op;

    static std::vector<Instructin_set_instr> initialize_instr_set();
    std::vector<Instructin_set_instr> instruction_set;
};

#endif  // INSTRUCTION_SET_HH