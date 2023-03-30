#include <string>
#include <unistd.h>
#include <cstring>
#include "Client.h"
#include "CsvReader.h"

Client::Client(in_addr_t ip, in_port_t port) : socket(::socket(AF_INET, SOCK_STREAM, 0)), in() {
    //Initialize the socket and check it
    if (socket < 0) {
        perror("Error in creating a socket!");
    }
    memset(&in, 0, sizeof(in));
    in.sin_family = AF_INET;
    in.sin_addr.s_addr = ip;
    in.sin_port = port;
    if (connect(socket, (struct sockaddr *) &in, sizeof(in)) < 0) {
        perror("Error in creating the socket!");
    }
}

void Client::stringSender(const std::string &str) const {
    CsvReader::send(socket, str);
}


std::string Client::stringReceiver() const {
    return CsvReader::recv(socket);
}

void Client::closer() const {
    ::close(this->socket);
}


