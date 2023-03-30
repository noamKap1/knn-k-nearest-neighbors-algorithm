#include <memory>
#include <vector>
#include "Flower.h"
#include "CsvReader.h"
#include "Classifier.h"
#include "Server.h"
#include "thread"
#include "IOs/SocketIO.h"
#include "IOs/DefaultIO.h"
#include "Data.h"
#include "commands/Command.h"
#include "commands/UploadCommand.h"
#include "commands/ChangeAlgorithmPropertiesCommand.h"
#include "commands/ConfusionMatrixCommand.h"
#include "commands/ClassifyCommand.h"
#include "commands/CommandLineResultsCommand.h"
#include "commands/FileResultsCommand.h"
#include "CLI.h"

void clientHandler(int cSocket, Server *server);

int main(int argc, char *argv[]) {
    Server server(INADDR_ANY, htons(2505));
    while (true) {
        int cSocket = server.acceptClient();
        if (cSocket == -1) {
            break;
        }
        std::thread handlingClient(clientHandler, cSocket, &server);
        handlingClient.detach();
    }
    while (server.getClientNum()) {}
    server.closer();
}

void clientHandler(int cSocket, Server *server) {
    Classifier<Flower> classifier;
    Data<Flower> data(&classifier);
    SocketIO io(cSocket);
    std::vector<std::unique_ptr<Command<Flower>>> commandVector;
    commandVector.push_back(std::make_unique<UploadCommand<Flower>>(&io, &data));
    commandVector.push_back(std::make_unique<ChangeAlgorithmPropertiesCommand<Flower>>(&io, &data));
    commandVector.push_back(std::make_unique<ClassifyCommand<Flower>>(&io, &data));
    commandVector.push_back(std::make_unique<CommandLineResultsCommand<Flower>>(&io, &data));
    commandVector.push_back(std::make_unique<FileResultsCommand<Flower>>(&io, &data));
    commandVector.push_back(std::make_unique<ConfusionMatrixCommand<Flower>>(&io, &data));
    CLI<Flower> c(&io, std::move(commandVector));
    c.start();
    server->removeClient();
}
