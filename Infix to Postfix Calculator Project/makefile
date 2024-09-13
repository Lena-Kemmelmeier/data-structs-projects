postfix: postfix.o
	g++ postfix.o -o postfix
postfix.o: postfix.cpp arrayStack.h linkedStack.h
	g++ -c postfix.cpp
clean:
	rm *.o postfix