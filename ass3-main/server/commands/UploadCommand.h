#include "Command.h"
#include "vector"
#include "../Flower.h"
#include "../IOs/DefaultIO.h"
#include "../Data.h"

#ifndef FINAL_UPLOADCOMMAND_H
#define FINAL_UPLOADCOMMAND_H

template<class T>
class UploadCommand : public Command<T> {
public:
    UploadCommand(DefaultIO *defaultIo, Data<Flower> *dataManager) :
            Command<T>("upload an unclassified csv data file", defaultIo, dataManager) {}

    void execute() override {
        this->getCommandIO()->IOWrite("Please upload your local train csv file");
        std::string str = this->getCommandIO()->IORead();
        if (str.empty()) {
            this->getCommandIO()->IOWrite("Error, invalid file");
            return;
        }
        try {
            this->getCommandData()->setTrain(stringToFlowers(str, true));
        } catch (std::exception &exception) {
            this->getCommandIO()->IOWrite("Error, invalid file");
            return;
        }
        this->getCommandIO()->IOWrite("Upload Completed.");
        this->getCommandIO()->IOWrite("Please upload your local test csv file");
        str = this->getCommandIO()->IORead();
        if (str.empty()) {
            this->getCommandIO()->IOWrite("Error, invalid file");
            return;
        }
        try {
            this->getCommandData()->setTest(stringToFlowers(str, true));
        } catch (std::exception &exception) {
            this->getCommandIO()->IOWrite("Error, invalid file");
            return;
        }
        this->getCommandIO()->IOWrite("Upload Completed.");
    }

};


#endif //FINAL_UPLOADCOMMAND_H
