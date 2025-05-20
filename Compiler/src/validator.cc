#include "validator.hh"

#include <iostream>

#include "listmaker.hh"
#include "structure.hh"

void Validator::display_instruction_adress_error(
    const std::string& mnemonic, const std::string& src, const std::string& dst,
    const std::string& src_adr_t, const std::string& dst_adr_t) const {
    std::cout << "incorrect adressing type in instruction " << mnemonic << " "
              << src << " " << dst << std::endl
              << "operand types are: " << src_adr_t << " and " << dst_adr_t
              << std::endl;
}

bool Validator::has_absolute_or_immediate = false;

AddressingTypes Validator::determine_adressing_type() {
    switch (current_addressing_flags) {
        case HASH | NUM:
            return IMMEDIATE;
        case AT_F | HASH | NUM:
            return ABSOLUTE;
        case LPAR | RPAR:
            return REG_INDIRECT;
        case LPAR | RPAR | PLS:
            return AUTO_INCREMENT;
        case AT_F | LPAR | RPAR | PLS:
            return AUTO_INCREMENT_INDIRECT;
        case MIN | LPAR | RPAR:
            return AUTO_DECREMENT;
        case AT_F | MIN | LPAR | RPAR:
            return AUTO_DECREMENT_INDIRECT;
        case NUM | LPAR | RPAR:
            return INDEXED;
        case AT_F | NUM | LPAR | RPAR:
            return INDEXED_INDIRECT;
        default:
            return ERROR;
    }
    return ERROR;
}

void Validator::display_error_message(const std::string& error) const {
    std::cerr << error << std::endl;
}

bool Validator::validate_instruction_by_operands(Instruction instr,
                                                 Operand operand, bool is_src) {
    if (operand.string_form == "TPB" || operand.string_form == "TPS") {
        return true;
    }

    if (!is_src && operand.type == IMMEDIATE) {
        return instr.mnemonic == "CMP";
    }

    if (has_absolute_or_immediate &&
        (operand.type == ABSOLUTE || operand.type == IMMEDIATE)) {
        return false;
    }

    const auto& instr_info = instruction_set.findInstruction(instr.mnemonic);
    const auto& allowed_types =
        is_src ? instr_info.src_operands : instr_info.dest_operands;

    if (!allowed_types.empty()) {
        bool type_valid = std::find(allowed_types.begin(), allowed_types.end(),
                                    operand.type) != allowed_types.end();

        if (type_valid &&
            (operand.type == ABSOLUTE || operand.type == IMMEDIATE)) {
            has_absolute_or_immediate = true;
        }
        return type_valid;
    }

    has_absolute_or_immediate = false;
    return false;
}

void Validator::set_has_abs() { has_absolute_or_immediate = false; }