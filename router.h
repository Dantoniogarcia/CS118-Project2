#ifndef ROUTER
#define ROUTER

#include "headers.h"

class Router
{
public:
     Router(int portNumber, char **neighbors);
     void routeMessage(int destPort, char *message);
     void receiver();

     // Must Define still
//     void updateTable();
//     char calculateDV();
     
private:
     int m_portNumber;
     int destPort;
     char** dataTable;
};

#endif
