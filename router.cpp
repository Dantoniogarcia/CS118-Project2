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

class Router(int portNumber, char **neighbors)
{
	Router(int portNumber, char **neighbors)
	{
		int x = strlen(neighbors);
		int y = strlen(*neighbors);
		dataTable = neighbors;
	}
	void routeMessage(int destPort, char *message)
	{
		Socket s = Socket(destPort);
		s.sendMessage(messge);
	}
	void receiver()
	{
		sockaddr_in si_me, si_other;
		int s;
		assert((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))!=-1);
		int broadcast=1;

		setsockopt(s, SOL_SOCKET, SO_BROADCAST,&broadcast, sizeof broadcast);
		memset(&si_me, 0, sizeof(si_me));
		si_me.sin_family = AF_INET;
		si_me.sin_port = htons(portNumber);
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
	void updateTable()
	char calculateDV();
	private:
		int destPort;
		char dataTable[][];
}
