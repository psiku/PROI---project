//
// Created by Grzegorz Statkiewicz on 05/05/2023.
//

#include "Orchestrator/Orchestrator.h"

int main() {
    Orchestrator orchestrator;

    orchestrator.setup("./Data/example.csv");
    orchestrator.run();
    orchestrator.save("./Results/example.csv");

    return 0;
}
