#include "headers.h"
using namespace std;
//takes in server name, port number, message
int main(int argc, char* argv[])
{
     /*
     //making sure there are 2 arguements
     if (argc < 3)
     {
	  perror("A");
//		usage(argv[0]);//common for when incorrect amount of arguments occur
     }

     RouterSocket sock = RouterSocket(atoi(argv[1]));// port number ,server name

     sock.sendMessage(argv[2]);
     */

     Router* A = new Router('A', 10000);
     A-> initVars("test.txt");

     Router* B = new Router('B', 10001);
     B-> initVars("test.txt");

     Router* C = new Router('C', 10002);
     C-> initVars("test.txt");
     
     Router* D = new Router('D', 10003);
     D-> initVars("test.txt");

     Router* E = new Router('E', 10004);
     E-> initVars("test.txt");

     Router* F = new Router('F', 10005);
     F-> initVars("test.txt");

     A-> printState();
     B-> printState();
     C-> printState();
     D-> printState();
     E-> printState();
     F-> printState();

     char* a = new char[1];
     a[0] = 'H';
/*     
     RouterSocket sock = RouterSocket(10000);
     sock.sendMessage(a);

     A->receiver();
*/   
     return 0;
}

