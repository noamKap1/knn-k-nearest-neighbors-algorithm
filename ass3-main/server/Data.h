#include "Classifier.h"
#include "CsvReader.h"

#ifndef CLIENT_DATA_H
#define CLIENT_DATA_H

template<class T>
class Data {
private:
    std::vector<T> test;
    Classifier<T> *dataClassifier;
    std::vector<std::string> classified;
public:
    explicit Data(Classifier<T> *classifier) : dataClassifier(classifier) {}

    void classify() {
        classified.clear();
        std::string str = dataClassifier->distance->toString();
        if (str == "EUC") {
            for (auto t: test) {
                classified.push_back(dataClassifier->classify(t, dataClassifier->getDataVector(),
                                                              CsvReader::lengthArrEuc(dataClassifier->getDataVector(),
                                                                                      t),
                                                              CsvReader::typeArr(dataClassifier->getDataVector())));
            }
        } else if (str == "MAN") {
            for (auto t: test) {
                classified.push_back(dataClassifier->classify(t, dataClassifier->getDataVector(),
                                                              CsvReader::lengthArrMan(dataClassifier->getDataVector(),
                                                                                      t),
                                                              CsvReader::typeArr(dataClassifier->getDataVector())));
            }
        } else {
            for (auto t: test) {
                classified.push_back(dataClassifier->classify(t, dataClassifier->getDataVector(),
                                                              CsvReader::lengthArrChev(dataClassifier->getDataVector(),
                                                                                       t),
                                                              CsvReader::typeArr(dataClassifier->getDataVector())));
            }
        }
    }

    const std::vector<T> &getTest() const {
        return test;
    }

    void setTest(const std::vector<T> &v) {
        this->test = v;
    }

    Classifier<T> *getDataClassifier() const {
        return dataClassifier;
    }

    void setTrain(const std::vector<T> &v) {
        dataClassifier->setData(v);
    }

    const std::vector<std::string> &getClassified() const {
        return classified;
    }

    void setClassified(std::vector<std::string> v) {
        this->classified = v;
    }


};


#endif //CLIENT_DATA_H
