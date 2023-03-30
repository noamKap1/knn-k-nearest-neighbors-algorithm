#include "Command.h"
#include "../Classifier.h"
#include "../CsvReader.h"
#include "stdexcept"
#include "../distances/CheDistance.h"
#include "../distances/EucDistance.h"
#include "../distances/ManDistance.h"
#include "algorithm"
#include <memory>

#ifndef FINAL_CHANGEALGORITHMPROPERTIESCOMMAND_H
#define FINAL_CHANGEALGORITHMPROPERTIESCOMMAND_H

template<class T>
class ChangeAlgorithmPropertiesCommand : public Command<T> {
public:
    explicit ChangeAlgorithmPropertiesCommand(DefaultIO *defaultIo, Data<T> *dataManager) :
            Command<T>("algorithm settings", defaultIo,
                       dataManager) {}

    void execute() override {
        this->getCommandIO()->IOWrite(this->getCommandData()->getDataClassifier()->toString());
        std::string str = this->getCommandIO()->IORead();
        if (str.empty()) {
            this->getCommandIO()->IOWrite(this->getCommandData()->getDataClassifier()->toString());
            return;
        }
        std::vector<std::string> param = CsvReader::stringSplitter(str, ' ');
        if (param.size() != 2) {
            this->getCommandIO()->IOWrite("Error, expected 2 parameters.");
            return;
        }
        int numOfEll;
        try {
            numOfEll = std::stoi(param[0]);
        } catch (const std::invalid_argument &exception) {
            this->getCommandIO()->IOWrite("K should be an int.");
            return;
        }
        if (numOfEll < 1 || numOfEll > 10) {
            this->getCommandIO()->IOWrite("K should be between 1 and 10.");
            return;
        }
        std::unique_ptr<Distance<T>> distance;
        std::string inputDistance = param[1];
        std::transform(inputDistance.begin(), inputDistance.end(), inputDistance.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (inputDistance == "MAN" || inputDistance == "man") {
            distance = std::make_unique<ManDistance<T>>();
        } else if (inputDistance == "EUC" || inputDistance == "euc") {
            distance = std::make_unique<EucDistance<T>>();
        } else if (inputDistance == "CHE" || inputDistance == "che") {
            distance = std::make_unique<CheDistance<T>>();
        } else {
            this->getCommandIO()->IOWrite("Error, invalid distance metric.");
            return;
        }
        this->getCommandData()->getDataClassifier()->steNumOfEll(numOfEll);
        this->getCommandData()->getDataClassifier()->setDistance(distance);
        this->getCommandIO()->IOWrite(this->getCommandData()->getDataClassifier()->toString());
    }
};

#endif //FINAL_CHANGEALGORITHMPROPERTIESCOMMAND_H
