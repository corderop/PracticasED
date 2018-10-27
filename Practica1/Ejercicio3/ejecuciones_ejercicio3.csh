#!/bin/csh
@ inicio = 1
@ fin = 30000
@ incremento = 1
set ejecutable = ejercicio3
set salida = tiempos_algoritmo.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
