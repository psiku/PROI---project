#include <iostream>
#include "Data/Record/Record.h"
#include "Data/Instrument/Stock/Stock.h"
#include "Strategies/FirstStrategy/FirstStrategy.h"
#include "Data/Instrument/Instrument/Instrument.h"
#include "Data/CSVReader/CSVReader/CSVReader.h"
#include "Strategies/Strategy/Strategy.h"
#include "Data/CSVReader/Mapper/Mapper.h"
#include "Orchestrator/Orchestrator.h"
#include "ExceptionHandler/ExceptionHandler.h"

int main() {
    try {
        Orchestrator orchestrator;
        //orchestrator.setup("Data/example.csv");
        orchestrator.setup("../../Data/example.csv");
        orchestrator.run();
        //orchestrator.save("Results/example.csv");
        orchestrator.save("../../Results/example.csv");
    } catch(std::exception &e) {
        ExceptionHandler::handle(e);
    }

    return 0;
}
