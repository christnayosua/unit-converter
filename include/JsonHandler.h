#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include "FileHandler.h"
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class JsonHandler : public FileHandler {
private:
    json jsonData;
    std::vector<std::string> headers;
    
public:
    bool readFile(const std::string& filename) override;
    bool writeFile(const std::string& filename) override;
    
    // Dapatkan data pada kolom tertentu
    std::vector<double> getColumnData(const std::string& columnName);
    std::vector<double> getColumnData(int columnIndex);
    
    // Set data pada kolom tertentu
    void setColumnData(const std::string& columnName, const std::vector<double>& data);
    void setColumnData(int columnIndex, const std::vector<double>& data);
    
    // Dapatkan daftar kolom
    std::vector<std::string> getHeaders();
    
    // Cek apakah file valid
    bool isValid() const;
    
    int getColumnCount() const;
};

#endif // JSONHANDLER_H