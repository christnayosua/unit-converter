#ifndef LENGTH_H
#define LENGTH_H

#include "Converter.h"

#include <iostream>
#include <string>
#include <map>

class Length : public Converter {
private:
    std::map<std::string, double> multipliers;

public:
    Length();

    double toBase(double value, std::string unit) override;

    double fromBase(double baseValue, std::string targetUnit) override;
};

#endif