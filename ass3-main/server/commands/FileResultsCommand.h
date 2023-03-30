#ifndef FINAL_FILERESULTSCOMMAND_H
#define FINAL_FILERESULTSCOMMAND_H

#include "sstream"

template<class T>
class FileResultsCommand : public Command<T> {
public:
    FileResultsCommand(DefaultIO *defaultIo, Data<T> *dataManager) : Command<T>("download data", defaultIo, dataManager) {}

    void execute() override {
        if (this->getCommandData()->getClassified().empty()) {
            this->getCommandIO()->IOWrite("Can't do, first Classify to get the results.");
            return;
        }
        this->getCommandIO()->IOWrite("Enter str for the output file.");
        std::string str = this->getCommandIO()->IORead();
        std::stringstream message;
        message << "SAVE <";
        for (int i = 0; i < this->getCommandData()->getClassified().size(); i++) {
            message << std::to_string(i + 1) + '\t' + this->getCommandData()->getClassified()[i] << "\n";
        }
        message << "Done." << "> " << "TO <" << str << ">";
        this->getCommandIO()->IOWrite(message.str());
        this->getCommandIO()->IORead();
    }

};


#endif //FINAL_FILERESULTSCOMMAND_H
