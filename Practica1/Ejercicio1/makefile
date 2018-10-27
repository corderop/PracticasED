# Makefile para hacer mas automática la ejecución y demás procesos

ejecutarScript: darPermisosScript compilar
	./ejecuciones_ordenacion.csh

darPermisosScript: compilar
	chmod +x ejecuciones_ordenacion.csh

ejecutarPrograma: compilar
	./ejercicio1 200 100

compilar: ejercicio1.cpp
	g++ ejercicio1.cpp -o ejercicio1

clean:
	rm -R ejercicio1 fit.log