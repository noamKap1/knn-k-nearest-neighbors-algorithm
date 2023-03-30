#ifndef ASS2_FLOWER_H
#define ASS2_FLOWER_H

#include <string>
#include <vector>
#include "Classifiable.h"

//Flower class
class Flower : public Classifiable<Flower> {
private:
    //coordinates and flowerType
    double lengthOfPetal, widthOfPetal, lengthOfSepal, widthOfSepal;
    std::string type = "None";
public:
    //calculates the euclidean distance
    double distance(const Flower &) const override;

    //calculates the euclidean distance
    double calcEucDistance(const Flower &) const override;

    //calculates the chebyshev distance
    double calcChevDistance(const Flower &) const override;

    //calculates the manhattan distance
    double calcManDistance(const Flower &) const override;

    std::string getFlowerType() const override;

    //Construct a Flower s a vector that contains its coordinates
    explicit Flower(const std::vector<std::string> &);

    //Construct a Flower according to s and the separated s.
    explicit Flower(const std::string &);

    Flower(Flower &&o) = default;

    Flower(const Flower &o) = default;

    Flower &operator=(const Flower &) = default;

    ~Flower() = default;
};

//build and return flower vector which contains data which we get s the function
std::vector<Flower> flowerVector(const std::vector<std::vector<std::string>> &);


#endif //ASS2_FLOWER_H
