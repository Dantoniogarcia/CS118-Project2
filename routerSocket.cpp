#include "headers.h"

//////////////////////////////////////////////////////////////////////
// Function Implementations
//////////////////////////////////////////////////////////////////////

RouterSocket::RouterSocket(int port)
{
     // creating socket
     s = socket(PF_INET, SOCK_DGRAM,0);
     if(s<0)
     {
	  perror("Socket not created");
     }
     //filling in server information
     cAddr.sin_family = AF_INET;
     cAddr.sin_addr.s_addr = INADDR_ANY;
     cAddr.sin_port = htons(port); //since it is the client the OS can choose the port
     //binding the socket to a port
     if(bind(s, (struct sockaddr *)&cAddr, sizeof(cAddr))<0)
     {
	  perror("Did not Bind");
     }
     //server data
     memset((char*) &sAddr, 0, sizeof(sockaddr)); //allocating memory
     sAddr.sin_family = AF_INET;
     sAddr.sin_port = htons(port);
     //setting up host info
}

int RouterSocket::sendMessage(const char *message)
{
     int numByteSent = 0;
     //unrealiable sending of information
     numByteSent = sendto(s,message,strlen(message), 0, (struct sockaddr *)&sAddr, sizeof(sAddr));
     if(numByteSent < 0)
     {
	  perror("Message Not Sent");
     }
     printf("%d", numByteSent);
}


