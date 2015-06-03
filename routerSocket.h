#ifndef ROUTERSOCKET
#define ROUTERSOCKET

#include "headers.h"

class RouterSocket
{
public:
     RouterSocket(int port);
     int sendMessage(const char *message);
     
private:
     int port;
     int s;
     sockaddr_in cAddr;
     sockaddr_in sAddr;
     hostent* h;
};

#endif
