#ifndef HEADERS
#define HEADERS

class Router;
class RouterSocket;

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <assert.h>
#include <climits>

#include <fstream>
#include <cstring>
#include <errno.h>
#include <unistd.h> // close()
#include <netdb.h> // gethostbyname()
#include <sys/time.h> // timeval
#include <fcntl.h> // fcntl()


#include "router.h"
#include "routerSocket.h"
#include "router.cpp"
#include "routerSocket.cpp"
using namespace std;


#endif
