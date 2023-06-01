//
// Created by Wiktor Kruszewicz on 18/05/2023.
//
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../ConsoleApp/Data/CSVReader/Mapper/Mapper.h"
#include "../ConsoleApp/Data/CSVReader/CSVReader/CSVReader.h"

TEST(CSVTests, MapperStringTest) {
    std::vector<std::string> vec;
    vec.emplace_back("1");
    vec.emplace_back("2");
    vec.emplace_back("3");
    std::vector<int> expected_ans = {1,2,3};

    Mapper mapper;
    for(int i = 0 ; i < vec.size() ; i++) {
        ASSERT_EQ(expected_ans[i], mapper.translate<int>(vec[i]));
    }
}
TEST(CSVTests, CSVReaderTest) {
    CSVReader<int, double, std::string> reader;
    reader.read("./test.csv");
//    reader.read();
//    /*CSVResult<int, double, std::string> res = */reader.getMapped();
}