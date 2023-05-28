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
    Mapper mapper(vec);
    std::vector<int> ans = mapper.translate<int>();
    ASSERT_TRUE(ans[0] == 1 && ans[1] == 2 && ans[2] == 3);
}
TEST(CSVTests, CSVReaderTest) {
    CSVReader<int, double, std::string> reader("test.csv");
    reader.read();
//    /*CSVResult<int, double, std::string> res = */reader.getMapped();
//
//    std::tuple<int, double, std::string> tup = res.readline();
//
//    ASSERT_EQ(123.321, std::get<0>(tup));

}