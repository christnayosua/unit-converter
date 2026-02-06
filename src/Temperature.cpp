#include "Temperature.h"

Temperature::Temperature(double value, Unit from) 
    : value(value), currentUnit(from) {}

double Temperature::convertTo(Unit to) {
    if (currentUnit == to) return value;
    
    // Convert to Celsius first (base unit)
    double celsius = toCelsius(value, currentUnit);
    
    // Convert from Celsius to target
    return fromCelsius(celsius, to);
}

double Temperature::toCelsius(double val, Unit from) {
    switch(from) {
        case CELSIUS: return val;
        case FAHRENHEIT: return (val - 32) * 5.0/9.0;
        case KELVIN: return val - 273.15;
        case REAMUR: return val * 5.0/4.0;
        default: return val;
    }
}

double Temperature::fromCelsius(double celsius, Unit to) {
    switch(to) {
        case CELSIUS: return celsius;
        case FAHRENHEIT: return (celsius * 9.0/5.0) + 32;
        case KELVIN: return celsius + 273.15;
        case REAMUR: return celsius * 4.0/5.0;
        default: return celsius;
    }
}

std::string Temperature::getUnitString(Unit unit) {
    switch(unit) {
        case CELSIUS: return "°C";
        case FAHRENHEIT: return "°F";
        case KELVIN: return "K";
        case REAMUR: return "°Ré";
        default: return "";
    }
}