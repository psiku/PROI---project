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
    double volatility;

public:
    explicit Instrument(std::string id);
    void addRecord(const Record& record);                   // method which add record to the vector<Records> in Instrument
    virtual  double getVolatility(const Record& record);// virtual function which calculates Volatility in price, different for Stock, ETF, Cryptocurrency
    std::vector<Record> getRecords() const;                 // method which return vector<Records> of Instrument
    virtual double getPrice(const Record& record);          // virtual function which calculate price of record, different for Stock, ETF, Cryptocurrency

    // Insturment's own iterator implementation
    struct Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Record;
        using pointer           = Record*;
        using reference         = Record&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }  // dereferences the iterator and returns a reference to the value it points to
        pointer operator->() { return m_ptr; }          // returns the raw pointer the iterator is holding
        Iterator& operator++() { m_ptr++; return *this; } // prefix increment operator (++it), moves the iterator to the next element and returns a reference to the updated iterator.
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; } // Postfix increment operator (it++),creates a temporary copy of the iterator, moves the iterator to the next element, and returns the temporary copy.
        friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; } // compares two iterators for equality, returns true if they point to the same element, and false otherwise.
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; } // compares two iterators for inequality, returns true if they point to different elements, and false if they point to the same element.

        
    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&records[0]); }
    Iterator end() { return Iterator(&records[records.size()]); }
};


#endif //SHEEPSKIN_INSTRUMENT_H
