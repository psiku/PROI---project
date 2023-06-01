//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_NOTENOUGHDATAEXCEPTION_H
#define SHEEPSKIN_NOTENOUGHDATAEXCEPTION_H


#include <exception>

// Class NotEnoughDataException is an exception which is thrown when not enough data is provided to calculate strategy result
// it is derived from std::exception
class NotEnoughDataException: public std::exception {
public:
    const char* what() const throw() {
        return "Not enough data provided to calculate strategy result";
    }
};


#endif //SHEEPSKIN_NOTENOUGHDATAEXCEPTION_H
