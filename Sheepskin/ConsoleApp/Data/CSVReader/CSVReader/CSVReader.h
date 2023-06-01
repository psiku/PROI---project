//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CSVREADER_H
#define SHEEPSKIN_CSVREADER_H

#include <string>
#include <vector>
#include "../CSVResult/CSVResult.h"

class CSVReader {
private:
//    std::ifstream file;
    std::vector<std::vector<std::string>> values;
    static std::vector<std::string> split(std::string line);
public:
    CSVReader();
    static CSVResult read(std::string filepath);
};


#endif //SHEEPSKIN_CSVREADER_H
