//
// Created by barte on 11.05.2023.
//

#include <string>

#include "CSVReader.h"

template <class ...Types>
CSVReader<Types...>::CSVReader(std::string filename): filename(filename) {};

template <class ...Types>
void CSVReader<Types...>::read() {

}

template <class ...Types>
CSVResult<Types...> getMapped() {

}