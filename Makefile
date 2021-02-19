# Makefile for Writing Make Files Example

# https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
# https://malithjayaweera.com/2020/05/create-makefile/

# *****************************************************
# Variables to control Makefile operation
# verify tabs in bash with command:
#	 cat -e -t -v makefile_name
 
CC = g++
CFLAGS = -Wall -g -std=c++17
APPNAME = LinkedListExample

# ****************************************************
# Targets needed to bring the executable up to date

all: program

list.o:
	$(CC) $(CFLAGS) -c LinkedListExample/List.cpp 

source.o: list.o
	$(CC) $(CFLAGS) -c LinkedListExample/Source.cpp

program: source.o
	$(CC) $(CFLAGS) -o $(APPNAME) source.o list.o

clean:
	rm -f *.o $(OUTFILE)
