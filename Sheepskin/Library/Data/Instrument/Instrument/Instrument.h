//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_INSTRUMENT_H
#define SHEEPSKIN_INSTRUMENT_H


#include <string>
#include <vector>
#include "../../Record/Record.h"
#include "../../Record/Record.h"

// Class Instrument is a class which contains vector of Records and id of Instrument
class Instrument {
private:
    std::string id;
    std::vector<Record> records;
    double volatility;

public:
    explicit Instrument(std::string id);
    // addRecord method add record to the vector<Records> in Instrument
    //@param record - record which will be added to the vector<Records> in Instrument
    void addRecord(const Record& record);

    //getRecords method returns vector of Records
    std::vector<Record> getRecords() const;

    //getPrice method returns price of the instrument
    //it is virtual method, because it is used in Instrument and in Stock, ETF, CryptoCurrency
    //@param record - record which will be used to calculate price
    //@return price of the instrument
    virtual double getPrice(const Record& record);

    // Iterator class is used to iterate through the vector of Records
    struct Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Record;
        using pointer           = Record*;
        using reference         = Record&;

        Iterator(pointer ptr) : m_ptr(ptr) {}
        //operator* returns reference to the Record
        reference operator*() const { return *m_ptr; }

        //operator-> returns pointer to the Record
        pointer operator->() { return m_ptr; }

        //operator++ increments pointer to the next Record
        //@eturn *this - reference to the Iterator
        Iterator& operator++() { m_ptr++; return *this; }

        //operator++ increments pointer to the next Record
        //@return tmp - copy of the Iterator
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        //operator== checks if two Iterators are equal
        //@return true if two Iterators are equal, false otherwise
        friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; }

        //operator!= checks if two Iterators
        //@return true if two Iterators are not equal, false otherwise
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }


    private:
        pointer m_ptr;
    };
    //@return Iterator to the first Record
    Iterator begin() { return Iterator(&records[0]); }

    //@return Iterator to the last Record
    Iterator end() { return Iterator(&records[records.size()]); }
};


#endif //SHEEPSKIN_INSTRUMENT_H
