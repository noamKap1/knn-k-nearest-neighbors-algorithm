#include "Server.h"
#include <iostream>
#include <unistd.h>
#include "stdio.h"
#include "cstring"

//Construct a server according to the address and the port
Server::Server(in_addr_t ip, in_port_t port) : id(socket(AF_INET, SOCK_STREAM, 0)), fIn() {
    if(id >= 0){
        struct sockaddr_in in;
        memset(&in, 0, sizeof(in));
        in.sin_addr.s_addr = ip;
        in.sin_family = AF_INET;
        in.sin_port = port;
        if (bind(id, (struct sockaddr *) &in, sizeof(in)) < 0) {
            perror("Error in binding the socket!");
        }
    } else {
        perror("Error in creating the socket!");
    }
}

//receives string from the socket
std::string Server::stringReceiver() {
    if (this->cSocket == 0) {
        if(listen(id, this->qLength) >= 0){
            unsigned int addrLen = sizeof(this->fIn);
            this->cSocket = accept(id, (struct sockaddr *) &fIn, &addrLen);
            if (this->cSocket < 0) {
                perror("Error in accepting the client!");
            }
        } else {
            perror("Error in listening to the socket!");
        }
    }
    char buff[Socket::buffer_size];
    int dataLen = Socket::buffer_size;
    int bytes = recv(this->cSocket, buff, dataLen, 0);
    if (bytes < 0) {
        perror("Error in writing to the socket!");
    }
    std::string string(buff);
    return string;
}

//Sends string to the socket
void Server::stringSender(std::string string) {
    int sent_bytes = send(this->cSocket, string.c_str(), strlen(string.c_str()), 0);
    if (sent_bytes < 0) {
        perror("Error in sending to the client!");
    }
}

//close the server
void Server::closer() {
    close(this->id);
}
