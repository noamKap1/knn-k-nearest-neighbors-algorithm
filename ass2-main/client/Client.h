#ifndef ASS2_CLIENT_H
#define ASS2_CLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "string"
#include "../Socket.h"

class Client : public Socket {
private:
    bool connected = false;
    int socket;
    struct sockaddr_in in;
public:
    void stringSender(std::string) override;

    std::string stringReceiver() override;

    void closer() override;

    Client(in_addr_t, in_port_t);

    ~Client() override = default;
};


#endif //ASS2_CLIENT_H
