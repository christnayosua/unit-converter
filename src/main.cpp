#include "Converter.h"
#include "Length.h"

#include <iostream>
#include <string>

int main(){
    std::string input;
    std::cout << "Enter value in km: ";
    
    std::cin >> input;
    double val = std::stod(input);

    Length myconverter;
    double baseVal = myconverter.toBase(val, "km");
    double result = myconverter.fromBase(baseVal, "ft");

    std::cout << "Value in ft : " << result << std::endl;


    return 0;
}