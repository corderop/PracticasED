# Makefile para hacer mas automática la ejecución y demás procesos

ejecutarScript: darPermisosScript compilar
	./ejecuciones_ordenacion_6.csh

darPermisosScript: compilar
	chmod +x ejecuciones_ordenacion_6.csh

ejecutarPrograma: compilar
	./ejercicio6 200 100

compilar: ejercicio6.cpp
	g++ -O3 ejercicio6.cpp -o ejercicio6

clean:
	rm -R ejercicio6 fit.log