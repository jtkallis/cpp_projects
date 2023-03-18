all: Driver.o HashAndCompare.o
	g++ -Wall Driver.o HashAndCompare.o -o driver.out
HashAndCompare.o: HashAndCompare.cpp
	g++ -Wall -c HashAndCompare.cpp
Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp
clean:
	rm -rf *.o
	rm -f *.out

run:
	./driver.out $(DIR)