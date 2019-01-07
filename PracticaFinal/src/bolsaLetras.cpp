#include "bolsaLetras.h"

using namespace std;

BolsaLetras::BolsaLetras(){}

void BolsaLetras::addElemento(char L){
    letras.push_back(L);
}

bool BolsaLetras::eliminarLetra(char L){
    bool salida = false;

    for(int i=0; i<(int)letras.size() && !salida; ++i){
        salida = (letras[i] == L);
        if(salida)
            letras.erase(letras.begin()+i);
    }

    return salida;
}

bool BolsaLetras::letrasValidas(string palabra) const{
    BolsaLetras copia = (*this);
    bool valida = true;

    transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
    // Si alguna no es valida se sale del bucle
    for(int i=0; i<(int)palabra.size() && valida; i++){
        valida = copia.eliminarLetra(palabra[i]);
    }
    
    return valida;
}