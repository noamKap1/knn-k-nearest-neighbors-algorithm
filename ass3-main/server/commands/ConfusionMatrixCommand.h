#include "Command.h"
#include "vector"
#include "string"
#include "../Flower.h"
#include "../Classifier.h"

#ifndef FINAL_CONFUSIONMATRIXCOMMAND_H
#define FINAL_CONFUSIONMATRIXCOMMAND_H

template<class T>
class ConfusionMatrixCommand : public Command<T> {

public:
    ConfusionMatrixCommand(DefaultIO *defaultIo, Data<T> *dataManager) : Command<T>("display algorithm confusion matrix", defaultIo, dataManager) {}

    void execute() override {
        std::vector<std::string> classified = this->getCommandData()->getClassified();
        std::vector<T> testVec = this->getCommandData()->getTest();
        std::vector<std::string> flowerTypes;

        if (classified.empty()) {
            this->getCommandIO()->IOWrite("Please classify first.");
            return;
        }
        const int N = testVec.size();
        std::map<std::string, std::map<std::string, double>> elementsMap;
        for (int i = 0; i < N; i++) {
            if (!elementsMap[testVec[i].getFlowerType()].count(classified[i])) {
                elementsMap[testVec[i].getFlowerType()][classified[i]] = 0;
            }
            elementsMap[testVec[i].getFlowerType()][classified[i]]++;
        }
        for (const auto &p: elementsMap) {
            flowerTypes.push_back(p.first);
            double sumOfApperances = 0;
            for (const auto &k: p.second) {
                sumOfApperances += k.second;
            }

            for (const auto &k: p.second) {
                elementsMap[p.first][k.first] = (k.second * 100) / sumOfApperances;
            }
        }
        for (const auto &p: elementsMap) {
            for (const std::string &flower: flowerTypes) {
                if (!elementsMap[p.first].count(flower)) {
                    elementsMap[p.first][flower] = 0;
                }
            }
        }
        std::vector<std::vector<std::string>> mat;
        for (const auto &percentages: elementsMap) {
            std::vector<std::string> prediction;
            for (const auto &predict: percentages.second) {
                prediction.push_back(std::to_string(predict.second));
            }
            mat.push_back(prediction);
        }
        std::string str = "";
        for (const std::string &s: flowerTypes) {
            str.append(s + "\t");
        }
        str.append("\n");
        for (const std::string& type: flowerTypes) {
            str.append(type + "\t");
            for(std::string &pType : flowerTypes){
                str.append(std::to_string(elementsMap[type][pType]) + "\t");
            }
            str.append("\n");
        }
        this->getCommandIO()->IOWrite(str);
        this->getCommandIO()->IORead();
    }
};


#endif //FINAL_CONFUSIONMATRIXCOMMAND_H
