#include <iostream>
#include <fstream>
#include <sstream>
#include "CsvReader.h"

//Read s a csv file and return a data vector which contains the file lines
std::vector<std::vector<std::string>> readFromCSV(const std::string &file) {
    std::ifstream iStream(file);
    if (!iStream.is_open()){
        std::cout << "Could not open file" << std::endl;
    }
    std::string lines, s;
    std::vector<std::vector<std::string>> dataVector;
    while (iStream.good()) {
        std::getline(iStream, lines);
        std::stringstream stringStream(lines);

        std::vector<std::string> row;
        while (std::getline(stringStream, s, ',')) {
            row.push_back(s);
        }
        if (!row.empty())
            dataVector.push_back(row);
    }
    return dataVector;
}

//Calculates the euclidean distance of each flower to the unclassified flower
std::vector<double> lengthArrEuc(std::vector<Flower> data, Flower &unclassified) {
    std::vector<double> length;
    for (int i = 0; i < data.size(); i++) {
        length.push_back(data[i].calcEucDistance(unclassified));
    }
    return length;
}

//Calculates the manhattan distance of each flower to the unclassified flower
std::vector<double> lengthArrMan(std::vector<Flower> data, Flower &unclassified) {
    std::vector<double> length;
    for (int i = 0; i < data.size(); i++) {
        length.push_back(data[i].calcManDistance(unclassified));
    }
    return length;
}

//Calculates the chebyshev distance of each flower to the unclassified flower
std::vector<double> lengthArrChev(std::vector<Flower> data, Flower &unclassified) {
    std::vector<double> length;
    for (int i = 0; i < data.size(); i++) {
        length.push_back(data[i].calcChevDistance(unclassified));
    }
    return length;
}

//Returns vector which contains all the flower types
std::vector<std::string> typeArr(std::vector<Flower> data) {
    std::vector<std::string> types;
    for (int i = 0; i < data.size(); i++) {
        types.push_back(data[i].getFlowerType());
    }
    return types;
}

//Write to a csv file
void writeToCSV(const std::string &file, const std::vector<std::string> &dataVector) {
    std::ofstream oStream(file);
    for (const std::string &line: dataVector) {
        oStream << line << std::endl;
    }
}
