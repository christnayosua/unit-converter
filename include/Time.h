#ifndef TIME_H
#define TIME_H

#include "Converter.h"
#include <string>

class Time : public Converter {
public:
    Time();

    double toBase(double value, std::string unit) override;
    double fromBase(double baseValue, std::string unit) override;
};

#endif
