#include "Server.h"
#include <unistd.h>
#include "cstring"

Server::Server(in_addr_t ip, in_port_t port) : id(socket(AF_INET, SOCK_STREAM, 0)), in() {
    if (id >= 0) {
        struct sockaddr_in sockaddrIn;
        memset(&sockaddrIn, 0, sizeof(sockaddrIn));
        sockaddrIn.sin_family = AF_INET;
        sockaddrIn.sin_addr.s_addr = ip;
        sockaddrIn.sin_port = port;
        if (bind(id, (struct sockaddr *) &sockaddrIn, sizeof(sockaddrIn)) < 0) {
            perror("Error in binding to the socket!");
        }
        if (listen(id, this->qLength) < 0) {
            perror("Error in listening to the socket!");
        }
        memset(&tv, 0, sizeof(tv));
        tv.tv_sec = 180;
        FD_ZERO(&set);
        FD_SET(id, &set);
    } else {
        perror("Error in creating the socket!");
    }
}


int Server::acceptClient() {
    if (select(id + 1, &set, nullptr, nullptr, &tv) < 0) {
        perror("Error in select!");
    }
    if (FD_ISSET(id, &set)) {
        unsigned int addr_len = sizeof(this->in);
        int sock = accept(id, (struct sockaddr *) &in, &addr_len);
        if (sock < 0) {
            perror("Error in accepting the client!");
        }
        this->cSocket++;
        return sock;
    }
    return -1;
}

void Server::closer() const {
    ::close(this->id);

}

void Server::removeClient() {
    this->cSocket--;
}

int Server::getClientNum() const {
    return this->cSocket;
}
