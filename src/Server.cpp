#include "../include/smail/Server.h"
#include <ws2tcpip.h>
#include "Server.h"

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
    Server::~Server(){
        closesocket(serverSocket);
        // cleanup function
        WSACleanup();
        std::cout<<"[LOG] Server Instance close successfully"<<std::endl;
    }

    // socket formation
    void Server::run(int port){
        serverSocket = socket(AF_INET,SOCK_STREAM, 0);
        if(serverSocket == INVALID_SOCKET){
            std::cerr<<"[Error] Not able to create Socket connection "<<std::endl;
            return;
        }
    }
}