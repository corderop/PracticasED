/**
 * Pablo Cordero Romero
 * Francisco Beltrán Sánchez
 */
#include "diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   ofstream s1("mi_diccionario2");
   ofstream s2("mi_diccionario3");
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario, mi_diccionario2, mi_diccionario3;
   string* definicionesPalabra;
   int numTotalDef, maxDefPal;
   double promDef;

   f>>mi_diccionario; //Cargamos en memoria el diccionario  

   // - Obtener las definiciones asociadas a una palabra
   definicionesPalabra = mi_diccionario.getDefiniciones(1);

   // - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
   mi_diccionario2 = mi_diccionario.filtradoPorIntervalo('b', 'r');
   s1<<mi_diccionario2;
   
   // - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de termidnos asociados a "color"   
   mi_diccionario3 = mi_diccionario.filtradoPorPalabra("color");
   s2<<mi_diccionario3;

   // - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
   numTotalDef = mi_diccionario.totalDefiniciones();
   maxDefPal = mi_diccionario.maxDefinicionesPalabra();
   promDef = mi_diccionario.promedioDefiniciones();
   cout<<endl<<"Numero total definiciones = "<<numTotalDef<<endl<<"Máximo de definiciones por una palabra = "<<maxDefPal<<endl<<"Promedio de definiciones por palabra = "<<promDef<<endl;
}
