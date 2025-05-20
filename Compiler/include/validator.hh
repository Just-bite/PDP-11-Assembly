#ifndef VALIDATOR_HH
#define VALIDATOR_HH
#include <algorithm>
#include <string>

#include "instruction_set.hh"
#include "structure.hh"

class Validator {
   public:
    Validator() : instruction_set(InstructionSet()) {};
    void display_instruction_adress_error(const std::string&,
                                          const std::string&,
                                          const std::string&,
                                          const std::string&,
                                          const std::string&) const;
    void display_error_message(const std::string& error) const;

    bool validate_instruction_by_operands(Instruction instr, Operand operand,
                                          bool is_src);

    AddressingTypes determine_adressing_type();
    void set_has_abs();
    uint8_t current_addressing_flags = NONE;

   private:
    static bool has_absolute_or_immediate;
    InstructionSet instruction_set;
};

#endif  // VALIDATOR_HH