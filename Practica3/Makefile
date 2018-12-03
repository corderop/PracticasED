SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************

# Comandos para ejecutar la implementación con vectores dinámicos
ejecutarVD: $(BIN)/pruebacola_max-VD
	./$(BIN)/pruebacola_max_vd

$(BIN)/pruebacola_max-VD : $(OBJ)/pruebacola_max.o-VD
	$(CXX) -o $(BIN)/pruebacola_max_vd $(OBJ)/pruebacola_max.o -I$(INC)

$(OBJ)/pruebacola_max.o-VD : $(SRC)/pruebacola_max.cpp $(INC)/Cola_max_vd.* $(INC)/Cola_max.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp -D CUAL_COMPILA=1

# Comandos para ejecutar la implementación con pilas
ejecutarPILA: $(BIN)/pruebacola_max-PILA
	./$(BIN)/pruebacola_max_pila

$(BIN)/pruebacola_max-PILA : $(OBJ)/pruebacola_max.o-PILA
	$(CXX) -o $(BIN)/pruebacola_max_pila $(OBJ)/pruebacola_max.o -I$(INC)

$(OBJ)/pruebacola_max.o-PILA : $(SRC)/pruebacola_max.cpp $(INC)/Cola_max_pila.* $(INC)/Cola_max.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp -D CUAL_COMPILA=2

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*