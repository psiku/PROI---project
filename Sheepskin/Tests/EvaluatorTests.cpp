//
// Created by Grzegorz Statkiewicz on 01/06/2023.
//

#include <gtest/gtest.h>
#include "Data/Instrument/Instrument/Instrument.h"
#include "Evaluator/Evaluator.h"

TEST(EvaluatorTests, GetTimestampsTest) {
    Instrument instrument("abc");
    instrument.addRecord({100, 0, 0, 0, 0, 0});
    instrument.addRecord({200, 0, 0, 0, 0, 0});
    instrument.addRecord({300, 0, 0, 0, 0, 0});
    instrument.addRecord({300, 0, 0, 0, 0, 0});

    std::vector<long> timestamps = Evaluator::getTimestamps(&instrument);

    ASSERT_EQ(timestamps.size(), 3);

    ASSERT_EQ(timestamps[0], 100);
    ASSERT_EQ(timestamps[1], 100);
    ASSERT_EQ(timestamps[2], 0);
}

TEST(EvaluatorTests, GetTimestampMedianTest) {
    Instrument instrument("abc");
    instrument.addRecord({100, 0, 0, 0, 0, 0});
    instrument.addRecord({150, 0, 0, 0, 0, 0});
    instrument.addRecord({200, 0, 0, 0, 0, 0});
    instrument.addRecord({250, 0, 0, 0, 0, 0});

    long median = Evaluator::getTimestampMedian(&instrument);

    ASSERT_EQ(median, 50);
}

TEST(EvaluatorTests, ChoseFirstStrategyTest) {
    Instrument instrument("abc");
    instrument.addRecord({60*60*22, 0, 0, 0, 0, 0});
    instrument.addRecord({60*60*24, 0, 0, 0, 0, 0});

    StrategyType type = Evaluator::chose(&instrument);

    ASSERT_EQ(type, StrategyType::First);
}

TEST(EvaluatorTests, ChoseSecondStrategyTest) {
    Instrument instrument("abc");
    instrument.addRecord({60*60*24*2, 0, 0, 0, 0, 0});
    instrument.addRecord({60*60*24*7, 0, 0, 0, 0, 0});

    StrategyType type = Evaluator::chose(&instrument);

    ASSERT_EQ(type, StrategyType::Second);
}

TEST(EvaluatorTests, ChoseThirdStrategyTest) {
    Instrument instrument("abc");
    instrument.addRecord({60*60*24*7*2, 0, 0, 0, 0, 0});
    instrument.addRecord({60*60*24*7*10, 0, 0, 0, 0, 0});

    StrategyType type = Evaluator::chose(&instrument);

    ASSERT_EQ(type, StrategyType::Third);
}