#include "headers.h"
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Router Type
//////////////////////////////////////////////////////////////////////


Router::Router( char name, int port )
{
     m_id = name;

     m_routeTable = new int*[6];
     for ( int i = 0; i < 6; i++ )
     {
	  m_routeTable[i] = new int[6];
	  for ( int j = 0; j < 6; j++ )
	       m_routeTable[i][j] = INT_MAX;
     }

     my_neighbors = new neighbor[6];
     n_neighbors = 0;
}

void Router::initVars( string filename )
{
     ifstream file;
     file.open( "test.txt" );
     string line;

     while( !file.eof() )
     {
	  getline(file, line); 
	  if ( line[0] == m_id )
	  {
	       // initialize neighbors
	       my_neighbors[n_neighbors].name = line[2];
	       int tmp = 0;
	       for ( int i = 4; line[i] != ','; i++ )
	       {
		    tmp *= 10;
		    tmp += (line[i] - '0');
	       }
	       my_neighbors[n_neighbors].portnum = tmp;
	       n_neighbors++;


	       // initialize Routing Table
	       int count = 0;
	       tmp = 0;
	       for ( int i = 0; i < line.size(); i++ )
	       {
		    if ( count == 3 )
			 for ( int j = i; j < line.size(); j++ )
			 {
			      tmp *= 10;
			      tmp += (line[i] - '0');
			 }
		    
		    if ( line[i] == ',' )
			 count++; 
	       }
	       m_routeTable[line[0]-'A'][line[2]-'A'] = tmp;
	       m_routeTable[line[0]-'A'][line[0]-'A'] = 0;
	  }


     }

     
     for ( int i = 0; i < n_neighbors; i++ )
	  cout << my_neighbors[i].name << my_neighbors[i].portnum  << endl; 

     for ( int i = 0; i < 6; i++ )
     {
	  for ( int j = 0; j < 6; j++ )
	       if ( m_routeTable[i][j] == INT_MAX )
		    cout << "i" << ' ';
	       else
		    cout << m_routeTable[i][j] << ' '; 
	  cout << endl;
     }

     file.close();
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
     si_me.sin_port = htons( 0 ); // needs to be a client port number
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



