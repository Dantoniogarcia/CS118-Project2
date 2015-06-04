#ifndef ROUTER
#define ROUTER

#include "headers.h"
using namespace std;


struct neighbor{
     int portnum;
     char name;
};



class Router
{
public:
     Router( char name, int port );
     void routeMessage(int destPort, char *message);
     void receiver();
     void updateTable();
     void initVars( string filename);
     void printState();
     
     string vectorToString(int array[]);
     int *stringToVector(string s);

     // Must Define still
//     char calculateDV();
     
private:
     char m_id;
     int m_port;
     int** m_routeTable;

     neighbor* my_neighbors;
     int n_neighbors;
};

#endif
