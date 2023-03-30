#ifndef ASS1_FLOWER_H
#define ASS1_FLOWER_H


#include <string>
#include <vector>
#include "Classifiable.h"

//Flower class
class Flower : public Classifiable<Flower> {
private:
    //coordinates and flowerType
    double lengthOfPetal, widthOfPetal, lengthOfSepal, widthOfSepal;
    std::string flowerType = "None";
public:
    //calculates the euclidean distance
    double calcEucDistance(const Flower &) const override;

    //calculates the chebyshev distance
    double calcChevDistance(const Flower &) const override;

    //calculates the manhattan distance
    double calcManDistance(const Flower &) const override;

    //Returns the flower type
    std::string getFlowerType() const override;

    //Construct a Flower from a vector that contains its coordinates
    explicit Flower(const std::vector<std::string> &);

    Flower(Flower &&o) = default;

    Flower(const Flower &o) = default;

    Flower &operator=(const Flower &) = default;

    ~Flower() = default;
};

//build and return flower vector which contains data which we get from the function
std::vector<Flower> flowersVector(const std::vector<std::vector<std::string>> &dataVector);


#endif //ASS1_FLOWER_H