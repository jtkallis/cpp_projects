CXXFLAGS = -Wall -ansi -g
OBJS = driver1.cpp CBofCB.cpp CBofCB.h InnerCB.cpp InnerCB.h

all:
	g++ $(CXXFLAGS) $(OBJS) -o driver
        
run:
	./driver $(MIN) $(MAX) $(SIZE) $(SEED)
        
clean:
	rm results.txt 
	rm driver 
	