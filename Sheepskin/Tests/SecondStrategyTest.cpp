//
// Created by barte on 01.06.2023.
//
#include <gtest/gtest.h>
#include "Strategies/SecondStrategy/SecondStrategy.h"
#include "Data/Instrument/Stock/Stock.h"
#include "Data/Instrument/CryptoCurrency/CryptoCurrency.h"
#include "Data/Instrument/ETF/ETF.h"

TEST(FirstStrategyTest, FirstStrategyGetPriceTest){
    Stock stock("id");
    FirstStrategy strategy(&stock);

    Price value1 = strategy.status((3));
    Price value2 = strategy.status((0));
    Price value3 = strategy.status((-2.34));
    ASSERT_EQ(value1, DECREASE);
    ASSERT_EQ(value2, STILL);
    ASSERT_EQ(value3, INCREASE);
}