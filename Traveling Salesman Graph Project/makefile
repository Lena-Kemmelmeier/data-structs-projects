salesman: salesman.o path.o
	g++ -std=c++17 -o salesman salesman.o path.o
salesman.o: salesman.cpp matrixGraph.h arrayList.h path.h
	g++ -std=c++17 -c salesman.cpp
path.o: path.cpp path.h arrayList.h
	g++ -std=c++17 -c path.cpp
clean:
	rm *.o salesman