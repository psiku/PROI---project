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
        using CSVRow = std::tuple<Types...>;
        std::vector<CSVRow> vals(values[0].size());
        CSVResult res;
        int row_iterator = 0;
        ([&]{
            std::vector<Types> translated = Mapper<Types>(values[row_iterator]).translate();
            row_iterator++;
        }(), ...);
        return CSVResult(vals);
    };
};


#include "CSVReader.cpp"
#endif //SHEEPSKIN_CSVREADER_H
