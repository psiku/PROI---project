//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_MAPPER_H
#define SHEEPSKIN_MAPPER_H

#include <string>
#include <vector>

template <class T>
class Mapper {
public:
//    Mapper();
    Mapper() = default;
    void addColumn(std::vector<std::string> column);
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


template <class T>
void Mapper<T>::addColumn(std::vector<std::string> column) {
    std::cout << "am here\n";
    this->column = column;
}

template <>
int Mapper<int>::translate(std::string val) {
    return std::stoi(val);
}

template <>
long double Mapper<long double>::translate(std::string val) {
    std::cout << val << " ";
    return std::stold(val);
}
template <>
time_t Mapper<time_t>::translate(std::string val) {
    struct std::tm tm;
    std::istringstream ss(val);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); // or just %T in this case
    std::time_t time = mktime(&tm);
    return time;
}

template<class T>
T Mapper<T>::translate(std::string val) {
    return val;
}

#endif //SHEEPSKIN_MAPPER_H
