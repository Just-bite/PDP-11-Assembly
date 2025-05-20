#ifndef MEDIATOR_HH
#define MEDIATOR_HH
#include <map>
#include <string>

#include "listmaker.hh"
#include "parser.tab.hh"
#include "program.hh"
#include "validator.hh"

#define YY_DECL                                                  \
    yy::parser::symbol_type yylex(Mediator &m, Validator &valid, \
                                  ListMaker &list)
YY_DECL;

class Mediator {
   public:
    Mediator();

    int parse(const std::string &f, Validator valid, ListMaker list);

    void scan_begin();
    void scan_end();

    Program &program() { return program_master; }

    bool trace_parsing;
    bool trace_scanning;
    bool create_listing;
    yy::location location;

    std::string file;

   private:
    Program program_master;
};
#endif  // ! MEDIATOR_HH
