//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_INALIDFORMATEXCEPTION_H
#define SHEEPSKIN_INALIDFORMATEXCEPTION_H

#include <exception>

class InvalidFormatException: public std::exception {
public:
    const char* what() const throw() {
        return "Wrong format of the csv file";
    }
};

#endif //SHEEPSKIN_INALIDFORMATEXCEPTION_H
