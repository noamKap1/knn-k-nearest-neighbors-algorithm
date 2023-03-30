#ifndef ASS1_CLASSIFIABLE_H
#define ASS1_CLASSIFIABLE_H

//Classifiable interface
template<class T>
class Classifiable {
    //calculates the euclidean distance
    virtual double calcEucDistance(const T &other) const = 0;

    //calculates the chebyshev distance
    virtual double calcChevDistance(const T &other) const = 0;

    //calculates the manhattan distance
    virtual double calcManDistance(const T &other) const = 0;

    //returns the flower type
    virtual std::string getFlowerType() const = 0;
};


#endif //ASS1_CLASSIFIABLE_H
