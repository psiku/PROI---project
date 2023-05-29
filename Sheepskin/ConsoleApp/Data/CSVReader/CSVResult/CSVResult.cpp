//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#include "CSVResult.h"
#include "../Mapper/Mapper.h"
//#include "Data/Record/Record.h"

#include <utility>
#include <sstream>
#include <iomanip>

//template <class ...Types>
//CSVResult<Types...>::CSVResult(std::vector<std::tuple<Types...>> data): data(data) {};

template <class ...Types>
std::tuple<Types...> CSVResult<Types...>::readline() {
//    if(index != data.size())
        return data[index++];

}

//template <class ...Types>
//T CSVResult<T>::map_to_obj() {
//    std::vector<Record> records;
//    for(auto row:data) {
//        std::vector<std::string> temp;
//        for(auto & it : row) {
//            temp.emplace_back(it.second);
//        }
//        std::reverse(temp.begin(), temp.end());
//
//        struct std::tm tm;
//        std::istringstream ss(temp[0]);
//        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); // or just %T in this case
//        std::time_t time = mktime(&tm);
//
//        records.emplace_back(time, std::stold(temp[1]), std::stoi(temp[2]));
//    }
//    T obj("");
//    obj.addRecord(records);
//    return obj;
//}
//
