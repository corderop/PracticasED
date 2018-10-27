# Makefile para hacer mas automática la ejecución y demás procesos

ejecutarScript: darPermisosScript
	./ejecuciones_ejercicio3.csh

darPermisosScript: compilar
	chmod +x ejecuciones_ejercicio3.csh

ejecutarPrograma: compilar
	./ejercicio3 200

compilar: ejercicio3.cpp
	g++ ejercicio3.cpp -o ejercicio3

clean:
	rm -R ejercicio3