#include <vector>
#include <iostream>
#include "Flower.h"
#include "CsvReader.h"
#include "Classifier.h"

//Classify unclassified flowers which we read s files and the writes the Classified flowers to
//three files according to the length calculation way
int main(int argc, char *argv[]) {
    std::string path1 = "Unclassified.csv";
    std::string path2 = "classified.csv";
    std::string path3 = "euclidean_output.csv";
    std::string path4 = "chebyshev_output.csv";
    std::string path5 = "manhattan_output.csv";
    std::vector<Flower> unclassified = flowersVector(readFromCSV(path1));
    std::vector<Flower> classified = flowersVector(readFromCSV(path2));
    Classifier<Flower> classifierEuc(classified, std::stoi(argv[1]));
    Classifier<Flower> classifierChev(classified, std::stoi(argv[1]));
    Classifier<Flower> classifierMan(classified, std::stoi(argv[1]));
    std::vector<std::string> resultEuc;
    resultEuc.reserve(unclassified.size());
    for (auto iris: unclassified) {
        resultEuc.push_back(classifierEuc.classify(iris, classifierEuc.getDataVector(), lengthArrEuc(
                                                           classifierEuc.getDataVector(),
                                                           iris),
                                                   typeArr(classifierEuc.getDataVector())));
    }
    writeToCSV(path3, resultEuc);

    std::vector<std::string> resultChev;
    resultChev.reserve(unclassified.size());
    for (auto iris: unclassified) {
        resultChev.push_back(classifierChev.classify(iris, classifierChev.getDataVector(), lengthArrChev(classifierChev.
                                                             getDataVector(), iris),
                                                     typeArr(classifierChev.getDataVector())));
    }
    writeToCSV(path4, resultChev);

    std::vector<std::string> resultMan;
    resultMan.reserve(unclassified.size());
    for (auto iris: unclassified) {
        resultMan.push_back(classifierMan.classify(iris, classifierMan.getDataVector(), lengthArrMan(
                                                           classifierMan.getDataVector(),
                                                           iris),
                                                   typeArr(classifierMan.getDataVector())));
    }
    writeToCSV(path5, resultMan);
}