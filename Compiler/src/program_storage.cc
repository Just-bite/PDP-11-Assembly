#include "program_storage.hh"

#include <iostream>

void ProgramStorage::add_byte(uint16_t address, uint8_t value) {
    byte_table[address] = value;
}

bool ProgramStorage::has_byte_at(uint16_t address) const {
    return byte_table.count(address) > 0;
}

uint8_t ProgramStorage::get_byte(uint16_t address) const {
    return byte_table.at(address);
}

const std::map<uint16_t, uint8_t>& ProgramStorage::get_byte_table() const {
    return byte_table;
}

void ProgramStorage::add_word(uint16_t address, uint16_t value) {
    word_table[address] = value;
}

bool ProgramStorage::has_word_at(uint16_t address) const {
    return word_table.count(address) > 0;
}

uint16_t ProgramStorage::get_word(uint16_t address) const {
    return word_table.at(address);
}

const std::map<uint16_t, uint16_t>& ProgramStorage::get_word_table() const {
    return word_table;
}

void ProgramStorage::add_label(const std::string& name, const LabelInfo& info) {
    symbol_table[name] = info;
}

bool ProgramStorage::has_label(const std::string& name) const {
    return symbol_table.count(name) > 0;
}

LabelInfo& ProgramStorage::get_label_infor(const std::string& name) {
    return symbol_table.at(name);
}

LabelInfo ProgramStorage::get_label_info(const std::string& name) const {
    static const LabelInfo NOT_FOUND{0, false, false, {}};
    auto it = symbol_table.find(name);
    return (it != symbol_table.end()) ? it->second : NOT_FOUND;
}

uint16_t ProgramStorage::get_label_address(const std::string& name) const {
    return symbol_table.at(name).value;
}

const std::map<std::string, LabelInfo>& ProgramStorage::get_symbol_table()
    const {
    return symbol_table;
}

std::vector<uint8_t> ProgramStorage::generate_data_segment(
    uint16_t start_address) const {
    std::vector<uint8_t> data;
    uint16_t current_address = start_address;

    while (has_byte_at(current_address)) {
        data.push_back(get_byte(current_address));
        current_address += 1;
    }

    while (has_word_at(current_address)) {
        uint16_t word = get_word(current_address);
        data.push_back(word & 0xFF);
        data.push_back((word >> 8) & 0xFF);
        current_address += 2;
    }

    return data;
}

std::vector<uint8_t> ProgramStorage::generate_code_segment(
    uint16_t start_address) const {
    std::vector<uint8_t> code;
    uint16_t current_address = start_address;

    while (true) {
        if (has_byte_at(current_address)) {
            std::cout << "BYTE" << std::endl;
            code.push_back(get_byte(current_address));
            current_address += 1;
        } else if (has_word_at(current_address)) {
            std::cout << "WORD" << std::endl;
            uint16_t word = get_word(current_address);
            code.push_back(word & 0xFF);
            code.push_back((word >> 8) & 0xFF);
            current_address += 2;
        } else {
            break;
        }
    }

    return code;
}
