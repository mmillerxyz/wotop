#include "proxysocket.h"

class ServerSocket {
public:
    int mainSocketFd, mainPipeSafeToRead, on;
    int pid;
    struct sockaddr_in server, client;
    socklen_t clientLen;
    FILE *writeSocketPtr, *readSocketPtr;

    ServerSocket();
    void listenOnPort(int portNumber);
    // void connectToClient(void (*f)(ClientSocket&));
    void connectToSocket(void (*f)(ProxySocket&), Mode);
    void closeSocket();
};
