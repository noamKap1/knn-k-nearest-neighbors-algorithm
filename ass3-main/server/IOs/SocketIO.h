#include "DefaultIO.h"
#include "../Server.h"
#include "string"

#ifndef FINAL_SOCKETIO_H
#define FINAL_SOCKETIO_H


class SocketIO : public DefaultIO {
private:
    int socket;
public:
    explicit SocketIO(int socket);

    void IOWrite(std::string) override;

    std::string IORead() override;

    ~SocketIO();

};


#endif //FINAL_SOCKETIO_H
