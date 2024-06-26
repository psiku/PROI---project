//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_CSVRESULT_H
#define SHEEPSKIN_CSVRESULT_H

#include <utility>
#include <vector>
#include <unordered_map>
#include <string>

class CSVResult {
private:
    int index = 0;
    std::vector<std::vector<std::string>> data;
public:
    CSVResult() = default;
    explicit CSVResult(std::vector<std::vector<std::string>> data): data(std::move(data)) {};

    bool end();
    std::vector<std::string> getRow();
};

#endif //SHEEPSKIN_CSVRESULT_H
