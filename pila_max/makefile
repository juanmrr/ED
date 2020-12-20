OBJ=obj
BIN=bin
SRC=src
INC=inc

all: $(BIN)/usoPila_max

clean:
	rm $(BIN)/usoPila_max
	
$(BIN)/usoPila_max: $(SRC)/usoPila_max.cpp
	g++ -o $(BIN)/usoPila_max $(SRC)/usoPila_max.cpp -I $(INC)

documentacion:
	doxygen ./doc/Doxyfile
