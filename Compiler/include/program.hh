#ifndef PROGRAMM_HH
#define PROGRAMM_HH

#include <iostream>
#include <map>
#include <vector>

#include "program_storage.hh"
#include "structure.hh"

class Program {
   public:
    Program()
        : storage(std::map<std::string, LabelInfo>{},
                  std::map<uint16_t, uint8_t>{},
                  std::map<uint16_t, uint16_t>{}) {}
    void process_label(const std::string &name, bool is_directive,
                       int16_t dir_val);
    void add_instruction(const std::string &mnemonic,
                         const std::vector<Operand> &operands);

    void setILC(uint16_t ilc_to_set);
    void addILC(uint16_t ilc_inc = 1);
    int16_t getILC() const;

    std::map<std::string, LabelInfo> get_symbol_table() const;
    std::map<uint16_t, uint8_t> get_byte_table() const;
    std::map<uint16_t, uint16_t> get_word_table() const;
    std::vector<Instruction> get_program() const;

    void set_byte_table(uint16_t, uint8_t);
    void set_word_table(uint16_t, uint16_t);

   private:
    int16_t ilc = 0;
    std::vector<Instruction> program;
    ProgramStorage storage;
    int calculate_instr_size(const std::vector<Operand> &operands);
};

#endif  // PROGRAMM_HH