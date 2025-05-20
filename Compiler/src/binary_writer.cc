#include "binary_writer.hh"

bool BinaryFileWriter::write(const std::vector<uint8_t>& data,
                             const std::string& filename) {
    std::ofstream outfile(filename, std::ios::binary);
    if (!outfile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename
                  << std::endl;
        return false;
    }

    outfile.write(reinterpret_cast<const char*>(data.data()), data.size());
    outfile.close();

    if (outfile.fail()) {
        std::cerr << "Ошибка записи в файл " << filename << std::endl;
        return false;
    }

    std::cout << "Успешно записано " << data.size() << " байт в " << filename
              << std::endl;
    return true;
}
