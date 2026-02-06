#include <iostream>
#include <memory>
#include "CsvHandler.h"
#include "JsonHandler.h"
#include "Length.h"
#include "Time.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename> [column_index] [from_unit] [to_unit] [quantity_type]\n";
        return 1;
    }
    
    std::string filename = argv[1];
    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    
    // Factory pattern untuk file handler
    std::unique_ptr<FileHandler> fileHandler;
    
    if (extension == "csv") {
        fileHandler = std::make_unique<CsvHandler>();
    } else if (extension == "json") {
        fileHandler = std::make_unique<JsonHandler>();
    } else {
        std::cerr << "Unsupported file format: " << extension << std::endl;
        return 1;
    }
    
    // Baca file
    if (!fileHandler->readFile(filename)) {
        return 1;
    }
    
    return 0;
}