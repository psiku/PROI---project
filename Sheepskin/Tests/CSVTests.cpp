//
// Created by Wiktor Kruszewicz on 18/05/2023.
//
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../ConsoleApp/Data/CSVReader/Mapper/Mapper.h"

TEST(CSVTests, MapperStringTest) {
    std::vector<std::string> vec;
    vec.emplace_back("1");
    vec.emplace_back("2");
    vec.emplace_back("3");
    Mapper mapper(vec);
    std::vector<int> ans = mapper.translate<int>();
    ASSERT_TRUE(ans[0] == 1 && ans[1] == 2 && ans[2] == 3);
}