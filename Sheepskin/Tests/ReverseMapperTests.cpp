//
// Created by Wiktor Kruszewicz on 01/06/2023.
//
#include <gtest/gtest.h>
#include "Data/CSVWriter/ReverseMapper/ReverseMapper.h"
#include "Data/CSVReader/Mapper/Mapper.h"

TEST(ReverseMapperTests, DoubleToStringTest) {
    ReverseMapper reverse_mapper;
    Mapper mapper;
    double val = 123.5;
    ASSERT_FLOAT_EQ(mapper.translate<double>(reverse_mapper.translate<double>(val)), val);
}
TEST(ReverseMapperTests, NegativeDoubleToStringTest) {
    ReverseMapper reverse_mapper;
    Mapper mapper;
    double val = -123.5;
    ASSERT_FLOAT_EQ(mapper.translate<double>(reverse_mapper.translate<double>(val)), val);
}
