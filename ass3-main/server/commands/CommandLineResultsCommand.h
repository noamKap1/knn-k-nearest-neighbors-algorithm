#include "Command.h"

#ifndef FINAL_COMMANDLINERESULTSCOMMAND_H
#define FINAL_COMMANDLINERESULTSCOMMAND_H

template<class T>
class CommandLineResultsCommand : public Command<T> {
public:
    CommandLineResultsCommand(DefaultIO *defaultIo, Data<T> *dataManager) : Command<T>("display data", defaultIo, dataManager) {}

    void execute() override {
        if (this->getCommandData()->getClassified().empty()) {
            this->getCommandIO()->IOWrite("Can't do, classify first to get results");
            return;
        }
        for (int i = 0; i < this->getCommandData()->getClassified().size(); i++) {
            this->getCommandIO()->IOWrite(std::to_string(i + 1) + '\t' + this->getCommandData()->getClassified()[i]);
        }
        this->getCommandIO()->IOWrite("Done.");
        this->getCommandIO()->IORead(); // Waiting for client to press enter.
    }

};


#endif //FINAL_COMMANDLINERESULTSCOMMAND_H
