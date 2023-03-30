#include <vector>
#include "Flower.h"
#include "CsvReader.h"
#include "Classifier.h"
#include "../Socket.h"
#include "Server.h"

int main(int argc, char *argv[]) {
    Socket *sServer;
    sServer = new Server(INADDR_ANY, htons(1234));
    std::string path = "classified.csv";
    std::vector<Flower> clfVector = flowerVector(readFromCSV(path));
    Classifier<Flower> classifier(clfVector, 5);
    std::string message = sServer->stringReceiver();
    std::vector<std::string> messages = stringSplitter(message, '\n');
    std::string flowerType;
    for (const std::string &string: messages) {
        Flower flower(string);
        flowerType.append(classifier.classify(flower, classifier.getDataVector(),
                                              lengthArrEuc(classifier.getDataVector(),flower),
                                              typeArr(classifier.getDataVector())));
        flowerType.append("\n");
    }
    sServer->stringSender(flowerType);
    sServer->closer();
    delete sServer;
    return 0;
}