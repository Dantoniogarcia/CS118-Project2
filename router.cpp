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
			      tmp += (line[j] - '0');
			 }
		    
		    if ( line[i] == ',' )
			 count++; 
	       }
	       m_routeTable[line[0]-'A'][line[2]-'A'] = tmp;
	       m_routeTable[line[0]-'A'][line[0]-'A'] = 0;
	  }


     }

     file.close();
}

void Router::printState()
{
     for ( int i = 0; i < n_neighbors; i++ )
	  cout << my_neighbors[i].name << ' '
	       << my_neighbors[i].portnum << endl;


     for ( int i = 0; i < 6; i++ )
     {
	  for ( int j = 0; j < 6; j++ )
	       if ( m_routeTable[i][j] == INT_MAX )
		    cout << "i" << ' ';
	       else
		    cout << m_routeTable[i][j] << ' '; 
	  cout << endl;
     }
}

int nodeNumber(char nodeName)
{
	switch(nodeName)
	{
	case 'A': return 0;
		break;
	case 'B': return 1;
		break;
	case 'C': return 2;
		break;
	case 'D': return 3;
		break;
	case 'E': return 4;
		break;
	case 'F': return 5;
		break;
	}

}
/*
void calcDV()
{
	nodeNumber(m_id);

	if(no data for node, and data available for node, update)
	if(distance to neighbor + DV from neighbor to node < current DV to node, update)
	find out which neighbor has lowest cost to destination, send to that one.  

	int destNode = nodeNumber(node);
	int shortest = 9999999;
	int closestNeigh;
	for(int x =1; x< n_neighbors; x++)
	{
	if(data_table[nodeNumber(my_neighbors[x].name)][destNode] < shortest)
		shortest = data_table[nodeNumber(my_neighbors[x].name)][destNode];
		closestNeigh=x;
	}
	routeMessage(my_neighbors[closestNeigh].portnum, "send this whatever");
}
*/
/*
void updateTable(int row, int column, int value)
{

}*/
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


string Router::vectorToString(int array[])
{
  string s;
  int ii =0;
  for(int i =0; i< 6; i++)
  {
    s += array[i] + '0';
    ii= i+1;
    if(i ==5)
	break;
    s += ',';
  }
  return s;
}

int * Router::stringToVector(string s)
{
  int *array = new int[6];
  int ii = 0;
  array[0] = s[0] - '0';
  array[1] = s[2] - '0';
  array[2] = s[4] - '0';
  array[3] = s[6] - '0';
  array[4] = s[8] - '0';
  array[5] = s[10] - '0'; 
  return array;

}

