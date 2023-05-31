//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//
#include <gtest/gtest.h>
#include "Orchestrator/Orchestrator.h"
#include "Data/Instrument/Stock/Stock.h"

TEST(OrchestratorTests, RunTest) {
    Stock instrument("123");
    instrument.addRecord(Record(1685566304296, 3,3,3,3,1));
    instrument.addRecord(Record(1685566318954, 2,2,2,2,1));
    instrument.addRecord(Record(1685566326207, 3,3,3,3,1));

    Orchestrator orchestrator({ &instrument });

    orchestrator.run();
    auto estimations = orchestrator.getEstimations();

    ASSERT_EQ(estimations.size(), 1);

    for(auto& estimation : estimations) {
        ASSERT_GT(estimation.getForecast().getFallChance(), 0);
        ASSERT_GT(estimation.getForecast().getMaintanceChance(), 0);
        ASSERT_GT(estimation.getForecast().getRiseChance(), 0);
    }
}