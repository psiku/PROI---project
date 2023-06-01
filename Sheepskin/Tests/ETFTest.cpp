//
// Created by barte on 29.05.2023.
//
#include <gtest/gtest.h>
#include "Data/Instrument/ETF/ETF.h"



TEST(ETFTest, getPriceTest) {
    ETF etf("id");
    Record record(1647580800,38000.00,38200.00,37700.00,38050.00,1);

    etf.addRecord(record);
    double result = etf.getPrice(record);

    ASSERT_FLOAT_EQ(result, 37987.5);
}
TEST(ETFTest, getType) {
    ETF etf("id");

    ASSERT_EQ(etf.getType(), "etf");
}