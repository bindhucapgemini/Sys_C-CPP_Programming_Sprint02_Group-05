BIN = ../bin
SRC = ../src
INC = ../inc
GCC = g++
CFLAGS = -c
LFLAGS = -o
all:hallticket.o candidate.o examcenter.o main.o
	$(GCC) $(LFLAGS) $(BIN)/ExamCenterAllotment $(BIN)/hallticket.o $(BIN)/candidate.o $(BIN)/examcenter.o $(BIN)/main.o
hallticket.o:$(SRC)/HallTicket.cpp
	$(GCC) $(LFLAGS) $(BIN)/hallticket.o $(CFLAGS) $(SRC)/HallTicket.cpp
candidate.o:$(SRC)/candidate.cpp
	$(GCC) $(LFLAGS) $(BIN)/candidate.o $(CFLAGS) $(SRC)/candidate.cpp
examcenter.o:$(SRC)/ExamCenter.cpp
	$(GCC) $(LFLAGS) $(BIN)/examcenter.o $(CFLAGS) $(SRC)/ExamCenter.cpp
main.o:$(SRC)/main.cpp 
	$(GCC) $(LFLAGS) $(BIN)/main.o $(CFLAGS) $(SRC)/main.cpp 
clean: 
	rm $(BIN)/*.out $(BIN)/*.o
