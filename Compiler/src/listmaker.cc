#include "listmaker.hh"

ListMaker::ListMaker() {};

const char* ListMaker::addressingTypeToString(AddressingTypes type) {
    switch (type) {
        case REG:
            return "REG";
        case REG_INDIRECT:
            return "REG_INDIRECT";
        case AUTO_INCREMENT:
            return "AUTO_INCREMENT";
        case AUTO_INCREMENT_INDIRECT:
            return "AUTO_INCREMENT_INDIRECT";
        case AUTO_DECREMENT:
            return "AUTO_DECREMENT";
        case AUTO_DECREMENT_INDIRECT:
            return "AUTO_DECREMENT_INDIRECT";
        case INDEXED:
            return "INDEXED";
        case INDEXED_INDIRECT:
            return "INDEXED_INDIRECT";
        case IMMEDIATE:
            return "IMMEDIATE";
        case ABSOLUTE:
            return "ABSOLUTE";
        case RELATIVE:
            return "RELATIVE";
        default:
            return "UNKNOWN";
    }
}

void ListMaker::print_symbol_table(
    std::map<std::string, LabelInfo> symbol_table) const {
    std::ofstream out_file("symbol_table.lst");
    if (!out_file.is_open()) {
        std::cerr << "Error: Could not create symbol_table.txt file"
                  << std::endl;
        return;
    }

    auto dual_print = [&](const std::string& content) {
        std::cout << content;
        out_file << content;
    };

    dual_print("\nSymbol Table (octal format):\n");
    dual_print(
        "+-----------------+-----------+---------+---------------------+\n");
    dual_print(
        "| Label           | Address   | Defined | References          |\n");
    dual_print(
        "+-----------------+-----------+---------+---------------------+\n");

    for (const auto& [name, info] : symbol_table) {
        std::ostringstream line;
        line << "| " << std::left << std::setw(15) << name << " | "
             << std::setw(9) << std::oct << info.value << " | " << std::setw(7)
             << (info.is_defined ? "Yes" : "No") << " | ";

        if (info.refs.empty()) {
            line << "None               |";
        } else {
            std::ostringstream refs_stream;
            for (size_t i = 0; i < info.refs.size(); ++i) {
                if (i > 0) refs_stream << ", ";
                refs_stream << std::oct << info.refs[i];
                if (i == 3 && info.refs.size() > 4) {
                    refs_stream << ", ...";
                    break;
                }
            }
            std::string refs_str = refs_stream.str();
            line << std::setw(19) << refs_str << " |";
        }

        dual_print(line.str() + "\n");
        line << std::dec;
    }

    dual_print(
        "+-----------------+-----------+---------+---------------------+\n");
    dual_print("Total symbols: " + std::to_string(symbol_table.size()) +
               "\n\n");

    out_file.close();
    std::cout << "Symbol table saved to symbol_table.lst" << std::endl;
}

void ListMaker::add_to_listing(const std::string& line, uint16_t ilc,
                               const std::string& comment) {
    listing[ilc].push_back({line, comment});
}

void ListMaker::print_listing_to_file(const std::string& filename) const {
    std::ofstream out_file(filename);
    if (!out_file.is_open()) {
        throw std::runtime_error("Cannot open file for listing: " + filename);
    }

    const int INSTR_WIDTH = 40;
    const int LC_WIDTH = 10;
    const int MAX_LINE_WIDTH = INSTR_WIDTH - 2;

    out_file << std::left << std::setw(INSTR_WIDTH) << "Instructions"
             << std::right << "LC" << std::endl;
    out_file << std::setfill('-') << std::setw(INSTR_WIDTH + LC_WIDTH) << ""
             << std::setfill(' ') << std::endl;

    for (const auto& entry : listing) {
        uint16_t ilc = entry.first;
        const auto& lines_comments = entry.second;

        for (const auto& line_comment : lines_comments) {
            const std::string& line = line_comment.first;
            const std::string& comment = line_comment.second;

            std::string base_line = line;
            bool first_line = true;

            if (!comment.empty() && comment != " ") {
                std::string full_comment = comment;
                size_t pos = 0;

                while (pos < full_comment.size()) {
                    if (first_line) {
                        std::string display_line = base_line;
                        int available_space =
                            MAX_LINE_WIDTH - base_line.length();

                        if (available_space > 0) {
                            display_line +=
                                full_comment.substr(pos, available_space);
                            pos += available_space;
                        }

                        out_file << std::left << std::setw(INSTR_WIDTH)
                                 << display_line << std::right
                                 << std::setw(LC_WIDTH) << std::oct
                                 << std::uppercase << ilc << std::endl;
                        first_line = false;
                    } else {
                        std::string comment_line =
                            "  " + full_comment.substr(pos, MAX_LINE_WIDTH);
                        pos += MAX_LINE_WIDTH;

                        out_file << std::left << std::setw(INSTR_WIDTH)
                                 << comment_line << std::right
                                 << std::setw(LC_WIDTH) << "" << std::endl;
                    }
                }
            } else {
                out_file << std::left << std::setw(INSTR_WIDTH) << base_line
                         << std::right << std::setw(LC_WIDTH) << std::oct
                         << std::uppercase << ilc << std::endl;
            }
        }
    }

    out_file.close();
}

void ListMaker::print_listing() const {
    std::cout << "=== Listing ===" << std::endl;
    for (const auto& entry : listing) {
        uint16_t ilc = entry.first;
        const auto& lines_comments = entry.second;

        for (const auto& line_comment : lines_comments) {
            std::cout << "[" << std::oct << std::uppercase << ilc << "] "
                      << line_comment.first;

            if (!line_comment.second.empty() && line_comment.second != " ") {
                std::cout << " ;" << line_comment.second;
            }

            std::cout << std::endl;
        }
    }
    std::cout << "===============" << std::endl;
}