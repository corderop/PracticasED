SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

# **** Ejecutar ****
exec:
	./$(BIN)/pruebadiccionario ./datos/diccionario.txt

# **** Compilación de módulos ****
all: $(BIN)/pruebadiccionario

$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(LIB)/libdiccionario.a
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o -I$(INC) -L$(LIB) -ldiccionario

$(LIB)/libdiccionario.a : $(OBJ)/termino.o $(OBJ)/diccionario.o
	ar rvs $(LIB)/libdiccionario.a $(OBJ)/termino.o $(OBJ)/diccionario.o

$(OBJ)/termino.o : $(SRC)/termino.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/termino.o $(SRC)/termino.cpp -I$(INC)

$(OBJ)/diccionario.o : $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp -I$(INC)

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp -I$(INC)

# **** Generación de documentación ******
documentacion:
	doxygen doc/doxys/Doxyfile

# **** Limpieza ****
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ datos/*_P.txt

mrproper : clean
	-rm $(BIN)/* doc/html/*