// define global variable
#ifndef TIME_H
#define TIME_H

// Import modul
#include "Converter.h"
#include <string>

// Time Converter
class Time : public Converter{
    public:
    // Constructor
    Time();

    // Override method from Converter
    double convert(double value, const std::string& fromUnit,
    const std::string& toUnit) override;

    // Base unit -> Seconds
    double toBase(double value, const std::string& fromUnit);
    double fromBase(double value, const std::string& toUnit);

    // Validation
    bool isValid(const std::string& unit) override;

    // Get Unit
    std::string getQuantityName() override;
}

#endif 