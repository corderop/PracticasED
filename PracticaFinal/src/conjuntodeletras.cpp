#include "conjuntodeletras.h"

ConjuntoDeLetras::ConjuntoDeLetras(){}

int ConjuntoDeLetras::getTamano() const{
    return this->letras.size();
}

int ConjuntoDeLetras::getPuntuacion(char letra) const{
    int salida = 0;
    set<Letra>::iterator it;
    bool salir = false;
    letra = toupper(letra);

    for(it = letras.begin() ; it!=letras.end() && !salir; ++it)
        if(it->getLetra() == letra)
            salida = it->getPuntos();

    return salida;
}

void ConjuntoDeLetras::addLetra(const Letra &lt){
    this->letras.insert(lt);
}

void ConjuntoDeLetras::eliminarLetra(char letra){
    set<Letra>::iterator it;
    bool salir = false;
    letra = toupper(letra);

    for(it = letras.begin() ; it!=letras.end() && !salir; ++it)
        if((*it).getLetra() == letra){
            letras.erase(it);
            salir = true;
        }
}

bool ConjuntoDeLetras::estaLetra(char L) const{
    bool esta = false;
    set<Letra>::iterator it;

    for(it=this->letras.begin(); it!=this->letras.end() && !esta; it++)
        esta = ( (*it).getLetra() == L );
        
    return esta;
}

BolsaLetras ConjuntoDeLetras::generarLetras(int num) const{
    BolsaLetras salida;
    int posiciones[this->getTamano()] = {0}; // Hecho para elegir las posiciones de las letras aleatorias a coger
    ConjuntoDeLetras::const_iterator it;
    int aux;

    do{
        it = this->begin();
        aux = rand() % (this->getTamano()-1);
        it += aux;

        posiciones[aux]++;
        if(posiciones[aux] <= (*it).getCantidad()){
            salida.addElemento((*it).getLetra());
            cout<<(*it).getLetra()<<"  ";

            num--;
        }

    }while(num > 0);

    return salida;
}

int ConjuntoDeLetras::calcularPuntuacion(string palabra, char tipo) const{
    int puntuacion = 0;

    if(tipo == 'P')
        for(int i=0; i<(int)palabra.size(); i++)
            puntuacion += getPuntuacion(palabra[i]);
    else if(tipo == 'L')
        puntuacion = (int)palabra.size();

    return puntuacion;
}

istream & operator>>(istream & is, ConjuntoDeLetras& cj){
    string aux;
    Letra lt;

    getline(is, aux, '\n');
    while(!is.eof()){
        is>>lt;
        cj.letras.insert(lt);
    }

    return is;
}

ostream & operator<<(ostream & os, const ConjuntoDeLetras &cj){

    os << "#Letra Cantidad Puntos\n";

    set<Letra>::iterator it;

    for(it=cj.letras.begin(); it!=cj.letras.end(); it++)
        os << *it;

    return os;
}

// Métodos correspondientes al iterator ------------------------------------
ConjuntoDeLetras::iterator::iterator(){}

Letra ConjuntoDeLetras::iterator::operator*(){
    return *it;
}

ConjuntoDeLetras::iterator& ConjuntoDeLetras::iterator::operator++(){
    ++this->it;
    
    return *this;
}

ConjuntoDeLetras::iterator& ConjuntoDeLetras::iterator::operator+=(int num){
    for(int i=0; i<num; i++)
       ++this->it;
    
    return *this;
}

bool ConjuntoDeLetras::iterator::operator==(const ConjuntoDeLetras::iterator &i){
    bool salida = false;

    if(this->it == i.it)
        salida = true;

    return salida;
}

bool ConjuntoDeLetras::iterator::operator!=(const ConjuntoDeLetras::iterator &i){
    return !( (*this)==i );
}

ConjuntoDeLetras::iterator ConjuntoDeLetras::begin(){
    ConjuntoDeLetras::iterator salida;
    salida.it = this->letras.begin();

    return salida;
}

ConjuntoDeLetras::iterator ConjuntoDeLetras::end(){
    ConjuntoDeLetras::iterator salida;
    salida.it = this->letras.end();

    return salida;
}

// Métodos correspondientes al const_iterator ------------------------------------
ConjuntoDeLetras::const_iterator::const_iterator(){}

Letra ConjuntoDeLetras::const_iterator::operator*(){
    return *it;
}

ConjuntoDeLetras::const_iterator& ConjuntoDeLetras::const_iterator::operator++(){
    ConjuntoDeLetras::const_iterator *salida = new ConjuntoDeLetras::const_iterator();
    salida->it = ++this->it;
    
    return *salida;
}

ConjuntoDeLetras::const_iterator& ConjuntoDeLetras::const_iterator::operator+=(int num){
    ConjuntoDeLetras::const_iterator *salida = new ConjuntoDeLetras::const_iterator();
    
    for(int i=0; i<num; i++)
        salida->it = ++this->it;
    
    return *salida;
}

bool ConjuntoDeLetras::const_iterator::operator==(const ConjuntoDeLetras::const_iterator &i) const{
    bool salida = false;

    if(this->it == i.it)
        salida = true;

    return salida;
}

bool ConjuntoDeLetras::const_iterator::operator!=(const ConjuntoDeLetras::const_iterator &i) const{
    return !( (*this)==i );
}

ConjuntoDeLetras::const_iterator ConjuntoDeLetras::begin() const{
    ConjuntoDeLetras::const_iterator salida;
    salida.it = this->letras.begin();

    return salida;
}

ConjuntoDeLetras::const_iterator ConjuntoDeLetras::end() const{
    ConjuntoDeLetras::const_iterator salida;
    salida.it = this->letras.end();

    return salida;
}

ConjuntoDeLetras::const_iterator ConjuntoDeLetras::cbegin() const{
    ConjuntoDeLetras::const_iterator salida;
    salida.it = this->letras.begin();

    return salida;
}

ConjuntoDeLetras::const_iterator ConjuntoDeLetras::cend() const{
    ConjuntoDeLetras::const_iterator salida;
    salida.it = this->letras.end();

    return salida;
}