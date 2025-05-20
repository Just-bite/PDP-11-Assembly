#include "instruction_set.hh"

#include <stdexcept>
#include <vector>

std::vector<AddressingTypes> InstructionSet::unar_op = {REG,
                                                        REG_INDIRECT,
                                                        AUTO_INCREMENT,
                                                        AUTO_INCREMENT_INDIRECT,
                                                        AUTO_DECREMENT,
                                                        AUTO_DECREMENT_INDIRECT,
                                                        INDEXED,
                                                        INDEXED_INDIRECT,
                                                        ABSOLUTE};

std::vector<AddressingTypes> InstructionSet::binary_op_src = {
    REG,
    REG_INDIRECT,
    AUTO_INCREMENT,
    AUTO_INCREMENT_INDIRECT,
    AUTO_DECREMENT,
    AUTO_DECREMENT_INDIRECT,
    INDEXED,
    INDEXED_INDIRECT,
    IMMEDIATE,
    ABSOLUTE};

std::vector<AddressingTypes> InstructionSet::binary_op_dst = {
    REG, REG_INDIRECT, AUTO_INCREMENT, AUTO_DECREMENT, INDEXED, ABSOLUTE};

std::vector<AddressingTypes> InstructionSet::arythmetic_op_src = {
    REG, REG_INDIRECT, AUTO_INCREMENT, AUTO_DECREMENT, INDEXED};

std::vector<AddressingTypes> InstructionSet::jmp_op = {REG_INDIRECT,
                                                       AUTO_INCREMENT,
                                                       AUTO_INCREMENT_INDIRECT,
                                                       AUTO_DECREMENT,
                                                       AUTO_DECREMENT_INDIRECT,
                                                       INDEXED,
                                                       INDEXED_INDIRECT,
                                                       ABSOLUTE,
                                                       RELATIVE};

InstructionSet::InstructionSet() { instruction_set = initialize_instr_set(); }

