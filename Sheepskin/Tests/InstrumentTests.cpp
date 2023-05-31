//
// Created by barte on 31.05.2023.
//
#include <gtest/gtest.h>
#include "Data/Instrument/Instrument/Instrument.h"


TEST(InstrumentTests, getRecordsEmpty) {
    Instrument instrument("id");

    double result = instrument.getRecords().size();

    ASSERT_EQ(result, 0);
}

TEST(InstrumentTests, addRecord) {
    Instrument instrument("id");
    Record record(1647580800,38000.00,38200.00,37700.00,38050.00,1);

    instrument.addRecord(record);
    instrument.addRecord(record);
    instrument.addRecord(record);
    double result = instrument.getRecords().size();

    ASSERT_EQ(result, 3);
}
TEST(InstrumentTests, iterateOverRecordsUsingIteratorMethods) {
    Instrument instrument("id");
    Record record1(1647580800, 38000.00, 38200.00, 37700.00, 38050.00, 1);
    Record record2(1647590800, 38100.00, 38300.00, 37800.00, 38150.00, 2);
    Record record3(1647600800, 38200.00, 38400.00, 37900.00, 38250.00, 3);

    instrument.addRecord(record1);
    instrument.addRecord(record2);
    instrument.addRecord(record3);

    int count = 0;
    for (auto it = instrument.begin(); it != instrument.end(); ++it) {
        count++;
    }

    ASSERT_EQ(count, 3);
}
TEST(InstrumentTests, dereferenceIterator) {
    Instrument instrument("id");
    Record record1(1647580800, 38000.00, 38200.00, 37700.00, 38050.00, 1);
    instrument.addRecord(record1);

    Instrument::Iterator it = instrument.begin();
    Record& record = *it;

    double value = record1.close;

    ASSERT_EQ(record.close, value);
}
TEST(InstrumentIteratorTests, compareIterators) {
    Instrument instrument("id");
    Record record1(1647580800, 38000.00, 38200.00, 37700.00, 38050.00, 1);
    Record record2(1647580860, 38100.00, 38200.00, 37700.00, 38050.00, 2);
    instrument.addRecord(record1);
    instrument.addRecord(record2);

    Instrument::Iterator it1 = instrument.begin();
    Instrument::Iterator it2 = instrument.begin();

    ASSERT_EQ(it1, it2);
    ASSERT_FALSE(it1 != it2);

    ++it1;

    ASSERT_FALSE(it1 == it2);
    ASSERT_NE(it1, it2);
}