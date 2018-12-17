/**
 * @file diccionario.cpp
 * @brief Implementación de los métodos del TDA diccionario
 */
#include "diccionario.h"

using namespace std;

Diccionario::Diccionario(){
    numTerminos = 0;
}

Diccionario::Diccionario(int numT, const Termino *conj){
    if(numT>0){
        numTerminos = numT;
        for(int i=0; i<numT ; i++)
            conjunto.insert(conj[i]);
    }
    else{
        numTerminos = 0;
    }
}

Diccionario::Diccionario(const Diccionario &cp){
    this->numTerminos = cp.numTerminos;
    this->conjunto = cp.conjunto;
}

vector<string> Diccionario::getDefiniciones(string palabra){
    
    bool encontrado=false;
    vector<string> salida;

    set<Termino>::iterator it;

    for(it=conjunto.begin(); it!=conjunto.end() && !encontrado; it++){

        if(palabra == (*it).getPalabra() ){
            salida = (*it).getDefiniciones();
            encontrado=true;
        }
    }

    return salida;
}

set<Termino> Diccionario::getTerminos(){
    return conjunto;
}

int Diccionario::getNumTerminos(){
    return numTerminos;
}

void Diccionario::addTermino(const Termino &t){
    conjunto.insert(t); //Insert por defecto ya los introduce alfabéticamente
    numTerminos++;
}

void Diccionario::quitTermino(const Termino &t){
        
    set<Termino>::iterator it;
    bool acabar = false;

    for(it=conjunto.begin(); it!=conjunto.end() && !acabar; it++)
        if((*it) == t){
            conjunto.erase(*it);
            acabar = true;
        }
}

Diccionario Diccionario::filtradoPorIntervalo(char min, char max){
    Diccionario salida;
    string comparacion;

    set<Termino>::iterator it;

    for(it=conjunto.begin(); it!=conjunto.end() ; it++){
        comparacion = (*it).getPalabra();

        if( comparacion[0]>=min && comparacion[0]<=max )
            salida.addTermino(*it);
    }

    return salida;
}

Diccionario Diccionario::filtradoPorPalabra(string palabra){
    Diccionario salida;
    Termino *taux;
    bool primera;

    set<Termino>::iterator it;

    for(it=conjunto.begin(); it!=conjunto.end() ; it++){
        taux = new Termino;
        primera = true;

        for(int j=0; j<(*it).getNumeroDefiniciones(); j++){
            if( it->getDefinicionPos(j).find(palabra) != (long unsigned int)-1){
                if(primera){
                    taux->setPalabra( (*it).getPalabra() );
                    primera=false;
                }
                taux->nuevaDefinicion( (*it).getDefinicionPos(j) );

            }
        }

        if(!primera)
            salida.addTermino(*taux);
        delete taux;
    }

    return salida;
}

int Diccionario::totalDefiniciones(){
    int suma = 0;

    set<Termino>::iterator it;
    for (it=conjunto.begin(); it!=conjunto.end(); it++)
        suma += (*it).getNumeroDefiniciones();

    return suma;
}

int Diccionario::maxDefinicionesPalabra(){
    int max = 0;

    set<Termino>::iterator it;

    for (it=conjunto.begin(); it!=conjunto.end(); it++)
        if(max < (*it).getNumeroDefiniciones())
            max = (*it).getNumeroDefiniciones();

    return max;
}

double Diccionario::promedioDefiniciones(){
    return totalDefiniciones()/(double)numTerminos;
}
//--------------------------------------------------------
Diccionario::iterator Diccionario::begin(){

    return this->conjunto.begin();

}

Diccionario::const_iterator Diccionario::begin() const{

    return this->conjunto.begin();

}

Diccionario::iterator Diccionario::end(){

    return this->conjunto.end();

}

Diccionario::const_iterator Diccionario::end() const{

    return this->conjunto.end();

}

ostream& operator<< (ostream &os, const Diccionario &dic){
    
    Diccionario::const_iterator it;

    for(it = dic.begin(); it != dic.end(); ++it){
        os << (*it);
    }
    
    return os;
}

istream& operator>> (istream &flujo, Diccionario &dic){
    string aux;
    string anterior = "\0";
    Termino *taux;
    
    getline(flujo, aux, ';');
    do{
        taux = new Termino;

        do{
            if(anterior == "\0" || aux != anterior){
                taux->setPalabra(aux);
                anterior = aux;
                getline(flujo, aux, '\n');
                taux->nuevaDefinicion(aux);
            }
            else{
                getline(flujo, aux, '\n');
                taux->nuevaDefinicion(aux);
            }

            if(!flujo.eof())
                getline(flujo, aux, ';');
        }while(aux == anterior);

        dic.addTermino( *taux );

        delete taux;
        
    }while(!flujo.eof());

    return flujo;
}

