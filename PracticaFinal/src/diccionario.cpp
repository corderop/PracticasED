#include "diccionario.h"

Diccionario::Diccionario(){
    datos.clear();
}

int Diccionario::size() const{
    return datos.size();
}

vector<string> Diccionario::PalabrasLongitud(int longitud) const{
    vector<string> salida;

    set<string>::iterator it;

    for(it=datos.begin(); it!=datos.end(); it++)
        if((int)it->size() == longitud)
            salida.push_back(*it);

    return salida;
}

bool Diccionario::Esta(string palabra) const{
    bool salida = false;
    set<string>::const_iterator it;

    transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

    it = datos.find(palabra); // Devuelve el último elemento si no lo encuentra

    // Debemos comprobar por si lo encuentra en el último elemento 
    if(it != datos.end())
        salida = true;

    return salida;
}

bool Diccionario::empty() const{
    return datos.empty();
}

Diccionario Diccionario::crearSubdiccionario(const BolsaLetras &bl) const{
    Diccionario salida;
    bool poder;

    Diccionario::const_iterator it;

    for(it=this->begin(); it!=this->end(); ++it){
        poder = false;
        poder = bl.letrasValidas(*it);
        if(poder)
            salida.datos.insert(*it);
    }

    return salida;
}

// Métodos correspondientes al iterador ----------------------------------------
Diccionario::iterator::iterator(){}

string Diccionario::iterator::operator*(){
    return *it;
}

Diccionario::iterator& Diccionario::iterator::operator++(){
    ++this->it;

    return *this;
}

bool Diccionario::iterator::operator==(const Diccionario::iterator &i){
    bool salida = false;

    if(this->it == i.it)
        salida = true;

    return salida;
}

bool Diccionario::iterator::operator!=(const Diccionario::iterator &i){
    return !( (*this)==i );
}

Diccionario::iterator Diccionario::begin(){
    Diccionario::iterator salida;
    salida.it = this->datos.begin();

    return salida;
}

Diccionario::iterator Diccionario::end(){
    Diccionario::iterator salida;
    salida.it = this->datos.end();

    return salida;
}

// Métodos correspondientes al iterador constante-------------------------------
Diccionario::const_iterator::const_iterator(){}

string Diccionario::const_iterator::operator*(){
    return *it;
}

Diccionario::const_iterator& Diccionario::const_iterator::operator++(){
    //Diccionario::const_iterator *salida = new Diccionario::const_iterator();
    /*salida->it = */++this->it;

    return *this/*salida*/;
}

bool Diccionario::const_iterator::operator==(const Diccionario::const_iterator &i) const{
    bool salida = false;

    if(this->it == i.it)
        salida = true;

    return salida;
}

bool Diccionario::const_iterator::operator!=(const Diccionario::const_iterator &i) const{
    return !( (*this)==i );
}

Diccionario::const_iterator Diccionario::begin() const{
    Diccionario::const_iterator salida;
    salida.it = this->datos.begin();

    return salida;
}

Diccionario::const_iterator Diccionario::end() const{
    Diccionario::const_iterator salida;
    salida.it = this->datos.end();

    return salida;
}

Diccionario::const_iterator Diccionario::cbegin() const{
    Diccionario::const_iterator salida;
    salida.it = this->datos.begin();

    return salida;
}

Diccionario::const_iterator Diccionario::cend() const{
    Diccionario::const_iterator salida;
    salida.it = this->datos.end();

    return salida;
}

istream & operator>>(istream & is,Diccionario &D){
    string aux;
    
    do{
        getline(is, aux, '\n');
        D.datos.insert(aux);
    }while(!is.eof());

    return is;
}

ostream & operator<<(ostream & os, const Diccionario &D){
    Diccionario::const_iterator it;

    for(it = D.begin(); it != D.end(); ++it)
        os<<(*it)<<endl;
    
    return os;
}