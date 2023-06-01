//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_MAPPER_H
#define SHEEPSKIN_MAPPER_H

#include <string>
#include <vector>
#include <map>
#include "../../Instrument/Instrument/Instrument.h"
#include "../../CSVReader/CSVResult/CSVResult.h"

class Mapper {
public:
//    Mapper();
    Mapper() = default;
    std::vector<Instrument*> mapToInstruments(CSVResult);
    template <class T>
    T translate(std::string val);
};

#endif //SHEEPSKIN_MAPPER_H
