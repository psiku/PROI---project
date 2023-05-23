//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_MAPPER_H
#define SHEEPSKIN_MAPPER_H

#include <string>
#include <vector>

class Mapper {
    std::vector<std::string> column;
public:
    Mapper();
    Mapper(std::vector<std::string> column);
    void addColumn(std::vector<std::string> column);
    template <class T>
    std::vector<T> translate();
};



#endif //SHEEPSKIN_MAPPER_H
