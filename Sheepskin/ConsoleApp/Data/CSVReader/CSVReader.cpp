//
// Created by barte on 11.05.2023.
//

#include <string>
#include <vector>

#include "CSVReader.h"

template <class T>
CSVReader<T>::CSVReader(std::string filename): filename(filename) {};

template <class T>
std::vector<T> CSVReader<T>::read() {}