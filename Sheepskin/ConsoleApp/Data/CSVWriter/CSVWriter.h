//
// Created by Grzegorz Statkiewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_CSVWRITER_H
#define SHEEPSKIN_CSVWRITER_H

#include <string>
#include <vector>
#include "Strategies/StrategyResult/StrategyResult.h"

class CSVWriter {
private:
    std::string filename;
    std::vector<StrategyResult> decisions;
public:
    CSVWriter(std::string filename);
    void write();
};


#endif //SHEEPSKIN_CSVWRITER_H
