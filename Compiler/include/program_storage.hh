#ifndef PROGRAM_STORAGE_HH
#define PROGRAM_STORAGE_HH

#include <map>

#include "structure.hh"

class ProgramStorage {
   public:
    ProgramStorage(std::map<std::string, LabelInfo> symbol_table,
                   std::map<uint16_t, uint8_t> byte_table,
                   std::map<uint16_t, uint16_t> word_table)
        : symbol_table(symbol_table),
          byte_table(byte_table),
          word_table(word_table) {};

    void add_byte(uint16_t address, uint8_t value);

    bool has_byte_at(uint16_t address) const;

    uint8_t get_byte(uint16_t address) const;

    const std::map<uint16_t, uint8_t>& get_byte_table() const;

    void add_word(uint16_t address, uint16_t value);
    bool has_word_at(uint16_t address) const;

    uint16_t get_word(uint16_t address) const;

    const std::map<uint16_t, uint16_t>& get_word_table() const;

    void add_label(const std::string& name, const LabelInfo& info);

    bool has_label(const std::string& name) const;

    LabelInfo& get_label_infor(const std::string& name);
    LabelInfo get_label_info(const std::string& name) const;
    uint16_t get_label_address(const std::string& name) const;

    const std::map<std::string, LabelInfo>& get_symbol_table() const;

    std::vector<uint8_t> generate_data_segment(uint16_t start_address) const;
    std::vector<uint8_t> generate_code_segment(uint16_t start_address) const;

   private:
    std::map<std::string, LabelInfo> symbol_table;
    std::map<uint16_t, uint8_t> byte_table;
    std::map<uint16_t, uint16_t> word_table;
};
#endif  // PROGRAM_STORAGE_HH