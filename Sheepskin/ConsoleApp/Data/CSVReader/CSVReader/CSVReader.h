//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CSVREADER_H
#define SHEEPSKIN_CSVREADER_H

#include <string>
#include <fstream>
#include "../../../../Library/Data/Instrument/Instrument/Instrument.h"
#include "../CSVResult/CSVResult.h"

template <class ...Types>
class CSVReader {
private:
    std::ifstream file;
    std::vector<std::vector<std::string>> values;
    std::vector<std::string> split(std::string line);
public:
    CSVReader() = default;
    CSVResult read(std::string filepath);
//    CSVResult<Types...> getMapped() {
//        using CSVRow = std::tuple<Types...>;
//        std::vector<CSVRow> vals(values[0].size());
//        CSVResult<Types...> res;
//        int column_iterator = 0;
//        ([&]{
//            std::vector<Types> translated = Mapper<Types>(values[column_iterator]).translate();
//            for(Types u:translated)
//                std::cout << u << " ";
//            std::cout << '\n';
//            column_iterator++;
//        }(), ...);
//        return CSVResult(vals);
//    };
};


#include "CSVReader.cpp"
#endif //SHEEPSKIN_CSVREADER_H
