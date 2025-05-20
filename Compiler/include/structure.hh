#ifndef STRUCTURE_HH
#define STRUCTURE_HH

#include <cstdint>
#include <string>
#include <vector>

enum AddressingTypes : uint8_t {
    REG = 0b00000000,
    REG_INDIRECT = 0b00110000,
    AUTO_INCREMENT = 0b01110000,
    AUTO_INCREMENT_INDIRECT = 0b01110001,
    AUTO_DECREMENT = 0b00110100,
    AUTO_DECREMENT_INDIRECT = 0b00110101,
    INDEXED = 0b00111000,
    INDEXED_INDIRECT = 0b00111001,
    IMMEDIATE = 0b00000101,
    ABSOLUTE = 0b00001011,
    RELATIVE = 0b10000000,
    ERROR = 0b11111111,
};

enum TokenFlags : uint8_t {
    NONE = 0b00000000,
    AT_F = 0b00000001,  // @
    HASH = 0b00000010,  // #
    MIN = 0b00000100,   // -
    NUM = 0b00001000,   // numbers
    LPAR = 0b00010000,  // (
    RPAR = 0b00100000,  // )
    PLS = 0b01000000,   // +
};

struct Operand {
    uint16_t value;
    int16_t offset = 0;
    AddressingTypes type = AddressingTypes::REG;
    uint8_t token_flags = NONE;
    std::string label_name;
    std::string string_form;

    Operand()
        : value(0),
          offset(0),
          type(REG),
          token_flags(NONE),
          label_name(),
          string_form() {};
    Operand(uint16_t val, AddressingTypes t, std::string string_form,
            int16_t disp = 0, std::string lable_name = "not_label")
        : value(val),
          string_form(string_form),
          offset(disp),
          type(t),
          label_name(lable_name) {};
};

struct Instruction {
    std::string mnemonic;
    std::vector<Operand> operands;
    uint16_t adress;
    uint8_t size;
};

struct LabelInfo {
    int16_t value;
    bool is_defined;
    bool is_directive;
    std::vector<uint16_t> refs;
};

#endif