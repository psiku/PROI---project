//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CSVREADER_H
#define SHEEPSKIN_CSVREADER_H

#include <string>
#include <fstream>
#include "Data/Instrument/Instrument/Instrument.h"
#include "../CSVResult/CSVResult.h"

template <class ...Types>
class CSVReader {
private:
    std::ifstream file;
    std::vector<std::vector<std::string>> values;
    std::vector<std::string> split(std::string line);
public:
    CSVReader() = default;
    void read(std::ifstream &file);
    CSVResult<Types...> getMapped() {
        std::cout << "Am hereeee";
        using CSVRow = std::tuple<Types...>;
        std::vector<CSVRow> vals;
        for(auto row:values) {
//            std::cout << "Am here";
//            Mapper mapper<Type(row);
//            mapper.translate<long double>();
            (Mapper<Types>(row), ...);
            //vals.emplace_back(r);
        }
        return CSVResult(vals);
    };
};


#include "CSVReader.cpp"
#endif //SHEEPSKIN_CSVREADER_H
