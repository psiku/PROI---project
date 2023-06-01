//
// Created by barte on 11.05.2023.
//

#include <string>
#include <iostream>
#include <fstream>

#include "CSVReader.h"

//template <class ...Types>
//CSVReader<Types...>::CSVReader(std::string filename): filename(filename) {};
#include "../../../Exceptions/InvalidFormatException.h"

CSVResult CSVReader::read(std::string filepath) {
    std::ifstream file;
    file.open(filepath);

    std::string line;
    std::string header = line;
    std::getline(file, header);

    std::vector<std::vector<std::string>> columns(split(header).size());
    while(std::getline(file, line)) {
        if(split(line).size() != split(header).size()) {
            throw InvalidFormatException();
        }
        for(int i = 0 ; i < split(line).size(); i++) {
              columns[i].emplace_back(split(line)[i]);
        }
    }
    return CSVResult(columns);
//    return result;
}

std::vector<std::string> CSVReader::split(std::string line) {
    std::vector <std::string> ans;

    std::string curr_val;
    for(char chr: line) {
        if(chr == ',') {
            ans.emplace_back(curr_val);
            curr_val = "";
        }
        else {
            curr_val += chr;
        }
    }
    ans.emplace_back(curr_val);
    return ans;
}

//template <class ...Types>
//CSVResult<Types...> CSVReader<Types...>::getMapped() {
////    return CSVResult<Types...>();
//    using CSVRow = std::tuple<Types...>;
//    std::vector<CSVRow> vals;
//    for(auto row:values) {
//        Mapper mapper(row);
//        (mapper.translate<Types>(), ...);
//        //vals.emplace_back(r);
//    }
//    //return CSVResult(vals);
//}