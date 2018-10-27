/**
 * Pablo Cordero Romero
 * Francisco Beltrán Sánchez
 */
#include "termino.h"

using namespace std;

Termino::Termino(){

    palabra="\0";
    num_def=0;
    definiciones=new string [num_def];

}

Termino::Termino(string pal, string* def, int numero){

    palabra=pal;
    num_def=numero;

    definiciones=new string [num_def];

    for(int i=0; i<num_def; i++){

        definiciones[i]=def[i];

    }

}

Termino::Termino(const Termino& ter){

    palabra=ter.palabra;
    num_def=ter.num_def;
    definiciones=new string[num_def];

    for(int i=0; i<num_def; i++){

        definiciones[i]=ter.definiciones[i];

    }

}

string Termino::getPalabra() const{

    return palabra;

}

void Termino::setPalabra(string pal){    
    palabra=pal;
}

string* Termino::getDefiniciones(){

    return definiciones;

}

string Termino::getDefinicionPos(int pos){
    return definiciones[pos];
}

void Termino::nuevaDefinicion(string def){
    string* aux=new string [num_def];
    
    for(int i=0; i<num_def ; i++)
        aux[i]=definiciones[i];
    num_def++;

    delete [] definiciones;
    definiciones = new string [num_def];

    for(int i=0; i<num_def-1 ; i++)
        definiciones[i] = aux[i];
    definiciones[num_def-1] = def;

    delete [] aux;
}

int Termino::getNumeroDefiniciones(){

    return num_def;

}
