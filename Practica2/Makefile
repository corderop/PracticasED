SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(SRC)/termino.cpp $(SRC)/diccionario.cpp $(SRC)/pruebadiccionario.cpp datos/diccionario.txt
	g++ -c $(SRC)/termino.cpp -o $(OBJ)/termino.o -Iinclude
	g++ -c $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o -Iinclude
	g++ -c $(SRC)/pruebadiccionario.cpp -o $(OBJ)/pruebadiccionario.o -Iinclude
	g++ $(OBJ)/termino.o $(OBJ)/diccionario.o $(OBJ)/pruebadiccionario.o -o $(BIN)/pruebadiccionario
	./$(BIN)/pruebadiccionario datos/diccionario.txt

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
