#ifndef DRIVER_HH
#define DRIVER_HH
#include <map>
#include <string>

#include "parser.tab.hh"

#define YY_DECL yy::parser::symbol_type yylex(driver &drv)
YY_DECL;

class driver {
   public:
    driver();

    std::map<std::string, int> variables;

    int parse(const std::string &f);
    std::string file;

    void scan_begin();
    void scan_end();

    bool trace_parsing;
    bool trace_scanning;
    yy::location location;

    std::vector<Instruction> program;
    std::map<std::string, LabelInfo> symbol_table;
};
#endif  // ! DRIVER_HH
