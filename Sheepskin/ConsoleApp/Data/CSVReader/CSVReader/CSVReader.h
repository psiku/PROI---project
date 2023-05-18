//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CSVREADER_H
#define SHEEPSKIN_CSVREADER_H

#include <string>
#include "Data/Instrument/Instrument/Instrument.h"
#include "../CSVResult/CSVResult.h"

class CSVReader {
private:
    std::string filename;
public:
    explicit CSVReader(std::string filename);
    CSVResult read();
};


#endif //SHEEPSKIN_CSVREADER_H
