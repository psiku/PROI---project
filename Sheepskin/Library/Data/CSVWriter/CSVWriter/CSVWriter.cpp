//
// Created by Grzegorz Statkiewicz on 11/05/2023.
//

//#include <string>
//
//#include "CSVWriter.h"
//#include <fstream>
//#include "../../../Estimation/Estimation.h"
//#include "../ReverseMapper/ReverseMapper.h"
//
//template <class T>
//CSVWriter<T>::CSVWriter(std::string filename, std::vector<T> decisions): filename(std::move(filename)), decisions(decisions) {};
//
//template <class T>
//void CSVWriter<T>::write() {
//}
//
//template <>
//void CSVWriter<Estimation>::write() {
//    ReverseMapper mapper;
//
//    std::ofstream file;
//    file.open(filename);
//    for(Estimation decision:decisions) {
//        file << mapper.mapEstimationToRow(decision) << "\n";
//    }
//}