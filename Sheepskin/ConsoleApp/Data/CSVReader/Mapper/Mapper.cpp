////
//// Created by Wiktor Kruszewicz on 18/05/2023.
////
//#include <iostream>
//#include <sstream>
//#include <iomanip>
//#include <utility>
//#include <string>
//#include <vector>
//#include "Mapper.h"
//
//
//template <class T>
//void Mapper<T>::addColumn(std::vector<std::string> column) {
//    this->column = column;
//}
//
//template <class T>
//Mapper<T>::Mapper(std::vector<std::string> column): column(column) {};
//
//template <>
//std::vector<int> Mapper<int>::translate() {
//    std::vector<int> ans;
//    for(std::string str:column) {
//        ans.emplace_back(std::stoi(str)) ;
//    }
//    std::cout << ans[0];
//    return ans;
//}
//
//template <>
//std::vector<long double> Mapper<long double>::translate() {
//    std::cout << "Am here\n";
//    std::vector<long double> ans;
//    for(std::string str:column) {
//        ans.emplace_back(std::stold(str)) ;
//    }
//    return ans;
//}
//template <>
//std::vector<time_t> Mapper<time_t>::translate() {
//    std::vector<time_t> ans;
//    for(std::string str:column) {
//        struct std::tm tm;
//        std::istringstream ss(str);
//        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); // or just %T in this case
//        std::time_t time = mktime(&tm);
//        ans.emplace_back(time) ;
//    }
//    return ans;
//}