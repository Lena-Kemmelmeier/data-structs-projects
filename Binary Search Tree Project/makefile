tree: main.o
	g++ -std=c++17 -o tree main.o
main.o: main.cpp linkedtreenode.h linkedBinaryTree.h linkedBinarySearchTree.h
	g++ -std=c++17 -c main.cpp
clean:
	rm *.o tree *.txt