# Makefile para hacer mas automática la ejecución y demás procesos

ejecutarScript: darPermisosScript compilar
	./ejecuciones_ordenacion.csh

darPermisosScript: compilar
	chmod +x ejecuciones_ordenacion.csh

ejecutarPrograma: compilar
	./ejercicio8 200

compilar: ejercicio8.cpp
	g++ ejercicio8.cpp -o ejercicio8

clean:
	rm -R ejercicio8 fit.log