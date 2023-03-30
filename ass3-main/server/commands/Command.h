#include <utility>

#include "../IOs/DefaultIO.h"
#include "../Data.h"

#ifndef FINAL_COMMAND_H
#define FINAL_COMMAND_H

template<class T>
class Command {
private:
    Data<T> *commandData;
    std::string commandDescription;
    DefaultIO *commandIO;
public:
    Command(std::string commandDesc, DefaultIO *defaultIo, Data<T> *dataManager) :
            commandDescription(std::move(commandDesc)), commandIO(defaultIo), commandData(dataManager) {}

    virtual void execute() = 0;

    Data<T> *getCommandData() const {
        return commandData;
    }

    std::string getCommandDescription() {
        return std::string(commandDescription);
    }

    DefaultIO *getCommandIO() {
        return commandIO;
    }

    virtual ~Command() = default;
};

#endif //FINAL_COMMAND_H
