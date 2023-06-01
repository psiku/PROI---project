//
// Created by Grzegorz Statkiewicz on 01/06/2023.
//

#ifndef SHEEPSKIN_INVALIDARGUMENTSEXCEPTION_H
#define SHEEPSKIN_INVALIDARGUMENTSEXCEPTION_H

class InvalidArgumentsException: public std::exception {
public:
    const char* what() const throw() {
        return "Invalid arguments were provided (probably to small)";
    }
};

#endif //SHEEPSKIN_INVALIDARGUMENTSEXCEPTION_H
