#include "string"

#ifndef FINAL_DEFAULTIO_H
#define FINAL_DEFAULTIO_H


class DefaultIO {
public:
    virtual void IOWrite(std::string) = 0;

    virtual std::string IORead() = 0;
};


#endif //FINAL_DEFAULTIO_H
