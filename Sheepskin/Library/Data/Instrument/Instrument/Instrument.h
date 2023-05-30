//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_INSTRUMENT_H
#define SHEEPSKIN_INSTRUMENT_H


#include <string>
#include <vector>
#include "../../Record/Record.h"
#include "../../Record/Record.h"


class Instrument {
private:
    std::string id;
    std::vector<Record> records;
    long double volatility;

public:
    explicit Instrument(std::string id);
    void addRecord(const Record& record);
    virtual long double getVolatility(const Record& record);
    std::vector<Record> getRecords() const;
    virtual double getPrice(const Record& record);

// Iterator -> możliwe że do przeniesienia jako osobna klasa
    struct Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Record;
        using pointer           = Record*;
        using reference         = Record&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; }
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&records[0]); }
    Iterator end() { return Iterator(&records[records.size()]); }
};


#endif //SHEEPSKIN_INSTRUMENT_H
