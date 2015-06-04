#ifndef ROUTER
#define ROUTER

#include "headers.h"
using namespace std;

class Router
{
public:
     Router( string name, int port );
     void routeMessage(int destPort, char *message);
     void receiver();
     void updateTable();

     // Must Define still
//     char calculateDV();
     
private:
     string m_id;
     int m_port;
     int** m_routeTable;
     
};

#endif
