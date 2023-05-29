//
// Created by barte on 29.05.2023.
//
#include <gtest/gtest.h>
#include "Data/Instrument/Stock/Stock.h"



TEST(StockTest, getPriceTest) {
    Stock stock("id");
    Record record(1647580800,38000.00,38200.00,37700.00,38050.00,1);

    stock.addRecord(record);
    double result = stock.getPrice(record);

    ASSERT_FLOAT_EQ(result, 38025.0);
}
TEST(StockTest, getMean) {
    Stock stock("id");
    Record record(1647580800,38000.00,38200.00,37700.00,38050.00,1);

    stock.addRecord(record);
    double result = stock.calculateMean(record);

    ASSERT_FLOAT_EQ(result, 38025.0);
}