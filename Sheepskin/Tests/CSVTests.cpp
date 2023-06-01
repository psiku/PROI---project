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
    Mapper<int> mapper(vec);
    std::vector<int> ans = mapper.translate();
    ASSERT_TRUE(ans[0] == 1 && ans[1] == 2 && ans[2] == 3);
}
TEST(CSVTests, CSVReaderTest) {
    std::ifstream file;
    file.open("/Users/chumchum/Studia/SEM2/PROI/Projekt/laboratoria-proi23l-projekt-zespolowy/Sheepskin/Tests/test.csv");

    CSVReader<int, double, std::string> reader;
    reader.read(file);
//    reader.read();
//    /*CSVResult<int, double, std::string> res = */reader.getMapped();
}