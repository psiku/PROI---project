//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//
#include <gtest/gtest.h>
#include "Forecast/Forecast.h"

TEST(ForecastTests, AreEqualTests) {
    Forecast first(1,1,1);
    Forecast second(1,1,1);

    bool areEqual = (first == second);
    ASSERT_TRUE(areEqual);
}

TEST(ForecastTests, AreNotEqualTests) {
    Forecast first(1,1,1);
    Forecast second(0,0,0);

    bool areNotEqual = (first != second);
    ASSERT_TRUE(areNotEqual);
}

TEST(ForecastTests, PrecisionEqualityTests) {
    Forecast first(0.0000000001,1,1);
    Forecast second(0.0,1,1);

    bool areEqual = (first == second);
    ASSERT_TRUE(areEqual);
}

