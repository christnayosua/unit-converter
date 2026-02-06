#include "Time.h"
#include <stdexcept>

Time::Time() {}

double Time::toBase(double value, const std::string& fromUnit) {
    // Konversi ke detik (base unit)
    if (fromUnit == "s" || fromUnit == "second" || fromUnit == "seconds") {
        return value;
    } else if (fromUnit == "ms" || fromUnit == "millisecond" || fromUnit == "milliseconds") {
        return value / 1000.0;
    } else if (fromUnit == "ns" || fromUnit == "nanosecond" || fromUnit == "nanoseconds") {
        return value / 1e9;
    } else if (fromUnit == "min" || fromUnit == "minute" || fromUnit == "minutes") {
        return value * 60.0;
    } else if (fromUnit == "h" || fromUnit == "hour" || fromUnit == "hours") {
        return value * 3600.0;
    } else {
        throw std::invalid_argument("Invalid time unit: " + fromUnit);
    }
}

double Time::fromBase(double value, const std::string& toUnit) {
    // Konversi dari detik ke unit target
    if (toUnit == "s" || toUnit == "second" || toUnit == "seconds") {
        return value;
    } else if (toUnit == "ms" || toUnit == "millisecond" || toUnit == "milliseconds") {
        return value * 1000.0;
    } else if (toUnit == "ns" || toUnit == "nanosecond" || toUnit == "nanoseconds") {
        return value * 1e9;
    } else if (toUnit == "min" || toUnit == "minute" || toUnit == "minutes") {
        return value / 60.0;
    } else if (toUnit == "h" || toUnit == "hour" || toUnit == "hours") {
        return value / 3600.0;
    } else {
        throw std::invalid_argument("Invalid time unit: " + toUnit);
    }
}

double Time::convert(double value, const std::string& fromUnit, const std::string& toUnit) {
    double baseValue = toBase(value, fromUnit);
    return fromBase(baseValue, toUnit);
}

bool Time::isValidUnit(const std::string& unit) {
    return (unit == "s" || unit == "second" || unit == "seconds" ||
            unit == "ms" || unit == "millisecond" || unit == "milliseconds" ||
            unit == "ns" || unit == "nanosecond" || unit == "nanoseconds" ||
            unit == "min" || unit == "minute" || unit == "minutes" ||
            unit == "h" || unit == "hour" || unit == "hours");
}

std::string Time::getQuantityName() {
    return "Time";
}