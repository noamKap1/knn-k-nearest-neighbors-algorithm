#include "StandardIO.h"
#include "iostream"

void StandardIO::IOWrite(std::string message) {
    std::cout << message << std::endl;
}

std::string StandardIO::IORead() {
    std::string str;
    getline(std::cin, str);
    return str;
}

