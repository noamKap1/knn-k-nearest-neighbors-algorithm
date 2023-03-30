#include "Distance.h"
#include "vector"
#include <cstdio>
#include <cmath>

#ifndef FINAL_EUCDISTANCE_H
#define FINAL_EUCDISTANCE_H

template<class T>
class EucDistance : public Distance<T> {
public:
    std::string toString() const override {
        return "EUC";
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
            d += std::pow(firstCoor.at(i) - secondCoor.at(i), 2);
        }
        d = std::pow(d, 0.5);
        return d;
    }

};


#endif //FINAL_EUCDISTANCE_H
