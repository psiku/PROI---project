//
// Created by Grzegorz Statkiewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_CSVWRITER_H
#define SHEEPSKIN_CSVWRITER_H

#include <string>
#include <vector>

template <class T>
class CSVWriter {
private:
    std::string filename;
//    std::vector<T> decisions;
public:
    CSVWriter(std::string filename);
    void write();
};


#endif //SHEEPSKIN_CSVWRITER_H
