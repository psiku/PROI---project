//
// Created by Grzegorz Statkiewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_CSVWRITER_H
#define SHEEPSKIN_CSVWRITER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include "CSVWriter.h"
#include "../../../Estimation/Estimation.h"
#include "../ReverseMapper/ReverseMapper.h"

template <class T>
class CSVWriter {
private:
    std::string filename;
    std::vector<T> decisions;
public:
    CSVWriter(std::string filename, std::vector<T> decisions);
    void write();
};


template <class T>
CSVWriter<T>::CSVWriter(std::string filename, std::vector<T> decisions): filename(std::move(filename)), decisions(decisions) {};

template <class T>
void CSVWriter<T>::write() {}

template <>
void CSVWriter<Estimation>::write() {
    ReverseMapper mapper;
    std::ofstream file;
    file.open(filename);

    std::vector<std::string> header = {"id", "type", "fall", "rise", "maint"};
    file << mapper.join(header, ",") << "\n";
    std::cout << mapper.join(header, ",") << "\n";
    for(Estimation decision:decisions) {
        file << mapper.mapEstimationToRow(decision) << "\n";
        std::cout << mapper.mapEstimationToRow(decision) << "\n";
    }
    file.close();
}

#endif //SHEEPSKIN_CSVWRITER_H
