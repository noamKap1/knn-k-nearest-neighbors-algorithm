#include "SocketIO.h"
#include "string"
#include "../CsvReader.h"
#include <unistd.h>

SocketIO::SocketIO(int socket) : socket(socket) {}

void SocketIO::IOWrite(std::string message) {
    CsvReader::send(this->socket, message);
}

std::string SocketIO::IORead() {
    return CsvReader::recv(this->socket);
}

SocketIO::~SocketIO() {
    close(this->socket);
}