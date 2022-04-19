#------------------------------------------------------------------------------
#  Makefile for CSE 101 Programming Assignment 4
#
#  make                     makes FindComponents
#  make ListTest         	makes ListTest
#  make clean               removes binaries
#  make checkFind           tests FindComponents for memory leaks on in7
#  make checkClient         tests GraphClient for memory leaks
#------------------------------------------------------------------------------

ListTest: ListTest.o List.o
	gcc -std=c17 -Wall -o ListTest ListTest.o List.o

ListTest.o : ListTest.c List.h
	gcc -std=c17 -Wall -c ListTest.c -g

List.o : List.c List.h
	gcc -std=c17 -Wall -c List.c

clean :
	rm -f Lex ListTest ListTest.o List.o