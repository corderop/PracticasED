SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

# **** Ejecutar ****
exec_diccionario: comp_diccionario
	./$(BIN)/testdiccionario ./datos/diccionario1.txt

exec_letras_L: comp_letras
	./$(BIN)/letras datos/spanish.txt datos/letras.txt 8 L

exec_letras_P: comp_letras
	./$(BIN)/letras datos/spanish.txt datos/letras.txt 8 P

exec_cantidad_letras: comp_cantidad_letras
	./$(BIN)/cantidad_letras datos/spanish.txt datos/letras.txt datos/salida.txt

# **** Compilación de módulos ****

comp_all: comp_diccionario comp_letras comp_cantidad_letras

## Diccionario 		***********************************************
comp_diccionario: $(BIN)/testdiccionario

$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(LIB)/libjuego.a
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o  -L$(LIB) -ljuego

$(OBJ)/testdiccionario.o : $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp 

## Letras 			***********************************************
comp_letras: $(BIN)/letras

$(BIN)/letras: $(OBJ)/letras.o $(LIB)/libjuego.a
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o  -L$(LIB) -ljuego

$(OBJ)/letras.o : $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letras.o $(SRC)/letras.cpp 

## Cantidad letras 	***********************************************

comp_cantidad_letras: $(BIN)/cantidad_letras

$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(LIB)/libjuego.a
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o  -L$(LIB) -ljuego

$(OBJ)/cantidad_letras.o : $(SRC)/cantidad_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp 

## Crear librerias 	***********************************************

$(LIB)/libjuego.a : $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjuntodeletras.o $(OBJ)/bolsaLetras.o
	ar rvs $(LIB)/libjuego.a $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjuntodeletras.o $(OBJ)/bolsaLetras.o

$(OBJ)/letra.o : $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letra.o $(SRC)/letra.cpp 

$(OBJ)/conjuntodeletras.o : $(SRC)/conjuntodeletras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/conjuntodeletras.o $(SRC)/conjuntodeletras.cpp 

$(OBJ)/bolsaLetras.o : $(SRC)/bolsaLetras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/bolsaLetras.o $(SRC)/bolsaLetras.cpp 

$(OBJ)/diccionario.o : $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp 

# **** Generación de documentación ******
documentacion:
	doxygen doc/doxys/Doxyfile

# **** Limpieza ****
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ datos/*_P.txt

mrproper : clean
	-rm $(BIN)/* doc/html/*