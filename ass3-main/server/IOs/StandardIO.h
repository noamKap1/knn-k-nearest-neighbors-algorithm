#include "DefaultIO.h"

#ifndef FINAL_STANDARDIO_H
#define FINAL_STANDARDIO_H


class StandardIO : public DefaultIO {
public:
    void IOWrite(std::string) override;

    std::string IORead() override;
};


#endif //FINAL_STANDARDIO_H
