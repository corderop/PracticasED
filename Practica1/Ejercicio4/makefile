# Makefile para hacer mas automática la ejecución y demás procesos

# Comandos para el mejor caso del algoritmo
ejecutarScriptme: darPermisosScriptme
	./ejercicio4me/ejecuciones_ejercicio4me.csh

darPermisosScriptme: compilarme
	chmod +x ./ejercicio4me/ejecuciones_ejercicio4me.csh

ejecutarProgramame: compilarme
	./ejercicio4me/ejercicio4me 200 100000

compilarme: ./ejercicio4me/ejercicio4me.cpp
	g++ ./ejercicio4me/ejercicio4me.cpp -o ./ejercicio4me/ejercicio4me

# Comandos para el peor caso del algoritmo
ejecutarScriptma: darPermisosScriptma
	./ejercicio4ma/ejecuciones_ejercicio4ma.csh

darPermisosScriptma: compilarma
	chmod +x ./ejercicio4ma/ejecuciones_ejercicio4ma.csh

ejecutarProgramama: compilarma
	./ejercicio4ma/ejercicio4ma 200 100000

compilarma: ./ejercicio4ma/ejercicio4ma.cpp
	g++ ./ejercicio4ma/ejercicio4ma.cpp -o ./ejercicio4ma/ejercicio4ma

# Limpiador de los ejecutables de la carpeta
clean:
	rm -R ./ejercicio4me/ejercicio4me
	rm -R ./ejercicio4ma/ejercicio4ma