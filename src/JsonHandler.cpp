#include "JsonHandler.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

bool JsonHandler::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return false;
    }
    
    try {
        file >> jsonData;
        
        // Asumsikan struktur: array of objects atau object dengan array
        if (jsonData.is_array() && !jsonData.empty()) {
            // Ambil keys dari object pertama sebagai headers
            if (jsonData[0].is_object()) {
                for (auto& [key, value] : jsonData[0].items()) {
                    headers.push_back(key);
                }
            }
        }
        
        return true;
    } catch (const std::exception& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return false;
    }
}

bool JsonHandler::writeFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot create file: " << filename << std::endl;
        return false;
    }
    
    file << jsonData.dump(4);  // Pretty print dengan indent 4
    return true;
}

std::vector<double> JsonHandler::getColumnData(const std::string& columnName) {
    std::vector<double> result;
    
    if (!jsonData.is_array()) return result;
    
    for (const auto& item : jsonData) {
        if (item.contains(columnName) && item[columnName].is_number()) {
            result.push_back(item[columnName].get<double>());
        }
    }
    
    return result;
}

std::vector<double> JsonHandler::getColumnData(int columnIndex) {
    if (columnIndex < 0 || columnIndex >= headers.size()) {
        throw std::out_of_range("Invalid column index");
    }
    return getColumnData(headers[columnIndex]);
}

void JsonHandler::setColumnData(const std::string& columnName, const std::vector<double>& data) {
    if (!jsonData.is_array()) return;
    
    for (size_t i = 0; i < jsonData.size() && i < data.size(); ++i) {
        jsonData[i][columnName] = data[i];
    }
}

void JsonHandler::setColumnData(int columnIndex, const std::vector<double>& data) {
    if (columnIndex < 0 || columnIndex >= headers.size()) {
        throw std::out_of_range("Invalid column index");
    }
    setColumnData(headers[columnIndex], data);
}

std::vector<std::string> JsonHandler::getHeaders() {
    return headers;
}

bool JsonHandler::isValid() const {
    return !jsonData.is_null();
}

int JsonHandler::getColumnCount() const {
    return headers.size();
}