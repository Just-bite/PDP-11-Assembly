
#include <iostream>
#include <vector>

#include "assembler.hh"
#include "mediator.hh"

int main(int argc, char* argv[]) {
    int res = 0;
    Mediator m;
    Validator valid;
    ListMaker list;
    for (int i = 1; i < argc; ++i)
        if (argv[i] == std::string("-p"))
            m.trace_parsing = true;
        else if (argv[i] == std::string("-s"))
            m.trace_scanning = true;
        else if (argv[i] == std::string("-l"))
            m.create_listing = true;
        else if (!m.parse(argv[i], valid, list))
            std::cout << "ok" << '\n';
        else
            res = 1;
    ProgramStorage prog(m.program().get_symbol_table(),
                        m.program().get_byte_table(),
                        m.program().get_word_table());
    Assembler asmblr(prog);
    asmblr.generate_machine_code(m.program().get_program());
    return res;
}
