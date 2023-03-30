#include "vector"
#ifndef CLIENT_CLASSIFIABLE_H
#define CLIENT_CLASSIFIABLE_H

class Classifiable {

    virtual double getDistance() const = 0;

    virtual std::string getFlowerType() const = 0;

    virtual std::vector<double> getCoordinates() const = 0;
};


#endif //CLIENT_CLASSIFIABLE_H
