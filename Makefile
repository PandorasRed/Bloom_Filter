CPP=g++
EXE=main
SRC=src/
INC=./include
CFLAGS= -g -Wall -I $(INC)

all: $(EXE)

readFastaFile.o: $(SRC)readFastaFile.cpp
			$(CPP) -o readFastaFile.o -c $(SRC)readFastaFile.cpp $(CFLAGS)
main.o: $(SRC)main.cpp
			$(CPP) -o main.o -c $(SRC)main.cpp $(CFLAGS)
main: main.o readFastaFile.o 
			$(CPP) -o main main.o $(CFLAGS)
clean:
	rm -f *.o main