#ifndef BINARY_WRITER_HH
#define BINARY_WRITER_HH
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "structure.hh"

class BinaryFileWriter {
   public:
    static bool write(const std::vector<uint8_t>& data,
                      const std::string& filename);
};

#endif  // BINARY_WRITER_HH