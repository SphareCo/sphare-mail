#include "../include/smail/Server.h"

int main() {
    std::cout<<"---Sphare Co. Mail Server System"<<std::endl;

    smail::Server server;

    server.run(2525);


    return 0;
}