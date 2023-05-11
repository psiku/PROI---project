//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#include <gtest/gtest.h>
#include "../Library/Strategies/FirstStrategy/FirstStrategy.h"
#include "../Library/Data/Instrument/Stock/Stock.h"
#include "Strategies/SecondStrategy/SecondStrategy.h"

TEST(StrategyTest, FirstStrategyTest) {
    Stock stock("test");
    FirstStrategy strategy(stock);

    StrategyResult result = strategy.eval();
    ASSERT_FLOAT_EQ(result.getFallChance(), 0.5);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 0.5);
}
TEST(StrategyTest, SecondStrategyTest) {
    Stock stock("test");
    SecondStrategy strategy(stock);

    StrategyResult result = strategy.eval();
    ASSERT_FLOAT_EQ(result.getFallChance(), 0.2);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 0.8);
}
