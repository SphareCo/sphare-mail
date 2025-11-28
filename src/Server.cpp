#include "../include/smail/Server.h"
#include <ws2tcpip.h>

namespace smail
{
    // constructor
    Server::Server()
    {
        // winsock initialization

        WSADATA wsaData;
        int wsaErr = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (wsaErr != 0)
        {
            std::cerr << "[Error] Winsock initialization failed";
            exit(1);
        }

        serverSocket = INVALID_SOCKET;
        std::cout << "[LOG] Server Instance created & Winsock intialized." << std::endl;
    }

    // destructor
    Server::~Server()
    {
        closesocket(serverSocket);
        // cleanup function
        WSACleanup();
        std::cout << "[LOG] Server Instance close successfully" << std::endl;
    }

    // socket formation
    void Server::run(int port)
    {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == INVALID_SOCKET)
        {
            std::cerr << "[Error] Not able to create Socket connection " << std::endl;
            return;
        }

        // port and ip binding in sphare-mail
        sockaddr_in service;
        // AF_INET is for IPv4 protocol means version 4 IP
        // AF_INET6 is used for IPv6 protocol means version 6 IP
        service.sin_family = AF_INET;
        // It's can easily connect any IP
        // Setting IP address
        service.sin_addr.s_addr = INADDR_ANY;
        // Setting port number
        service.sin_port = htons(port);

        if (bind(serverSocket, (SOCKADDR *)&service, sizeof(service)) == SOCKET_ERROR)
        {
            std::cerr<<"[ERROR] Bind failed! "<<port<<"might be busy"<<std::endl;
            closesocket(serverSocket);
            return;
        }
    }
}