//
// Created by barte on 29.05.2023.
//

#include <gtest/gtest.h>
#include "Data/Instrument/CryptoCurrency/CryptoCurrency.h"



TEST(CryptoCurrencyTest, getPriceTest) {
    CryptoCurrency Cryptocurrency("id");
    Record record(1647580800,38000.00,38200.00,37700.00,38050.00,1);

    Cryptocurrency.addRecord(record);
    double result = Cryptocurrency.getPrice(record);

    ASSERT_FLOAT_EQ(result, 38050.00);
}
TEST(CryptoCurrencyTest, getType) {
    CryptoCurrency cryptoCurrency("id");

    ASSERT_EQ(cryptoCurrency.getType(), "crypto");
}