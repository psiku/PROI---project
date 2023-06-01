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
    instrument.addRecord({1, 0, 0, 0, 0, 0});
    instrument.addRecord({2, 0, 0, 0, 0, 0});
    instrument.addRecord({3, 0, 0, 0, 0, 0});
    instrument.addRecord({5, 0, 0, 0, 0, 0});

    SecondStrategy strategy(nullptr);

    auto result = strategy.splitByFibonacci(&instrument);

    ASSERT_EQ(result.size(), 3);

    ASSERT_EQ(result[0].from(), 1);
    ASSERT_EQ(result[0].to(), 1);

    ASSERT_EQ(result[1].from(), 2);
    ASSERT_EQ(result[1].to(), 3);

    ASSERT_EQ(result[2].from(), 5);
    ASSERT_EQ(result[2].to(), 5);
}
