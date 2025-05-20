#include "program.hh"

void Program::process_label(const std::string& name, bool is_directive,
                            int16_t dir_val) {
    if (name.empty()) {
        std::cerr << "Error: Empty label name\n";
        exit(1);
    }

    bool is_definition;
    if (!is_directive) {
        is_definition = (name.back() == ':');
    } else {
        is_definition = true;
    }

    std::string normalized_name = name;
    if (is_definition && !is_directive) {
        normalized_name.pop_back();
        if (normalized_name.empty()) {
            std::cerr << "Error: Label definition cannot be just ':'\n";
            exit(1);
        }
    }

    if (is_definition) {
        if (storage.get_symbol_table().count(normalized_name)) {
            LabelInfo& symbol = storage.get_label_infor(normalized_name);

            if (is_directive && !dir_val) {
                std::cerr << "Error: Redefinition of .equ symbol '"
                          << normalized_name << "'\n";
                exit(1);
            }

            if (symbol.is_defined && dir_val) {
                std::cerr << "Error: Duplicate label '" << normalized_name
                          << "'\n";
                exit(1);
            }

            if (is_directive) {
                symbol.value = dir_val;
                symbol.is_defined = true;
                symbol.is_directive = true;
            } else {
                symbol.value = ilc;
                symbol.is_defined = true;
            }
        } else {
            if (is_directive) {
                storage.add_label(normalized_name, {dir_val, true, true, {}});
            } else {
                storage.add_label(normalized_name, {ilc, true, false, {}});
            }
        }
    } else {
        if (!storage.get_symbol_table().count(normalized_name)) {
            storage.add_label(normalized_name, {0, false, false, {}});
        }
        storage.get_label_infor(normalized_name).refs.push_back(ilc);
    }
}

void Program::add_instruction(const std::string& mnemonic,
                              const std::vector<Operand>& operands) {
    Instruction instr;
    instr.mnemonic = mnemonic;
    instr.operands = operands;
    instr.adress = ilc;
    instr.size = calculate_instr_size(operands);
    ilc += instr.size;
    program.push_back(instr);
}

int Program::calculate_instr_size(const std::vector<Operand>& operands) {
    int size = 2;
    for (const auto& op : operands) {
        if (op.type == ABSOLUTE || op.type == IMMEDIATE)
            size += 2;
        else
            continue;
    }
    return size;
}

void Program::setILC(uint16_t ilc_to_set) { ilc = ilc_to_set; }

int16_t Program::getILC() const { return ilc; }

void Program::addILC(uint16_t ilc_inc) { ilc += ilc_inc; }

std::map<std::string, LabelInfo> Program::get_symbol_table() const {
    return storage.get_symbol_table();
}

std::map<uint16_t, uint8_t> Program::get_byte_table() const {
    return storage.get_byte_table();
}

std::map<uint16_t, uint16_t> Program::get_word_table() const {
    return storage.get_word_table();
}

std::vector<Instruction> Program::get_program() const { return program; }

void Program::set_byte_table(uint16_t lc, uint8_t val) {
    storage.add_byte(lc, val);
}
void Program::set_word_table(uint16_t lc, uint16_t val) {
    storage.add_word(lc, val);
}