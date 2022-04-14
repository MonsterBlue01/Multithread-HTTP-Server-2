#------------------------------------------------------------------------------
#  Makefile for CSE 101 Programming Assignment 3
#
#  make                     makes FindPath
#  make GraphClient         makes GraphClient
#  make clean               removes binaries
#  make checkFind           tests FindPath for memory leaks on in7
#  make checkClient         tests GraphClient for memory leaks
#------------------------------------------------------------------------------

BASE_SOURCES   = Graph.c List.c
BASE_OBJECTS   = Graph.o List.o
HEADERS        = Graph.h List.h
COMPILE        = gcc -std=c17 -Wall -c -g
LINK           = gcc -std=c17 -Wall -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full

FindComponents : FindComponents.o $(BASE_OBJECTS)
	gcc -std=c17 -Wall -o FindComponents FindComponents.o $(BASE_OBJECTS)

GraphClient : GraphClient.o $(BASE_OBJECTS)
	$(LINK) GraphClient GraphClient.o $(BASE_OBJECTS)

ModelGraphTest : ModelGraphTest.o $(BASE_OBJECTS)
	$(LINK) ModelGraphTest ModelGraphTest.o $(BASE_OBJECTS)

GraphTest : GraphTest.o $(BASE_OBJECTS)
	$(LINK) GraphTest GraphTest.o $(BASE_OBJECTS)

FindComponents.o : FindComponents.c $(HEADERS)
	gcc -std=c17 -Wall -c -g FindComponents.c

GraphClient.o : GraphClient.c $(HEADERS)
	$(COMPILE) GraphClient.c

ModelGraphTest.o : ModelGraphTest.c $(HEADERS)
	$(COMPILE) ModelGraphTest.c

GraphTest.o : GraphTest.c $(HEADERS)
	$(COMPILE) GraphTest.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE) FindPath GraphClient GraphTest GraphTest.o FindPath.o GraphClient.o $(BASE_OBJECTS)

checkFind : FindPath
	$(MEMCHECK) FindPath in7 junk7

checkClient : GraphClient
	$(MEMCHECK) GraphClient