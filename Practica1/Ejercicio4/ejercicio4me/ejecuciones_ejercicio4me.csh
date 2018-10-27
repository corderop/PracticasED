#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 100
set ejecutable = ./ejercicio4me/ejercicio4me
set salida = ./ejercicio4me/tiempos_algoritmo_me.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
