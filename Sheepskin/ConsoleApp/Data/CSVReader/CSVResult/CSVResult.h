//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_CSVRESULT_H
#define SHEEPSKIN_CSVRESULT_H

#include <vector>
#include <unordered_map>
#include <string>

template <class ...Types>
class CSVResult {
private:
    int index = 0;
    std::vector<std::tuple<Types...>> data;
public:
    CSVResult() = default;
    explicit CSVResult(std::vector<std::tuple<Types...>> data): data(data) {};
    std::tuple<Types...> readline();
};

#include "CSVResult.cpp"

#endif //SHEEPSKIN_CSVRESULT_H
