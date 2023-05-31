//
// Created by barte on 31.05.2023.
//
//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//
#include <gtest/gtest.h>
#include "Validator/Validator.h"
#include "Data/Instrument/CryptoCurrency/CryptoCurrency.h"

TEST(ValidatorTests, ValidateInstrument) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 135.45, 200, 100, 175.25, 1000);
    Record record2(1647580860, 130.45, 200, 100, 175.25, 500);
    Record record3(1647580920, 125.45, 200, 100, 175.25, 750);
    Record record4(1647580980, 120.45, 200, 100, 175.25, 800);
    Record record5(1647581040, 100.45, 200, 100, 175.25, 1200);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record4);
    crypto.addRecord(record5);

    Validator validator;
    bool result = validator.validate(crypto);
    ASSERT_TRUE(result);
}
TEST(ValidatorTests, InvalidInstrument) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 135.45, -200, 100, 175.25, 1000);
    Record record2(1647580860, 130.45, 200, 100, 175.25, 500);
    Record record3(1647580920, 125.45, 200, 100, 175.25, 750);
    Record record4(1647580980, 120.45, 200, 100, 175.25, 800);
    Record record5(1647581040, 100.45, 200, 100, 175.25, 1200);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record4);
    crypto.addRecord(record5);

    Validator validator;
    bool result = validator.validate(crypto);
    ASSERT_FALSE(result);
}
TEST(ValidatorTests, InvalidBorderPricesTest) {
    Record record1(1647580800, 135.45, 200, 100, 175.25, 1000);

    Validator validator;
    bool result = validator.checkBorderPrices(record1);
    ASSERT_TRUE(result);
}
TEST(ValidatorTests, ValidBorderPricesTest) {
    Record record1(1647580800, 135.45, 100, 200, 175.25, 1000);

    Validator validator;
    bool result = validator.checkBorderPrices(record1);
    ASSERT_FALSE(result);
}