std::vector<Instructin_set_instr> InstructionSet::initialize_instr_set() {
    return {// UNAR OPERAND INSTRUCTIONS
            {"CLR", 0x0A00, {}, unar_op, false},
            {"CLRB", 0x8A00, {}, unar_op, false},
            {"COM", 0x0A40, {}, unar_op, false},
            {"COMB", 0x8A40, {}, unar_op, false},
            {"INC", 0x0A80, {}, unar_op, false},
            {"INCB", 0x8A80, {}, unar_op, false},
            {"DEC", 0x0AC0, {}, unar_op, false},
            {"DECB", 0x8AC0, {}, unar_op, false},
            {"NEG", 0x0B00, {}, unar_op, false},
            {"NEGB", 0x8B00, {}, unar_op, false},
            {"TST", 0x0BC0, {}, unar_op, false},
            {"TSTB", 0x8BC0, {}, unar_op, false},
            {"ASR", 0x0C80, {}, unar_op, false},
            {"ASRB", 0x8C80, {}, unar_op, false},
            {"ASL", 0x0CC0, {}, unar_op, false},
            {"ASLB", 0x8CC0, {}, unar_op, false},
            {"ROR", 0x0C00, {}, unar_op, false},
            {"RORB", 0x8C00, {}, unar_op, false},
            {"ROL", 0x0C40, {}, unar_op, false},
            {"ROLB", 0x8C40, {}, unar_op, false},
            {"SWAB", 0x00C0, {}, unar_op, false},
            {"ADC", 0x0B40, {}, unar_op, false},
            {"ADCB", 0x8B40, {}, unar_op, false},
            {"SBC", 0x0B80, {}, unar_op, false},
            {"SBCB", 0x8B80, {}, unar_op, false},
            {"SXT", 0x0DC0, {}, unar_op, false},
            // DOUBLE OPERAND INSTRUCTIONS
            {"MOV", 0x1000, binary_op_src, binary_op_dst, true},
            {"MOVB", 0x9000, binary_op_src, binary_op_dst, true},
            {"CMP", 0x2000, binary_op_src, binary_op_dst, true},
            {"CMPB", 0xA000, binary_op_src, binary_op_dst, true},
            {"ADD", 0x6000, binary_op_src, binary_op_dst, true},
            {"SUB", 0xE000, binary_op_src, binary_op_dst, true},
            // LOGIC INSTRUTIONS
            {"BIT", 0x3000, binary_op_src, binary_op_dst, true},
            {"BITB", 0xB000, binary_op_src, binary_op_dst, true},
            {"BIC", 0x4000, binary_op_src, binary_op_dst, true},
            {"BICB", 0xC000, binary_op_src, binary_op_dst, true},
            {"BIS", 0x5000, binary_op_src, binary_op_dst, true},
            {"BISB", 0xD000, binary_op_src, binary_op_dst, true},
            {"MUL", 0x7000, arythmetic_op_src, {REG}, true},
            {"DIV", 0x7200, arythmetic_op_src, {REG}, true},
            {"ASH", 0x7400, arythmetic_op_src, {REG}, true},
            {"ASHC", 0x7600, arythmetic_op_src, {REG}, true},
            {"XOR", 0x7800, arythmetic_op_src, {REG}, true},
            // PROGRAMM CONTROL INSTRUCTIONS
            {"BR", 0x0100, {}, {RELATIVE}, false},
            {"BNE", 0x0200, {}, {RELATIVE}, false},
            {"BEQ", 0x0300, {}, {RELATIVE}, false},
            {"BPL", 0x8000, {}, {RELATIVE}, false},
            {"BMI", 0x8100, {}, {RELATIVE}, false},
            {"BVC", 0x8400, {}, {RELATIVE}, false},
            {"BVS", 0x8500, {}, {RELATIVE}, false},
            {"BCC", 0x8600, {}, {RELATIVE}, false},
            {"BCS", 0x8700, {}, {RELATIVE}, false},
            // SIGNED CONDITION BRANCHES
            {"BGE", 0x0400, {}, {RELATIVE}, false},
            {"BLT", 0x0500, {}, {RELATIVE}, false},
            {"BGT", 0x0600, {}, {RELATIVE}, false},
            {"BLE", 0x0700, {}, {RELATIVE}, false},
            // UNSIGNED BRANCH
            {"BHI", 0x8200, {}, {RELATIVE}, false},
            {"BLOS", 0x8300, {}, {RELATIVE}, false},
            {"BHIS", 0x8600, {}, {RELATIVE}, false},
            {"BLO", 0x8700, {}, {RELATIVE}, false},
            {"JMP", 0x0040, {}, jmp_op, false},
            // NO OPERAND INSTRUCTIONS
            {"HALT", 0x0000, {}, {}, false},
            {"WAIT", 0x0001, {}, {}, false},
            {"RTI", 0x0002, {}, {}, false},
            {"BPT", 0x0003, {}, {}, false},
            {"IOT", 0x0004, {}, {}, false},
            {"RESET", 0x0005, {}, {}, false},
            {"RTT", 0x0006, {}, {}, false},
            // SUBROUTINE
            {"JSR", 0x0800, {}, {}, false},
            {"RTS", 0x0080, {}, {}, false},
            {"MARK", 0x0D00, {}, {}, false},
            {"SOB", 0x7E00, {}, {RELATIVE}, false},
            // MEMORY MANAGEMENT
            {"MFPI", 0x0D40, jmp_op, {}, false},
            {"MTPI", 0x00D0, {}, jmp_op, false},
            // FLAG HANDLING
            {"CLC", 0x00A1, {}, {}, false},
            {"CLV", 0x00A2, {}, {}, false},
            {"CLZ", 0x00A4, {}, {}, false},
            {"CLN", 0x00A8, {}, {}, false},
            {"CCC", 0x00AF, {}, {}, false},
            {"SEC", 0x00B1, {}, {}, false},
            {"SEV", 0x00B2, {}, {}, false},
            {"SEZ", 0x00B4, {}, {}, false},
            {"SEN", 0x00B8, {}, {}, false},
            {"SCC", 0x00BF, {}, {}, false}};
}

Instructin_set_instr InstructionSet::findInstruction(
    const std::string& mnemonic) const {
    for (const auto& instr : instruction_set) {
        if (instr.mnemonic == mnemonic) {
            return instr;
        }
    }
    throw std::runtime_error("Instruction not found: " + mnemonic);
}