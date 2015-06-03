#include "headers.h"


//////////////////////////////////////////////////////////////////////
// Function Implementations
//////////////////////////////////////////////////////////////////////

Router::Router(int portNumber, char **neighbors)
{
//     int x = strlen(neighbors);
//     int y = strlen(*neighbors);
//     dataTable = neighbors;
     m_portNumber = portNumber;
}

void Router::routeMessage(int destPort, char *message)
{
     RouterSocket s = RouterSocket(destPort);
     s.sendMessage(message);
}

void Router::receiver()
{
     sockaddr_in si_me, si_other;
     int s;
     assert((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))!=-1);
     int broadcast=1;

     setsockopt(s, SOL_SOCKET, SO_BROADCAST,&broadcast, sizeof broadcast);
     memset(&si_me, 0, sizeof(si_me));
     si_me.sin_family = AF_INET;
     si_me.sin_port = htons( m_portNumber );
     si_me.sin_addr.s_addr = INADDR_ANY;
     assert(::bind(s, (sockaddr *)&si_me, sizeof(sockaddr))!=-1);

     while(1)
     {
	  char buf[2048];
	  socklen_t slen=sizeof(sockaddr);
	  recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr *)&si_other, &slen);
	  printf("recv: %s\n", buf);
	  //delete buf;
	  memset (buf,'\0',sizeof(buf));
	  //routeMessage(
     }
}	





