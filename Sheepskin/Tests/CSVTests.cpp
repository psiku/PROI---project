//////
////// Created by Wiktor Kruszewicz on 18/05/2023.
//////
//#include <gtest/gtest.h>
//#include <string>
//#include <vector>
//#include "Data/CSVReader/Mapper/Mapper.h"
//#include "Data/CSVReader/CSVReader/CSVReader.h"
//
//TEST(CSVTests, MapperStringTest) {
//    std::vector<std::string> vec;
//    vec.emplace_back("1");
//    vec.emplace_back("2");
//    vec.emplace_back("3");
//    std::vector<int> expected_ans = {1,2,3};
////
//    Mapper mapper;
//    for(int i = 0 ; i < vec.size() ; i++) {
//        ASSERT_EQ(expected_ans[i], mapper.translate<int>(vec[i]));
//    }
//}
TEST(CSVTests, CSVReaderTest) {
   CSVReader reader;
//    reader.read(file);
   CSVResult res = reader.read("Tests/CSVFiles/test1.csv");
   std::vector<std::string> values = {"123.321", "1", "test"};
   auto row = res.getRow();
   for(int i = 0 ; i < values.size() ; i++)
       ASSERT_EQ(row[i], values[i]);
//    reader.read();
//    /*CSVResult<int, double, std::string> res = */reader.getMapped();
}
TEST(CSVTests, CSVReaderToMapperTest) {
   CSVReader reader;
   CSVResult res = reader.read("Tests/CSVFiles/test2.csv");

   Mapper mapper;
   auto instruments = mapper.mapToInstruments(res);

   ASSERT_EQ(instruments.size(), 4);

    Mapper mapper;
    for(int i = 0 ; i < vec.size() ; i++) {
        ASSERT_EQ(expected_ans[i], mapper.translate<int>(vec[i]));
    }
}
TEST(CSVTests, CSVReaderToMapperTest) {
    CSVReader reader;
    CSVResult res = reader.read("Tests/CSVFiles/test2.csv");

    Mapper mapper;
    auto* instruments = new std::vector<Instrument*>(mapper.mapToInstruments(res));

    ASSERT_EQ(instruments->size(), 4);
    for(auto instrument:*instruments) {
        ASSERT_TRUE(instrument->getRecords().size() > 0);
    }
//    for(auto *instrument:instruments) {
//        (instrument->getRecords());
//    }
//    ASSERT_TRUE(instruments[0]->getRecords().size() > 0);
}
