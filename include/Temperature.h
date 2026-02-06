#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Converter.h"
#include <string>

class Temperature : public Converter {
public:
    double toBase(double value, std::string unit) override;
    double fromBase(double baseValue, std::string unit) override;
};

#endif
