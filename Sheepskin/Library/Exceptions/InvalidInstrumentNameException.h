//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_INVALIDINSTRUMENTNAMEEXCEPTION_H
#define SHEEPSKIN_INVALIDINSTRUMENTNAMEEXCEPTION_H

#include <exception>

// Class InvalidInstrumentNameException is an exception which is thrown when invalid instrument name is provided
// it is derived from std::exception
class InvalidInstrumentNameException: public std::exception {
public:
    const char* what() const throw() {
        return "Invalid instrument name provided";
    }
};

#endif //SHEEPSKIN_INVALIDINSTRUMENTNAMEEXCEPTION_H
