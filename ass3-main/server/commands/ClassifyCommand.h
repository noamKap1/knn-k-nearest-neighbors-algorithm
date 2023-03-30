#include "Command.h"
#include "thread"

#ifndef FINAL_CLASSIFYCOMMAND_H
#define FINAL_CLASSIFYCOMMAND_H

template<class T>
class ClassifyCommand : public Command<T> {
public:
    ClassifyCommand(DefaultIO *defaultIo, Data<T> *dataManager) : Command<T>("classify data", defaultIo, dataManager) {}

    void execute() override {
        if (this->getCommandData()->getTest().empty()) {
            this->getCommandIO()->IOWrite("can't do, upload files first.");
            return;
        }
        this->getCommandIO()->IOWrite("Started classifying.");
        std::thread thread([this] { this->getCommandData()->classify(); });
        thread.detach();
        this->getCommandIO()->IOWrite("Finished classifying.");

    }
};

#endif //FINAL_CLASSIFYCOMMAND_H
