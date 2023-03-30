#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include "Client.h"
#include "CsvReader.h"
#include "thread"
#include <regex>

void receiver(Client *client);

void messagesHandler(const std::string &message, Client *client);

inline bool isFile(const std::string &path);

int main() {
    Client client(inet_addr("127.0.0.1"), htons(2505));
    std::thread thread(receiver, &client);
    while (true) {
        std::string str;
        getline(std::cin, str);
        if (isFile(str)) {
            str = CsvReader::readFile(str);
        }
        client.stringSender(str);
    }
}

void messagesHandler(const std::string &message, Client *client) {
    if (message == "exit") {
        client->closer();
        exit(0);
    }
    std::smatch m;
    std::regex regex("SAVE <((.|\\n)+)> TO <(.*)>");
    if(!std::regex_search(message, m, regex)){
        std::cout << message << std::endl;
    }
    else {
        CsvReader::writeFile(m[3].str(), m[1].str());
    }
}

void receiver(Client *client) {
    while (true) {
        const std::string &message = client->stringReceiver();
        messagesHandler(message, client);
    }
}

bool isFile(const std::string &path) {
    struct stat buffer{};
    return ((stat(path.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}
