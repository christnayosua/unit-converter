#include "Converter.h"
#include "Length.h"
#include "Temperature.h"
#include "Time.h"

#include "FileHandler.h"
#include "CsvHandler.h"

#include <iostream>
#include <string>
#include <vector>

FileHandler* getFileHandler(std::string filename) {
    if (filename.find(".csv") != std::string::npos) {
        return new CsvHandler();
    } else {
        std::cerr << "File format is not supported!\n";
        return nullptr;
    }
}

Converter* getConverter(const std::string& quantity) {
    if (quantity == "length") {
        return new Length();
    } 
    else if (quantity == "temperature") {
        return new Temperature();
    } 
    else if (quantity == "time") {
        return new Time();
    } 
    else {
        return nullptr;
    }
}

int main() {
    std::string filename;
    std::cout << "Enter file location: ";
    std::cin >> filename;

    FileHandler* fileHandler = getFileHandler(filename);
    if (fileHandler == nullptr) return -1;

    if (!fileHandler->load(filename)) {
        std::cerr << "Failed to load file! Exiting.\n";
        delete fileHandler;
        return -1;
    }

    std::string selector;
    std::cout << "Enter Column Index: ";
    std::cin >> selector;

    std::string quantity;
    std::cout << "Enter quantity (length / temperature / time): ";
    std::cin >> quantity;

    std::string unitOrigin;
    std::string unitTarget;

    std::cout << "Enter original unit: ";
    std::cin >> unitOrigin;

    std::cout << "Enter target unit: ";
    std::cin >> unitTarget;

    Converter* converter = getConverter(quantity);
    if (converter == nullptr) {
        std::cerr << "Invalid quantity type!\n";
        delete fileHandler;
        return -1;
    }

    std::vector<std::string> originalCol = fileHandler->getColumn(selector);
    std::vector<std::string> resultCol;

    for (const auto& raw : originalCol) {
        try {
            double inputVal = std::stod(raw);
            double baseVal = converter->toBase(inputVal, unitOrigin);
            double result = converter->fromBase(baseVal, unitTarget);
            resultCol.push_back(std::to_string(result));
        }
        catch (...) {
            resultCol.push_back("Error");
        }
    }

    std::string newHeader = unitTarget + "_converted";
    fileHandler->appendColumn(newHeader, resultCol);

    // Handle filename and its path
    std::size_t indexSeperator = filename.find_last_of("/") + 1;
    std::string dir = filename.substr(0, indexSeperator);
    std::string file = filename.substr(indexSeperator);

    std::string outputFile = dir + "converted_" + file;
    fileHandler->save(outputFile);
    std::cout << "Success! Saved to " << outputFile << "\n";

    delete converter;
    delete fileHandler;

    return 0;
}
