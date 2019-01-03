#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <time.h>
#include "diccionario.h"
#include "letra.h"
#include "conjuntodeletras.h"

using namespace std;

struct CantidadLetras{
    char letra;
    long int frecuenciaAbsoluta;
    long double frecuenciaRelativa;
};

int main(int argc, char *argv[]){

    if(argc != 4){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.- El fichero de diccionario"<<endl;
        cout<<"2.- El fichero con las letras"<<endl;
        cout<<"3.- El fichero donde escribir el conjunto de letras con la cantidad de apariciones calculada"<<endl;

        return 0;
    }

    ifstream dic(argv[1]);
    ifstream ltr(argv[2]);
    ofstream sld(argv[3]);

    Diccionario D;
    ConjuntoDeLetras L;
    vector<CantidadLetras> salida;
    long int total;

    dic>>D;
    ltr>>L;

    ConjuntoDeLetras::const_iterator itL;

    for(itL=L.cbegin(); itL!=L.cend(); ++itL){
        CantidadLetras aux;
        aux.frecuenciaAbsoluta = 0;
        aux.frecuenciaRelativa = 0;
        aux.letra = (*itL).getLetra();

        salida.push_back(aux);
    }

    Diccionario::const_iterator itD;

    for(itD=D.cbegin(); itD!=D.cend(); ++itD){
        string aux = (*itD);
        for(int i=0; i<(int)aux.size(); i++){
            transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
            bool salir = false;
            for(int j=0; j<(int)salida.size() && !salir; j++)
                if(salida[j].letra == aux[i]){
                    salida[j].frecuenciaAbsoluta++;
                    salir=true;
                    total++;
                }
        }
    }

    sld<<"#Letra FAbs. Frel."<<endl;
    for(int i=0; i<(int)salida.size(); i++){
        salida[i].frecuenciaRelativa = (salida[i].frecuenciaAbsoluta*1.0/total)*100;
        sld<<salida[i].letra<<"\t"<<salida[i].frecuenciaAbsoluta<<"\t"<<salida[i].frecuenciaRelativa<<endl;
    }


}