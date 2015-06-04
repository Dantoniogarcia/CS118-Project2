#ifndef ROUTER
#define ROUTER

#include "headers.h"
using namespace std;


struct neighbor{
     int portnum;
     string name;
};



class Router
{
public:
     Router( string name, int port );
     void routeMessage(int destPort, char *message);
     void receiver();
     void updateTable();
	 string vectorToString(int array[]);
	 int *stringToVector(string s);
     // Must Define still
//     char calculateDV();
     
private:
     string m_id;
     int m_port;
     int** m_routeTable;

     neighbor* my_neighbors;
     int n_neighbors;
};

#endif
