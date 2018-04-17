#File: Makefile
#Author: Josh Freeman

#Make file for Binary_Search_Tree assignment

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Target
TARGET=a.out

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

all: $(TARGET)

$(TARGET): driver.o node.o binary_search_tree.o
	$(CC) driver.o  node.o binary_search_tree.o -o $(TARGET)

driver.o: driver.cpp  node.h binary_search_tree.h
	$(CC) $(CFLAGS) driver.cpp

binary_search_tree.o:  binary_search_tree.cpp  binary_search_tree.h
	$(CC) $(CFLAGS) binary_search_tree.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) node.cpp

clean:
	rm *.o *~ $(TARGET)



