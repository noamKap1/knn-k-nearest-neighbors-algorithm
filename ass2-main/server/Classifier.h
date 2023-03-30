#ifndef ASS2_CLASSIFIER_H
#define ASS2_CLASSIFIER_H

#include <algorithm>
#include "Flower.h"
#include "vector"
#include "string"
#include "map"
#include "type_traits"

template<class T>
class Classifier {
private:
    //List of the classifiables
    std::vector<T> dataVector;
    //The k of the kkl algorithm
    int numOfEll;

public:
    //Construct a Classifier
    explicit Classifier(const std::vector<T> &data, int k) : numOfEll(k) {
        for (auto object: data) {
            this->dataVector.push_back(object);
        }
    }

    //Sets the vector field
    void setVector(std::vector<T> vector) {
        this->dataVector = vector;
    }

    //returns the data vector
    std::vector<T> getDataVector() {
        return this->dataVector;
    }

//Classify an unclassified Flower
    std::string classify(T &unclassified, std::vector<T> vector, std::vector<double> v, std::vector<std::string> s) {
        double temp = 0;
        for (int i = 0; i < vector.size(); i++) {
            for (int j = i + 1; j < vector.size(); j++) {
                if (v[j] < v[i]) {
                    temp = v[i];
                    std::string string = s[i];
                    s[i] = s[j];
                    s[j] = string;
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
        std::map<std::string, int> map;
        for (int i = 0; i < numOfEll; i++) {
            if (map.count(s[i]) == 0) {
                map[s[i]] = 0;
            }
            map[s[i]]++;
        }
        int max = 0;
        std::string type;
        for (const auto &item: map) {
            if (max < item.second) {
                type = item.first;
                max = item.second;
            }
        }
        return type;
    }

    ~Classifier() = default;

    Classifier(Classifier &&o) noexcept = default;

    Classifier(const Classifier &o) = default;

    Classifier &operator=(const Classifier &) = default;
};


#endif //ASS2_CLASSIFIER_H
