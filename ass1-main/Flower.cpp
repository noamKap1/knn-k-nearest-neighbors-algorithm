#include "Flower.h"
#include <cmath>


//Returns the flower type
std::string Flower::getFlowerType() const {
    return flowerType;
}

//calculates the euclidean distance
double Flower::calcEucDistance(const Flower &other) const {
    return std::sqrt(std::pow(this->widthOfSepal - other.widthOfSepal, 2)
                     + std::pow(this->lengthOfSepal - other.lengthOfSepal, 2) +
                     std::pow(this->lengthOfPetal - other.lengthOfPetal, 2)
                     + std::pow(this->widthOfPetal - other.widthOfPetal, 2));
}

//calculates the chebyshev distance
double Flower::calcChevDistance(const Flower &flower) const {
    return std::max(std::max(std::abs(this->widthOfPetal - flower.widthOfPetal),
                             std::abs(this->widthOfSepal - flower.widthOfSepal)),
                    std::max(std::abs(this->lengthOfPetal - flower.lengthOfPetal),
                             std::abs(this->lengthOfSepal - flower.lengthOfSepal)));
}

//calculates the manhattan distance
double Flower::calcManDistance(const Flower &flower) const {
    return std::abs(this->widthOfPetal - flower.widthOfPetal) +
           std::abs(this->widthOfSepal - flower.widthOfSepal) +
           std::abs(this->lengthOfPetal - flower.lengthOfPetal) +
           std::abs(this->lengthOfSepal - flower.lengthOfSepal);
}

//Construct a Flower from a vector that contains its coordinates
Flower::Flower(const std::vector<std::string> &v) :
        lengthOfSepal(std::stod(v.at(0))),
        widthOfSepal(std::stod(v.at(1))),
        widthOfPetal(std::stod(v.at(2))),
        lengthOfPetal(std::stod(v.at(3))) {
    if (v.size() == 5) {
        this->flowerType = v.at(4);
    }

}

//build and return flower vector which contains data which we get from the function
std::vector<Flower> flowersVector(const std::vector<std::vector<std::string>> &dataVector) {
    std::vector<Flower> result;
    for (const auto &v: dataVector) {
        Flower iris(v);
        result.push_back(iris);
    }
    return result;
}