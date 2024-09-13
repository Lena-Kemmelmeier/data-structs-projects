program: bank_sim.o customer.o event.o
	g++ bank_sim.o customer.o event.o -o bank_sim

bank_sim.o: bank_sim.cpp customer.o arrayQueue.h priorityQueue.h event.o
	g++ -c bank_sim.cpp

customer.o: customer.cpp customer.h
	g++ -c customer.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	rm *.o bank_sim