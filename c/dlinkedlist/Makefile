
all: dlinkedlist

dlinkedlist: main.c dlinkedlist.o
	gcc -o dlinkedlist -Wall -g main.c dlinkedlist.o

dlinkedlist.o: dlinkedlist.c dlinkedlist.h
	gcc -Wall -g -c -o dlinkedlist.o dlinkedlist.c


