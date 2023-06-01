//
// Created by Wiktor Kruszewicz on 01/06/2023.
//

#include "ReverseMapper.h"
#include "../../../Estimation/Estimation.h"
#include <string>
#include <vector>

template <>
std::string ReverseMapper::translate(double val) {
    return std::to_string(val);
}
std::string ReverseMapper::join(std::vector<std::string> words, std::string sep) {
    std::string ans;

    for(int i = 0 ; i < words.size()-1 ; i++) {
        ans += words[i];
        ans += sep;
    }
    ans += words[words.size()-1];

    return ans;
}
std::string ReverseMapper::mapEstimationToRow(Estimation est) {
    auto instrument= est.getInstrument();
    auto forecast = est.getForecast();
    std::string id = instrument.getId();
    std::string type = instrument.getType();
    std::string fall = translate<double>(forecast.getFallChance());
    std::string rise = translate<double>(forecast.getRiseChance());
    std::string maint = translate<double>(forecast.getMaintanceChance());

    std::vector<std::string> words = {id, type, fall, rise, maint};
    return join(words, ",");
}

template<class T>
std::string ReverseMapper::translate(T val) {
    return std::to_string(val);
}
