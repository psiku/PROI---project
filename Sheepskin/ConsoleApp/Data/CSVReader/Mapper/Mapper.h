//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_MAPPER_H
#define SHEEPSKIN_MAPPER_H

#include <string>
#include <vector>

template <class T>
class Mapper {
    std::vector<std::string> column;
public:
//    Mapper();
    Mapper(std::vector<std::string> column);
    void addColumn(std::vector<std::string> column);
    std::vector<T> translate();
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

template <class T>
Mapper<T>::Mapper(std::vector<std::string> column): column(column) {
//    std::cout << "Column: \n";
//    for(std::string s:column) {
//        std::cout << s << " ";
//    }
//    std::cout << '\n';
};

template <>
std::vector<int> Mapper<int>::translate() {
    std::cout << "int\n" << std::endl;
    std::vector<int> ans;
    for(std::string str:column) {
        ans.emplace_back(std::stoi(str)) ;
    }
    std::cout << ans[0];
    return ans;
}

template <>
std::vector<long double> Mapper<long double>::translate() {
    std::cout << "long double\n" << std::endl;
    std::vector<long double> ans;
    for(std::string str:column) {
        ans.emplace_back(std::stold(str)) ;
    }
    return ans;
}
template <>
std::vector<time_t> Mapper<time_t>::translate() {
    std::cout << "time_t\n" << std::endl;
    std::vector<time_t> ans;
    for(std::string str:column) {
        struct std::tm tm;
        std::istringstream ss(str);
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); // or just %T in this case
        std::time_t time = mktime(&tm);
        ans.emplace_back(time) ;
    }
    return ans;
}

template<class T>
std::vector<T> Mapper<T>::translate() {
    std::cout << "different\n" << std::endl;
    return column;
}

#endif //SHEEPSKIN_MAPPER_H
