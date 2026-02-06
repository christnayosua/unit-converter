#include "Temperature.h"
#include <stdexcept>

double Temperature::toBase(double value, std::string unit) {
    // Convert to Celsius (base)
    if (unit == "C" || unit == "celsius") {
        return value;
    } 
    else if (unit == "F" || unit == "fahrenheit") {
        return (value - 32) * 5.0 / 9.0;
    } 
    else if (unit == "K" || unit == "kelvin") {
        return value - 273.15;
    } 
    else if (unit == "Re" || unit == "reamur") {
        return value * 5.0 / 4.0;
    } 
    else {
        throw std::invalid_argument("Invalid temperature unit: " + unit);
    }
}

double Temperature::fromBase(double baseValue, std::string unit) {
    // Convert from Celsius to target
    if (unit == "C" || unit == "celsius") {
        return baseValue;
    } 
    else if (unit == "F" || unit == "fahrenheit") {
        return (baseValue * 9.0 / 5.0) + 32;
    } 
    else if (unit == "K" || unit == "kelvin") {
        return baseValue + 273.15;
    } 
    else if (unit == "Re" || unit == "reamur") {
        return baseValue * 4.0 / 5.0;
    } 
    else {
        throw std::invalid_argument("Invalid temperature unit: " + unit);
    }
}
