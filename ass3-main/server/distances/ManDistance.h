#include "Distance.h"
#include "vector"
#include <cstdio>
#include <cmath>

#ifndef FINAL_MANDISTANCE_H
#define FINAL_MANDISTANCE_H


template<class T>
class ManDistance : public Distance<T> {
public:
    std::string toString() const override {
        return "MAN";
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
        double d = 0;
        for (int i = 0; i < firstCoor.size(); i++) {
            d += std::abs(firstCoor.at(i) - secondCoor.at(i));
        }
        return d;
    }
};


#endif //FINAL_MANDISTANCE_H
