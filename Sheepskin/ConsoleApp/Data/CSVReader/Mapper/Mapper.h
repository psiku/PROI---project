//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_MAPPER_H
#define SHEEPSKIN_MAPPER_H

#include <string>
#include <vector>
#include <map>

class Mapper {
public:
//    Mapper();
    Mapper() = default;
    std::vector<Instrument*> map(CSVResult);
    template <class T>
    T translate(std::string val);
};
//#include "Mapper.cpp"
//
// Created by Wiktor Kruszewicz on 18/05/2023.
//
#include <iostream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
//#include "Mapper.h"

template <>
int Mapper::translate<int>(std::string val) {
    return std::stoi(val);
}

template <>
long double Mapper::translate<long double>(std::string val) {
    std::cout << val << " ";
    return std::stold(val);
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

std::vector<Instrument*> map(CSVResult) {
    std::map<std::string, Instrument*> instruments;

    
}

#endif //SHEEPSKIN_MAPPER_H
