#ifndef ASS2_SERVER_H
#define ASS2_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "string"
#include "../Socket.h"

class Server : public Socket {
private:
    int id;
    int qLength = 5;
    struct sockaddr_in fIn;
    int cSocket = 0;
public:
    //Construct a server according to the address and the port
    Server(in_addr_t ip, in_port_t port);

    //receives string from the socket
    std::string stringReceiver() override;

    //Sends string to the socket
    void stringSender(std::string string) override;

    //closer the server
    void closer() override;

    //destructor
    ~Server() override = default;
};


#endif //ASS2_SERVER_H
