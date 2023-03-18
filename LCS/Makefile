all: driver.o LCS.o
	g++ -Wall driver.o LCS.o -o drive
LCS.o: LCS.cpp
	g++ -Wall -c LCS.cpp
Driver.o: Driver.cpp
	g++ -Wall -c driver.cpp
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch*#
run:
	./drive $(FILE1) $(size1) $(FILE2) $(size2)