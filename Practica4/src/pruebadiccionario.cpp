/**
 * @file pruebadiccionario.cpp
 * @brief Archivo de prueba de diccionario
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
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
  Diccionario 
      mi_diccionario,
      terminosEntreCaracteres,
      terminosAsociadosAPalabra;
  vector<string>
      definicionesAsociadasAPalabra;
  ofstream 
      salida;

  f>>mi_diccionario; //Cargamos en memoria el diccionario
   
  // Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
  // - Obtener las definiciones asociadas a una palabra 
  salida.open("datos/definicionesAsociadasAPalabra_P.txt");
  string palabra = "abel";  

  definicionesAsociadasAPalabra = mi_diccionario.getDefiniciones(palabra);
  salida<<palabra<<endl;

  vector<string>::const_iterator it;
  for(it=definicionesAsociadasAPalabra.begin(); it != definicionesAsociadasAPalabra.end() ; it++){
    salida<<(*it)<<endl;
  }

  salida.close();

  // - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
  salida.open("datos/terminosEntreCaracteres_P.txt");

  terminosEntreCaracteres = mi_diccionario.filtradoPorIntervalo('a','c');
  salida<<terminosEntreCaracteres;

  salida.close();

  // - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
  salida.open("datos/terminosAsociadosAPalabra_P.txt");

  terminosAsociadosAPalabra = mi_diccionario.filtradoPorPalabra("color");
  salida<<terminosAsociadosAPalabra;

  salida.close();
  // - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
  cout<<"\nNUMERO TOTAL DE DEFINICIONES: "<<mi_diccionario.totalDefiniciones();
  cout<<"\nMÁXIMO DEFINCIONES ASOCIADAS A UNA PALABRA: "<<mi_diccionario.maxDefinicionesPalabra();
  cout<<"\nPROMEDIO DEFINICIONES POR PALABRA: "<<mi_diccionario.promedioDefiniciones()<<endl<<endl;
}
