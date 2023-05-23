//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CSVREADER_H
#define SHEEPSKIN_CSVREADER_H

#include <string>
#include "Data/Instrument/Instrument/Instrument.h"
#include "../CSVResult/CSVResult.h"

template <class ...Types>
class CSVReader {
private:
    std::string filename;
    std::vector<std::vector<std::string>> values;
public:
    explicit CSVReader(std::string filename);
    void read();
    CSVResult<Types...> getMapped();
};


#endif //SHEEPSKIN_CSVREADER_H
