//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CSVREADER_H
#define SHEEPSKIN_CSVREADER_H

#include <string>
#include "Data/Instrument/Instrument.h"

template <class T>
class CSVReader {
private:
    std::string filename;
public:
    CSVReader(std::string filename);
    std::vector<Instrument> read();
};


#endif //SHEEPSKIN_CSVREADER_H
