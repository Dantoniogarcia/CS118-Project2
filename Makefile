CC = g++
FLAGS = -c
LIBS = 
SOURCES = main.cpp routerSocket.cpp router.cpp
HEADERS = headers.h router.h routerSocket.h
OBJECTS = $(SOURCES:.cpp=.o)

all: DV

DV: $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@ 

routerSocket.o: routerSocket.cpp routerSocket.h headers.h
	$(CC) $(FLAGS) routerSocket.cpp $(LIBS)

router.o: router.cpp router.h headers.h routerSocket.cpp routerSocket.h
	$(CC) $(FLAGS) router.cpp $(LIBS)

main.o: router.cpp router.h routerSocket.cpp routerSocket.h headers.h
	$(CC) $(FLAGS) main.cpp $(LIBS)

clean: 
	rm -rf *o *~ DV
