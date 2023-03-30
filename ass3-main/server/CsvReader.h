#ifndef CLIENT_CSVREADER_H
#define CLIENT_CSVREADER_H

#include "vector"
#include "string"
#include "Flower.h"

namespace CsvReader {
    std::vector<std::vector<std::string> > readFromCSV(const std::string &path);

    void writeToCSV(const std::string &filePath, const std::vector<std::string> &dataVector);

    //Calculates the euclidean distance of each flower to the unclassified flower
    std::vector<double> lengthArrEuc(std::vector<Flower> data, Flower &unclassified);

//Calculates the chebyshev distance of each flower to the unclassified flower
    std::vector<double> lengthArrChev(std::vector<Flower> data, Flower &unclassified);

//Calculates the manhattan distance of each flower to the unclassified flower
    std::vector<double> lengthArrMan(std::vector<Flower> data, Flower &unclassified);

    std::vector<std::string> typeArr(std::vector<Flower> data);

    std::string readFile(const std::string &);

    std::vector<std::vector<std::string>> readCSV(const std::string &);

    void writeFile(const std::string &path, const std::string &content);

    std::vector<std::string> stringSplitter(const std::string &, const char);

    std::string recv(int);

    void send(int, const std::string &);
}
#endif //CLIENT_CSVREADER_H
