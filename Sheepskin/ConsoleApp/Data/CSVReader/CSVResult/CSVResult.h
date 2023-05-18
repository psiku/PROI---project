//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_CSVRESULT_H
#define SHEEPSKIN_CSVRESULT_H

#include <vector>
#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, std::string> row;

class CSVResult {
private:
    int index = 0;
    std::vector<row> data;
public:
    explicit CSVResult(std::vector<row> data);
    row readline();
};


#endif //SHEEPSKIN_CSVRESULT_H
