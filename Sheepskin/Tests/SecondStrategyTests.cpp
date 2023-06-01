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


    SecondStrategy strategy(nullptr);

    auto result = strategy.splitByFibonacci(&instrument);

    ASSERT_EQ(result.size(), 4);

    ASSERT_EQ(result[0].getRecords().size(), 2);
    ASSERT_EQ(result[1].getRecords().size(), 2);
    ASSERT_EQ(result[2].getRecords().size(), 3);
}
