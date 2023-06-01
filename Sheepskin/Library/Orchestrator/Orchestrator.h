//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_ORCHESTRATOR_H
#define SHEEPSKIN_ORCHESTRATOR_H
#include "../Data/Instrument/Instrument/Instrument.h"
#include "../Estimation/Estimation.h"


class Orchestrator {
private:
    std::vector<Instrument*> instruments;
    std::vector<Estimation> estimations;

public:
    explicit Orchestrator() {}
    explicit Orchestrator(std::vector<Instrument*> instruments) : instruments(instruments) {}

    void setup(std::string filename);
    void run();
    std::vector<Estimation> getEstimations();
    void save(std::string filename);
};


#endif //SHEEPSKIN_ORCHESTRATOR_H
