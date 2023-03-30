#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "string"

class Client {
private:
    int socket;
    struct sockaddr_in in;
public:

    std::string stringReceiver() const;

    void stringSender(const std::string &str) const;

    void closer() const;

    Client(in_addr_t, in_port_t);

    ~Client() = default;
};


#endif //CLIENT_CLIENT_H
