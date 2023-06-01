//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Orchestrator.h"
#include "../Evaluator/Evaluator.h"
#include "../Data/CSVReader/CSVReader/CSVReader.h"
#include "../Data/CSVReader/Mapper/Mapper.h"

void Orchestrator::setup(std::string filename) {
    // TODO
    CSVReader reader;
    CSVResult result = reader.read(filename);
    Mapper mapper;
    std::vector<Instrument*> instruments = mapper.mapToInstruments(result);
    this->instruments = instruments;
}

void Orchestrator::run() {
    Evaluator evaluator;
    Context context;

    for(auto* instrument : instruments) {
        evaluator.handle(&context, instrument);
        Forecast forecast = context.run();
        estimations.emplace_back(*instrument, forecast);
    }
}

std::vector<Estimation> Orchestrator::getEstimations() {
    return std::vector<Estimation>(estimations);
}

void Orchestrator::save(std::string filename) {
    // TODO
}



