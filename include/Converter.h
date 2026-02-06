#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>

class Converter {
public:
    virtual double toBase(double value, std::string unit) = 0;
    virtual double fromBase(double baseValue, std::string unit) = 0;
    virtual ~Converter() {} 
};

#endif