
#include "mediator.hh"

#include "parser.tab.hh"

Mediator::Mediator() : trace_parsing(false), trace_scanning(false) {}

int Mediator::parse(const std::string& f, Validator valid, ListMaker list) {
    file = f;
    location.initialize(&file);
    scan_begin();
    yy::parser parse(*this, valid, list);
    parse.set_debug_level(trace_parsing);
    int res = parse();
    scan_end();
    return res;
}