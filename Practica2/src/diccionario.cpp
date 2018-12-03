/**
 * Pablo Cordero Romero
 * Francisco Beltrán Sánchez
 */
#include "diccionario.h"

using namespace std;

Diccionario::Diccionario(){
    numTerminos = 0;
    conjunto = new Termino [numTerminos];
}

Diccionario::Diccionario(int numT, const Termino *conj){
    numTerminos = numT;
    conjunto = new Termino [numTerminos];
    for(int i=0; i<numT ; i++)
        conjunto[i] = conj[i];
}

Diccionario::Diccionario(const Diccionario &cp){
    numTerminos = cp.numTerminos;
    conjunto = new Termino [numTerminos];
    for(int i=0; i<numTerminos ; i++)
        conjunto[i] = cp.conjunto[i];
}

string* Diccionario::getDefiniciones(const Termino &t){
    return t.getDefiniciones();
}

Termino* Diccionario::getTerminos(){
    return conjunto;
}

int Diccionario::getNumTerminos(){
    return numTerminos;
}

void Diccionario::addTermino(const Termino &t){
    Termino *aux = new Termino [numTerminos];
    int cont=0;
    bool introducida = false;
    
    for(int i=0; i<numTerminos ; i++)
        aux[i] = conjunto[i];
    numTerminos++;

    delete [] conjunto;
    conjunto = new Termino [numTerminos];

    for(int i=0; i<numTerminos ; i++){
        if(i != numTerminos-1 || introducida){
            if(t.getPalabra() < aux[i].getPalabra()){
                conjunto[i] = t;
                introducida = true;
            }
            else{
                conjunto[i] = aux[cont];
                cont++;
            }
        }
    }
    if(!introducida)
        conjunto[numTerminos-1] = t;

    delete [] aux;
}

void Diccionario::quitTermino(int pos){
    if(pos< 0 || pos>=numTerminos)
        cout<<"Entrada erronea en el método de quitTermino. Posición no válida"<<endl;
    else{
        Termino *aux = new Termino [numTerminos];
        
        for(int i=0; i<numTerminos ; i++)
            aux[i] = conjunto[i];
        numTerminos--;

        delete [] conjunto;
        conjunto = new Termino [numTerminos];
        for(int i=0; i<numTerminos ; i++){
            int cont = 0;
            if(i != pos){
                conjunto[cont] = aux[i];
                cont++;
            }
        }

        delete [] aux;
    }
}

Diccionario Diccionario::filtradoPorIntervalo(char min, char max){
    Diccionario salida;
    string comparacion;

    for(int i=0; i<numTerminos ; i++){
        comparacion = conjunto[i].getPalabra();

        if( comparacion[0]>=min && comparacion[0]<=max )
            salida.addTermino(conjunto[i]);
    }

    return salida;
}

Diccionario Diccionario::filtradoPorPalabra(string palabra){
    Diccionario salida;
    Termino *taux;
    bool primera;

    for(int i=0 ; i<numTerminos ; i++){
        taux = new Termino;
        primera = true;

        for(int j=0; j<conjunto[i].getNumeroDefiniciones(); j++){
            if( conjunto[i].getDefinicionPos(j).find(palabra) != -1){
                if(primera){
                    taux->setPalabra( conjunto[i].getPalabra() );
                    primera=false;
                }
                taux->nuevaDefinicion( conjunto[i].getDefinicionPos(j) );

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

    for (int i=0; i<numTerminos; i++)
        suma += conjunto[i].getNumeroDefiniciones();

    return suma;
}

int Diccionario::maxDefinicionesPalabra(){
    int max = 0;

    for (int i=0; i<numTerminos; i++)
        if(max < conjunto[i].getNumeroDefiniciones())
            max = conjunto[i].getNumeroDefiniciones();

    return max;
}

double Diccionario::promedioDefiniciones(){
    return totalDefiniciones()/(double)numTerminos;
}

ostream& operator<<(ostream &flujo, const Diccionario &dic){
    for(int i=0; i<dic.numTerminos; i++){
        for(int j=0; j<dic.conjunto[i].getNumeroDefiniciones(); j++){
            flujo<<dic.conjunto[i].getPalabra()<<";";
            flujo<<dic.conjunto[i].getDefinicionPos(j)<<endl;
        }
    }

    return flujo;
}

istream& operator>>(istream &flujo, Diccionario &dic){
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

