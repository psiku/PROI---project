//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#include "Instrument.h"

#include <utility>

Instrument::Instrument(std::string id): id(std::move(id)) {}

void Instrument::addRecord(const Record& record) {
    records.push_back(record);
}