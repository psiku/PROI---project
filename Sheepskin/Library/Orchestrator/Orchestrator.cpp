//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Orchestrator.h"
#include "../Evaluator/Evaluator.h"
#include "../Data/CSVReader/CSVReader/CSVReader.h"
#include "../Data/CSVReader/Mapper/Mapper.h"
#include "../Data/CSVWriter/CSVWriter/CSVWriter.h"

void Orchestrator::setup(std::string filename) {
    // TODO
    CSVReader reader;
    CSVResult result = reader.read(filename);
    Mapper mapper;
    auto instruments = mapper.mapToInstruments(result);
    Orchestrator::instruments = instruments;
    std::cout << instruments.size();
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
    CSVWriter<Estimation> writer(std::move(filename), getEstimations());
    std::cout << "Am here";

    writer.write();
}



