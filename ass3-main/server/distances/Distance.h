#include "string"

#ifndef FINAL_DISTANCE_H
#define FINAL_DISTANCE_H

template<class T>
class Distance {
public:
    virtual std::string toString() const = 0;

    virtual double distance(T firstT, T secondT) const = 0;

    virtual ~Distance() = default;
};


#endif //FINAL_DISTANCE_H
