# Makefile para hacer mas automática la ejecución y demás procesos

ejecutarScript: darPermisosScript compilar
	./ejecuciones_ordenacion.csh

darPermisosScript: compilar
	chmod +x ejecuciones_ordenacion.csh

ejecutarPrograma: compilar
	./ejercicio7 200 100

compilar: ejercicio7.cpp
	g++ ejercicio7.cpp -o ejercicio7

clean:
	rm -R ejercicio7 fit.log