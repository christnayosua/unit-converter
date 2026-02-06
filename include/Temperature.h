#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Converter.h"

class Temperature : public Converter {
public:
    // Base unit: Celsius
    enum Unit {
        CELSIUS,
        FAHRENHEIT,
        KELVIN,
        REAMUR
    };

    Temperature(double value, Unit from);
    double convertTo(Unit to) override;
    std::string getUnitString(Unit unit);

private:
    double value;
    Unit currentUnit;
    
    // Conversion formulas to Celsius (base)
    double toCelsius(double val, Unit from);
    double fromCelsius(double celsius, Unit to);
};

#endif