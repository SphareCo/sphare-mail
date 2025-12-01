// It's a Safe gaurd
#ifndef SMAIL_SERVER_H
#define SMAIL_SERVER_H

// socket library include for windows
#include <winsock2.h>
#include <iostream>

namespace smail
{
    // Server class created/
    class Server
    {
    private:
        SOCKET serverSocket;

    public:
        // Constructor: when server will create
        Server();

        // Destructor: when server will close
        ~Server();

        // This function will start the server in the specific port
        void run(int port);
    };

}

#endif