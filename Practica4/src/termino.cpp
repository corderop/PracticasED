/**
 * @file termino.cpp
 * @brief Implementación de los métodos del TDA termino
 */
#include "termino.h"

using namespace std;

Termino::Termino(){

    num_def=0;
    term.first="\0";
    term.second.reserve(num_def);

}

Termino::Termino(string pal, string* def, int numero){

    term.first=pal;
    if(numero >= 0){
        num_def=numero;

        term.second.reserve(num_def);

        for(int i=0; i<num_def; i++){

            term.second.push_back(def[i]);

        }
    }
    else{
        num_def = 0;
        term.second.reserve(num_def);
    }
}

Termino::Termino(const Termino& ter){

    term.first=ter.term.first;
    num_def=ter.num_def;
    term.second = ter.term.second;    
}

string Termino::getPalabra() const{
    return term.first;
}

vector<string> Termino::getDefiniciones() const{
    return term.second;
}

int Termino::getNumeroDefiniciones()const{
    return num_def;
}

string Termino::getDefinicionPos(int pos) const{
     return term.second[pos];
}


void Termino::setPalabra(string pal){    
    term.first=pal;
}

void Termino::nuevaDefinicion(string def){
    term.second.push_back(def);
    num_def++;
}

Termino::iterator Termino::begin(){
    return this->term.second.begin();
}

Termino::const_iterator Termino::begin() const{
    return this->term.second.begin();
}

Termino::iterator Termino::end(){
    return this->term.second.end();
}

Termino::const_iterator Termino::end() const{
    return this->term.second.end();
}

bool Termino::operator<(Termino const& ot) const{
    return this->term.first < ot.term.first;
}

ostream& operator<< (ostream & os, const Termino & t){
    
    Termino::const_iterator it;
    
    for(it = t.begin(); it != t.end(); ++it){
        os << t.term.first <<";"<< (*it) << endl;
    }

    return os;

}

bool operator==(const Termino &uno, const Termino &dos){
    bool igual = false;

    if( uno.num_def == dos.num_def && uno.term.first == dos.term.first && uno.term.second == dos.term.second )
        igual = true;
        
    return igual;
}