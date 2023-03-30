#ifndef CLIENT_FLOWER_H
#define CLIENT_FLOWER_H


#include <string>
#include <vector>
#include "Classifiable.h"

//Flower class
class Flower : public Classifiable {
private:
    std::vector<double> coor;
    double distance;
    std::string type = "None";
    bool classified;
public:
    //calculates the euclidean distance
    double calcEucDistance(Flower other);

    //calculates the chebyshev distance
    double calcChevDistance(Flower flower);

    //calculates the manhattan distance
    double calcManDistance(Flower flower);

    double getDistance() const override;

    std::vector<double> getCoordinates() const override;

    std::string getFlowerType() const override;

    explicit Flower(const Flower &, std::string);

    explicit Flower(const std::vector<std::string> &, bool);

    Flower(Flower &&o) = default;

    Flower(const Flower &o) = default;

    Flower &operator=(const Flower &) = default;

    ~Flower() = default;
};

std::vector<Flower> stringToFlowers(const std::string &, bool);

//build and return flower vector which contains dataVector which we get s the function
//std::vector<Flower> flowerVector(const std::vector<std::vector<std::string>> &);

#endif //CLIENT_FLOWER_H
