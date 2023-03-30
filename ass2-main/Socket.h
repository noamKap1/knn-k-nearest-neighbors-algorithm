#ifndef ASS2_SOCKET_H
#define ASS2_SOCKET_H

#include "string"

class Socket {
public:
    //Set the buffer size
    static const int buffer_size = 4096;

    /**
     * Send the message through the socket
     */
    virtual void stringSender(std::string) = 0;

    /**
     * Get the message in the socket
     * @return the message
     */
    virtual std::string stringReceiver() = 0;

    /**
     * Close the socket
     */
    virtual void closer() = 0;

    /**
     * Destructor
     */
    virtual ~Socket() = default;
};


#endif //ASS2_SOCKET_H
