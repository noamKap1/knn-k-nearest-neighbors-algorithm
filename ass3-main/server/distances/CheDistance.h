#include "Distance.h"
#include "vector"
#include <cstdio>
#include <cmath>

#ifndef FINAL_CHEDISTANCE_H
#define FINAL_CHEDISTANCE_H

template<class T>
class CheDistance : public Distance<T> {
public:
    std::string toString() const override {
        return "CHE";
    }

    double distance(T firstT, T secondT) const override {
        std::vector<double> firstCoor = firstT.getCoordinates();
        std::vector<double> secondCoor = secondT.getCoordinates();
        if (firstCoor.empty()) {
            perror("Error, Vector can't be empty!");
        }
        if (firstCoor.size() != secondCoor.size()) {
            perror("Error, Vector lengths have to be equal!");
        }
        double d1 = std::abs(firstCoor.at(0) - secondCoor.at(0));
        for (int i = 1; i < firstCoor.size(); i++) {
            double d2 = std::abs(firstCoor.at(i) - secondCoor.at(i));
            if (d2 > d1) {
                d1 = d2;
            }
        }
        return d1;
    }
};


#endif //FINAL_CHEDISTANCE_H
