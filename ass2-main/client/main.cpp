#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "vector"
#include "CsvReader.h"
#include "../Socket.h"
#include "Client.h"

int main(int argc, char *argv[]) {
    Client client(inet_addr("127.0.0.1"), htons(1234));
    std::vector<std::vector<std::string>> unclfVector = readFromCSV(argv[1]);
    Socket *sClient;
    sClient = &client;
    std::string message;
    for (const std::vector<std::string> &vector: unclfVector) {
        for (const std::string &str: vector) {
            message.append(str);
            message.append(" ");
        }
        message.pop_back();
        message.append("\n");
    }
    message.pop_back();
    sClient->stringSender(message);
    std::string flowerTypes = sClient->stringReceiver();
    std::vector<std::string> write = stringSplitter(flowerTypes, '\n');
    writeToCSV(argv[2], write);
    client.closer();
    return 0;
}