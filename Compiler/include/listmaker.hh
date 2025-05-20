#ifndef LISTMAKER_HH
#define LISTMAKER_HH

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>

#include "structure.hh"

class ListMaker {
   public:
    ListMaker();
    const char* addressingTypeToString(AddressingTypes type);
    void print_symbol_table(
        std::map<std::string, LabelInfo> symbol_table) const;
    void add_to_listing(const std::string& line, uint16_t ilc,
                        const std::string& comment = " ");
    void print_listing_to_file(const std::string& filename) const;
    void print_listing() const;

   private:
    std::map<std::uint16_t, std::vector<std::pair<std::string, std::string>>>
        listing;
};

#endif  // LISTMAKER_HH