#include "Data/Record/Record.h"
#include "Data/Instrument/Stock/Stock.h"
#include "Strategies/FirstStrategy/FirstStrategy.h"
#include "Orchestrator/Orchestrator.h"
#include "ExceptionHandler/ExceptionHandler.h"

int main(int argc, char* argv[]) {
    try {
        if(argc < 3) throw std::exception();

        Orchestrator orchestrator;
        orchestrator.setup(argv[1]);
        orchestrator.run();
        orchestrator.save(argv[2]);
    } catch(std::exception &e) {
        ExceptionHandler::handle(e);
    }

    return 0;
}