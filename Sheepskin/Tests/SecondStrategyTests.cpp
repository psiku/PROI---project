//
// Created by Grzegorz Statkiewicz on 01/06/2023.
//

#include <gtest/gtest.h>
#include "Data/Instrument/Stock/Stock.h"
#include "Strategies/SecondStrategy/SecondStrategy.h"

TEST(SecondStrategyTests, SplitByFibonacciTest)
{
    Stock instrument("abc");
    instrument.addRecord({1, 0, 0, 0, 0, 0});
    instrument.addRecord({2, 0, 0, 0, 0, 0});
    instrument.addRecord({3, 0, 0, 0, 0, 0});
    instrument.addRecord({4, 0, 0, 0, 0, 0});
    instrument.addRecord({5, 0, 0, 0, 0, 0});
    instrument.addRecord({6, 0, 0, 0, 0, 0});
    instrument.addRecord({7, 0, 0, 0, 0, 0});
    instrument.addRecord({8, 0, 0, 0, 0, 0});
    instrument.addRecord({9, 0, 0, 0, 0, 0});

    SecondStrategy strategy(&instrument);

    auto result = strategy.splitByFibonacci();

    ASSERT_EQ(result.size(), 4);

    ASSERT_EQ(result[0].getRecords().size(), 2);
    ASSERT_EQ(result[1].getRecords().size(), 2);
    ASSERT_EQ(result[2].getRecords().size(), 3);
}
TEST(SecondStrategyTests, getAverageStageTest)
{
    Stock instrument("abc");
    instrument.addRecord({1, 0, 0, 0, 9, 0});
    instrument.addRecord({2, 1, 1, 1, 9, 0});
    instrument.addRecord({3, 2, 2, 2, 9, 0});
    instrument.addRecord({4, 3, 3, 3, 9, 0});
    instrument.addRecord({5, 4, 4, 4, 9, 0});
    instrument.addRecord({6, 5, 5, 5, 9, 0});
    instrument.addRecord({7, 6, 6, 6, 9, 0});
    instrument.addRecord({8, 7, 7, 7, 9, 0});
    instrument.addRecord({9, 8, 8, 8, 9, 0});

    SecondStrategy strategy(&instrument);

    auto periods = strategy.splitByFibonacci();

    double result = strategy.getAverageStage(periods, Rising);

    ASSERT_EQ(result, 1);
}
TEST(SecondStrategyTests, getAverageStageTestFalling)
{
    Stock instrument("abc");
    instrument.addRecord({1, 9, 9, 9, 9, 0});
    instrument.addRecord({2, 8, 8, 8, 8, 0});
    instrument.addRecord({3, 7, 7, 7, 7, 0});
    instrument.addRecord({4, 6, 6, 6, 6, 0});
    instrument.addRecord({5, 5, 5, 5, 5, 0});
    instrument.addRecord({6, 4, 4, 4, 4, 0});
    instrument.addRecord({7, 3, 3, 3, 3, 0});
    instrument.addRecord({8, 2, 2, 2, 2, 0});
    instrument.addRecord({9, 1, 1, 1, 1, 0});

    SecondStrategy strategy(&instrument);

    auto periods = strategy.splitByFibonacci();

    double result = strategy.getAverageStage(periods, Falling);

    ASSERT_EQ(result, 0);
}

