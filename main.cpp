#include "headers.h"

//takes in server name, port number, message
int main(int argc, char* argv[])
{
     //making sure there are 2 arguements
     if (argc < 3)
     {
	  perror("Fucking A");
//		usage(argv[0]);//common for when incorrect amount of arguments occur
     }
     RouterSocket sock = RouterSocket(atoi(argv[1]));// port number ,server name
     sock.sendMessage(argv[2]);
     return 0;
}

