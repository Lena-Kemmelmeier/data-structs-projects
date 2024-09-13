move: driver.o person.o cargo.o
	g++ -o move driver.o person.o cargo.o
driver.o: driver.cpp person.h transporter.h train.h bus.h cargo.h
	g++ -c driver.cpp
person.o: person.h person.cpp
	g++ -c person.cpp
cargo.o: cargo.h cargo.cpp
	g++ -c cargo.cpp
clean:
	rm *.o move