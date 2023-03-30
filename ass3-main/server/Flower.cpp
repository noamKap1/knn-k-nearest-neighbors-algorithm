#include "Flower.h"
#include "stdexcept"
#include "vector"
#include <cmath>
#include "CsvReader.h"

//calculates the euclidean distance
double Flower::calcEucDistance(Flower other) {
    double sqrDistance = 0;
    for (int i = 0; i < coor.size(); i++) {
        sqrDistance += (this->coor[i] - other.coor[i]) * (this->coor[i] - other.coor[i]);
    }
    this->distance = std::sqrt(sqrDistance);
    return this->distance;
}

//calculates the chebyshev distance
double Flower::calcChevDistance(Flower flower) {
    this->distance = 0;
    for (int i = 0; i < coor.size(); i++) {
        double abs = std::abs(this->coor[i] - flower.coor[i]);
        this->distance = std::max(abs, this->distance);
    }
    return this->distance;
}

//calculates the manhattan distance
double Flower::calcManDistance(Flower flower) {
    this->distance = 0;
    for (int i = 0; i < coor.size(); i++) {
        this->distance += std::abs(this->coor[i] - flower.coor[i]);
    }
    return this->distance;
}

std::string Flower::getFlowerType() const {
    if (!classified) {
        perror("Error, flower is not classified!");
    }
    return type;
}


std::vector<double> Flower::getCoordinates() const {
    return this->coor;
}

double Flower::getDistance() const {
    return this->distance;
}

Flower::Flower(const Flower &unclassified, std::string classification) : coor(unclassified.getCoordinates()),
                                                                         type(std::move(classification)),
                                                                         classified(true) {}

Flower::Flower(const std::vector<std::string> &v, bool isClassified) : classified(isClassified) {
    if(!isClassified){
        for (const auto &i: v) {
            coor.push_back(std::stod(i));
        }
    } else {
        for (int i = 0; i < v.size() - 1; i++) {
            coor.push_back(std::stod(v[i]));
        }
        type = v[v.size() - 1];
    }
}

std::vector<Flower> stringToFlowers(const std::string &encoding, bool isClassified) {
    std::vector<Flower> flowers;
    std::vector<std::string> flowersEn = CsvReader::stringSplitter(encoding, '\n');
    int coordinateNum = CsvReader::stringSplitter(flowersEn[0], ',').size();
    for (const std::string &coordinatesEncoding: flowersEn) {
        std::vector<std::string> vector = CsvReader::stringSplitter(coordinatesEncoding, ',');
        if (vector.size() != coordinateNum) {
            throw std::invalid_argument("Error, all Flowers should have the same amount of vector!");
        }
        if (vector.size() < 2) {
            throw std::invalid_argument("Error, the flower should have at least one coordinate!");
        }
        try {
            flowers.emplace_back(vector, isClassified);
        } catch (const std::exception &exception) {
            throw std::invalid_argument("Invalid coordinates");
        }
    }
    return flowers;
}

//build and return flower vector which contains dataVector which we get s the function
//std::vector<Flower> flowerVector(const std::vector<std::vector<std::string>> &dataVector) {
//    std::vector<Flower> result;
//    for (const auto &v: dataVector) {
//        Flower iris(v);
//        result.push_back(iris);
//    }
//    return result;
//}
