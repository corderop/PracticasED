#include "letra.h"

Letra::Letra(){
    letra = '\0';
    cantidad = 0;
    puntos = 0;
}

Letra::Letra(char ltr, int cntdd, int pnts){
    letra = ltr;
    if(cntdd>0)
        cantidad = cntdd;
    else
        cantidad = 0;
    if(pnts>0)
        puntos = pnts;
    else
        puntos = 0;
}

char Letra::getLetra() const{
    return this->letra;
}

int Letra::getCantidad() const{
    return this->cantidad;
}

int Letra::getPuntos() const{
    return this->puntos;
}

bool Letra::operator<(Letra const& ot) const{
    return this->letra<ot.letra;
}

istream & operator>>(istream & is, Letra& lt){
    string auxS;
    char auxC;
    int auxI1;
    int auxI2;

    getline(is,auxS,'\t');
    auxC = auxS[0];
    if(auxC>='a' && auxC<='z')
        auxC -= 32;
    lt.letra = auxC;

    getline(is,auxS, '\t');
    auxI1 = stoi(auxS,0,10);
    lt.cantidad = auxI1;

    getline(is,auxS, '\n');
    auxI2 = stoi(auxS,0,10);
    lt.puntos = auxI2;

    return is;
}

ostream & operator<<(ostream & os, const Letra &lt){
    os << lt.letra << '\t' << lt.cantidad << '\t' << lt.puntos << '\n';

    return os;
}