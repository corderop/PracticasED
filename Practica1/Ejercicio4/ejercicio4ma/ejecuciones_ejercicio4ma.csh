#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 100
set ejecutable = ./ejercicio4ma/ejercicio4ma
set salida = ./ejercicio4ma/tiempos_algoritmo_ma.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 100000` >> $salida
  @ i += $incremento
end
