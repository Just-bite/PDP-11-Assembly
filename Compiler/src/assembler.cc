#include "assembler.hh"

#include <algorithm>
#include <iostream>

void Assembler::generate_machine_code(const std::vector<Instruction>& program) {
    auto data = storage.generate_data_segment(DATA_SEGMENT_START);
    auto code = generate_program_code(program, CODE_SEGMENT_START);
    BinaryFileWriter::write(data, "data.bin");
    BinaryFileWriter::write(code, "code.bin");
}

std::vector<uint8_t> Assembler::generate_program_code(
    const std::vector<Instruction>& program, uint16_t start_address) {
    std::vector<uint8_t> output;
    std::vector<uint16_t> extra_words;
    uint16_t current_pc = start_address;
    int instr_length = 2;

    for (const auto& instr : program) {
        bool has_two_op = instr.operands.size() - 1;
        bool is_src = has_two_op;
        uint16_t opcode = encode_opcode(instr.mnemonic);
        Operand prev_op;
        validator.set_has_abs();

        for (const auto& operand : instr.operands) {
            bool is_valid = validator.validate_instruction_by_operands(
                instr, operand, is_src);
            if (is_valid) {
                opcode = encode_operand(operand, opcode, instr_length, is_src,
                                        extra_words, current_pc);
                is_src = false;
            } else {
                validator.display_instruction_adress_error(
                    instr.mnemonic, prev_op.string_form, operand.string_form,
                    list_maker.addressingTypeToString(prev_op.type),
                    list_maker.addressingTypeToString(operand.type));
            }
            prev_op = operand;
        }

        output.push_back(static_cast<uint8_t>(opcode & 0xFF));
        output.push_back(static_cast<uint8_t>((opcode >> 8) & 0xFF));

        for (const auto& word : extra_words) {
            output.push_back(word & 0xFF);
            output.push_back((word >> 8) & 0xFF);
        }

        current_pc += instr_length;
        extra_words.clear();
        instr_length = 2;
    }

    auto remaining_data = storage.generate_code_segment(current_pc);
    output.insert(output.end(), remaining_data.begin(), remaining_data.end());

    return output;
}

uint16_t Assembler::encode_opcode(const std::string& mnemonic) {
    Instructin_set_instr instr = instruction_set.findInstruction(mnemonic);
    has_two_op = instr.has_two_op;
    return instr.opcode;
}

uint16_t Assembler::encode_operand(Operand operand, uint16_t opcode,
                                   int& instr_length, bool is_source,
                                   std::vector<uint16_t>& extra_words,
                                   uint16_t current_pc) {
    uint16_t operand_to_code = 0;

    switch (operand.type) {
        case REG:
            operand_to_code = operand.value & 7;
            break;

        case REG_INDIRECT:
            operand_to_code = 010 | (operand.value & 7);
            break;

        case AUTO_INCREMENT:
            operand_to_code = 020 | (operand.value & 7);
            break;

        case AUTO_INCREMENT_INDIRECT:
            operand_to_code = 030 | (operand.value & 7);
            break;

        case AUTO_DECREMENT:
            operand_to_code = 040 | (operand.value & 7);
            break;

        case AUTO_DECREMENT_INDIRECT:
            operand_to_code = 050 | (operand.value & 7);
            break;

        case INDEXED:
            operand_to_code = 060 | (operand.value & 7);
            instr_length += 2;
            break;

        case INDEXED_INDIRECT:
            operand_to_code = 070 | (operand.value & 7);
            instr_length += 2;
            break;

        case IMMEDIATE:
            operand_to_code = 027;
            instr_length += 2;
            if (!storage.get_label_info(operand.label_name).is_directive) {
                extra_words.push_back(operand.offset);
            } else {
                extra_words.push_back(
                    storage.get_label_info(operand.label_name).value);
            }
            break;

        case ABSOLUTE: {
            operand_to_code = 037;
            uint16_t adress;
            if (operand.label_name == "TPS")
                adress = 0177564;
            else if (operand.label_name == "TPB")
                adress = 0177566;
            else if (operand.label_name == "not_label")
                adress = operand.offset;
            else {
                adress = storage.get_label_address(operand.label_name);
            }
            extra_words.push_back(adress);
            instr_length += 2;
            break;
        }

        case RELATIVE: {
            uint16_t offset;
            if (operand.label_name == "numof")
                offset = operand.offset;
            else {
                offset = storage.get_label_address(operand.label_name) -
                         (current_pc + 2);
                offset >>= 1;
            }
            offset &= 0x00FF;

            operand_to_code = offset;
            instr_length = 2;
            break;
        }

        default:
            std::cerr << "Неизвестный тип операнда!" << std::endl;
            break;
    }
    if (has_two_op && is_source) {
        operand_to_code <<= 6;
    }
    return opcode | operand_to_code;
}
