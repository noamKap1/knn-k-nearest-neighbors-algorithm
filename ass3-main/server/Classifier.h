#include <algorithm>
#include "Flower.h"
#include "vector"
#include "string"
#include "map"
#include "type_traits"
#include "distances/Distance.h"
#include "string"
#include "distances/EucDistance.h"

#ifndef CLIENT_CLASSIFIER_H
#define CLIENT_CLASSIFIER_H

//Classifier
template<class T>
class Classifier {
private:
    std::vector<T> dataVector;
    int numOfEll = 5;


public:
    std::unique_ptr<Distance<T>> distance = std::make_unique<EucDistance<T>>();

    std::vector<T> getDataVector() {
        return this->dataVector;
    }

    void setData(const std::vector<T> &vector) {
        this->dataVector.clear();
        for (auto object: vector) {
            this->dataVector.push_back(object);
        }
    }

    void setDistance(std::unique_ptr<Distance<T>> &newDistance) {
        this->distance = std::move(newDistance);
    }

    void steNumOfEll(int k) {
        this->numOfEll = k;
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

    std::string toString() const {
        return "The current KNN parameters are: K = " + std::to_string(numOfEll) + ", distance metric = " +
               distance->toString();
    }
};


#endif //CLIENT_CLASSIFIER_H
