CXXFLAGS = -Wall -ansi -g
OBJS = Proj5.o Proj5Aux.o DocumentStore.o Document.o Correspondence.o \
	Memo.o Email.o Report.o TechReport.o BadResponseException.o

Proj5.out: $(OBJS)
	g++ $(OBJS) -lg -o Proj5.out

#
# Dependencies: produced by "g++ -MM"
#
Correspondence.o: Correspondence.cpp Correspondence.h Document.h
Document.o: Document.cpp Document.h
DocumentStore.o: DocumentStore.cpp DocumentStore.h Document.h \
 Correspondence.h Memo.h Email.h Report.h TechReport.h BadResponseException.h
Email.o: Email.cpp Email.h Correspondence.h Document.h
Memo.o: Memo.cpp Memo.h Correspondence.h Document.h
Proj5Aux.o: Proj5Aux.cpp DocumentStore.h Document.h Proj5Aux.h
Proj5.o: Proj5.cpp Proj5Aux.h DocumentStore.h Document.h
Report.o: Report.cpp Report.h Document.h
TechReport.o: TechReport.cpp TechReport.h Report.h Document.h
