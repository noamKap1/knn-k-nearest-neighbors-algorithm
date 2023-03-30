#include <utility>

#include "vector"
#include "commands/Command.h"

#ifndef TESTING_CLI_H
#define TESTING_CLI_H

template<class T>
class CLI {
private:
    DefaultIO *io;
    std::vector<std::unique_ptr<Command<Flower>>> commands;

    void print() {
        std::string msg = "Welcome to the KNN Classifier Server. Please choose an option:";
        for (int i = 0; i < commands.size(); i++) {
            msg.append("\n" + std::to_string(i + 1) + ". " + commands[i]->getCommandDescription());
        }
        msg.append("\n" + std::to_string(commands.size() + 1) + ". exit");
        io->IOWrite(msg);
    }

public:
    CLI(DefaultIO *io, std::vector<std::unique_ptr<Command<Flower>>> commands) : io(io), commands(std::move(commands)) {
    }

    void start() {
        while (true) {
            print();
            std::string option = io->IORead();
            int optionNumber;
            try {
                optionNumber = std::stoi(option) - 1;
            }
            catch (const std::exception &e) {
                io->IOWrite("Please enter a number");
                continue;
            }
            if (optionNumber == commands.size()) {
                io->IOWrite("exit");
                break;
            }
            if (optionNumber < 0 || optionNumber > commands.size()) {
                io->IOWrite("Invalid command");
                continue;
            }
            commands[optionNumber]->execute();
        }
    }
};


#endif //TESTING_CLI_H
