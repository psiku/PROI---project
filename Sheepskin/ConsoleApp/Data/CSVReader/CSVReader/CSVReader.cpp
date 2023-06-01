//
// Created by barte on 11.05.2023.
//
#include <fstream>
#include <string>
#include <vector>
#include "../CSVResult/CSVResult.h"
#include "CSVReader.h"



CSVReader::CSVReader() {}

CSVResult CSVReader::read(std::string filepath) {
    std::ifstream file;
    file.open(filepath);

    std::string line;
    std::string header = line;
    std::getline(file, header);

    std::vector<std::vector<std::string>> columns(split(header).size());
    while(std::getline(file, line)) {
        for(int i = 0 ; i < split(line).size(); i++) {
              columns[i].emplace_back(split(line)[i]);
        }
    }
    return CSVResult(columns);
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

