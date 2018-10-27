#!/bin/csh
@ inicio = 1
@ fin = 700
@ incremento = 1
set ejecutable = ejercicio7
set salida = tiempos_algoritmo.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 100` >> $salida
  @ i += $incremento
end
