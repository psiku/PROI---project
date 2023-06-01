//
// Created by Wiktor Kruszewicz on 01/06/2023.
//

#ifndef SHEEPSKIN_REVERSEMAPPER_H
#define SHEEPSKIN_REVERSEMAPPER_H
#include <string>
#include <vector>
#include "../../../Estimation/Estimation.h"

class ReverseMapper {
public:
    ReverseMapper() = default;
    std::string mapEstimationToRow(Estimation est);
    std::string join(std::vector<std::string> words, std::string sep);
    template <class T>
    std::string translate(T val);
};


#endif //SHEEPSKIN_REVERSEMAPPER_H
