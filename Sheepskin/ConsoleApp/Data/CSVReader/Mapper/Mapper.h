//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_MAPPER_H
#define SHEEPSKIN_MAPPER_H

#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>
#include "../../../../Library/Data/Instrument/Instrument/Instrument.h"
#include "../CSVResult/CSVResult.h"

class Mapper {
public:
//    Mapper();
//    Mapper() = default;
    std::vector<Instrument*> mapToInstruments(CSVResult);
    template <class T>
    T translate(std::string val);
};
template <>
int Mapper::translate<int>(std::string val) {
    return std::stoi(val);
}

template <>
long double Mapper::translate<long double>(std::string val) {
    return std::stold(val);
}

template <>
double Mapper::translate<double>(std::string val) {
    return std::stod(val);
}

template <>
time_t Mapper::translate<time_t>(std::string val) {
    struct std::tm tm;
    std::istringstream ss(val);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); // or just %T in this case
    std::time_t time = mktime(&tm);
    return time;
}

template<>
std::string Mapper::translate<std::string>(std::string val) {
    return val;
}
#endif //SHEEPSKIN_MAPPER_H
