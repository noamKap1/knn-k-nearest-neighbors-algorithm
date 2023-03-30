#include <netinet/in.h>
#include "string"

#ifndef CLIENT_SERVER_H
#define CLIENT_SERVER_H

class Server {
private:
    int id;
    int qLength = 5;
    int cSocket = 0;
    struct sockaddr_in in;
    fd_set set;
    struct timeval tv;
public:
    Server(in_addr_t ip, in_port_t port);

    int acceptClient();

    void closer() const;

    void removeClient();

    int getClientNum() const;

    ~Server() = default;
};


#endif //CLIENT_SERVER_H
