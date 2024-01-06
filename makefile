CC = g++
CFLAGS = -std=c++11

all: hw2

hw2: main.o KmerTree.o BST.o BSTNode.o
	$(CC) $(CFLAGS) main.o KmerTree.o BST.o BSTNode.o -o hw2

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

KmerTree.o: KmerTree.cpp KmerTree.h
	$(CC) $(CFLAGS) -c KmerTree.cpp

BST.o: BST.cpp BST.h
	$(CC) $(CFLAGS) -c BST.cpp

BSTNode.o: BSTNode.cpp BSTNode.h
	$(CC) $(CFLAGS) -c BSTNode.cpp

clean:
	rm -rf *.o hw2