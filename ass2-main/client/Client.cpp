#include <string>
#include <unistd.h>
#include <cstring>
#include "Client.h"

Client::Client(in_addr_t ip, in_port_t port) : socket(::socket(AF_INET, SOCK_STREAM, 0)), in() {
    if(socket >= 0){
        memset(&in, 0, sizeof(in));
        in.sin_family = AF_INET;
        in.sin_addr.s_addr = ip;
        in.sin_port = port;
    } else {
        perror("Error in creating the socket!");

    }
}

void Client::stringSender(std::string str) {
    if (!connected) {
        if (connect(socket, (struct sockaddr *) &in, sizeof(in)) < 0) {
            perror("Error in connecting to the server!");
        }
        connected = true;
    }
    int bytes = send(socket, str.c_str(), strlen(str.c_str()), 0);
    if (bytes < 0) {
        perror("Error in writing to the socket!");
    }
}


std::string Client::stringReceiver() {
    //Read the message fIn the socket and save in the buffer
    char buffer[Socket::buffer_size];
    int bytes = recv(socket, buffer, Socket::buffer_size, 0);
    if(bytes >= 0){
        std::string message(buffer, strlen(buffer));
        return message;
    } else {
        perror("Error in reading from the socket!");
    }
}

void Client::closer() {
    close(this->socket);
}


