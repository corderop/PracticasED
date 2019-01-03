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

string mostrarMejorPuntuacion(char tipo, int num, const Diccionario &D, const ConjuntoDeLetras &L){
    string salida;
    vector<string> palabras;

    if(tipo == 'L'){
        int aux = num;
        
        while(palabras.empty()){
            palabras = D.PalabrasLongitud(aux);

            aux--;
        }
        
        for(int i=0; i<(int)palabras.size(); i++){
            cout<<palabras[i]<<"  Puntuación: "<<aux+1<<endl;
            salida = palabras[i];
        }
    }
    else if(tipo == 'P'){
        Diccionario::const_iterator it = D.begin();
        int puntuacionMax = L.calcularPuntuacion(*it, tipo),
            aux;
        
        for(it = D.begin(); it!=D.end(); ++it){
            aux = L.calcularPuntuacion(*it, tipo);
            if(aux >= puntuacionMax){
                if(aux==puntuacionMax){
                    palabras.push_back(*it);
                }
                else{
                    puntuacionMax = aux;
                    palabras.clear();
                    palabras.push_back(*it);
                }
            }
        }

        for(int i=0; i<(int)palabras.size(); i++){
            cout<<palabras[i]<<"  Puntuación: "<<puntuacionMax<<endl;
            salida = palabras[i];
        }
    }

    return salida;
}

int main(int argc, char * argv[]){
    if (argc!=5){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.- El fichero de diccionario"<<endl;
        cout<<"2.- El fichero con las letras"<<endl;
        cout<<"3.- El número de letras a generar de forma aleatoria"<<endl;
        cout<<"4.- Modalidad de juego:"<<endl;
        cout<<"\tL - Se buscará la palabra más larga"<<endl;
        cout<<"\tP - Se buscará la palabra de mayor puntuación"<<endl;

        return 0;
    }

    ifstream dic(argv[1]);
    ifstream ltr(argv[2]);
    int numLtr = strtol(argv[3], NULL, 10);
    char tipo = argv[4][0];
    char seguir;

    if (!dic || !ltr){
        cout<<"No puedo abrir alguno de los ficheros"<<endl;

        return 0;
    }

    Diccionario D;
    Diccionario *subD;
    ConjuntoDeLetras L;
    BolsaLetras bolsa;
    string entrada, solucion;

    cout<<endl<<endl<<"************************************"<<endl;
    cout<<"Cargando diccionario...."<<endl;
    dic>>D;
    cout<<"Leido el diccionario..."<<endl;
    cout<<"Cargando conjunto de letras"<<endl;
    ltr>>L;
    cout<<"Leido el conjunto de letras"<<endl;
    cout<<"************************************"<<endl<<endl;

    srand(time(NULL));

    if(tipo == 'P')
        cout << "******Puntuaciones Letras*******\n"<<
                "A\t1\n"<<
                "B\t3\n"<<
                "C\t3\n"<<
                "D\t2\n"<<
                "E\t1\n"<<
                "F\t4\n"<<
                "G\t2\n"<<
                "H\t4\n"<<
                "I\t1\n"<<
                "J\t8\n"<<
                "L\t1\n"<<
                "M\t3\n"<<
                "N\t1\n"<<
                "O\t1\n"<<
                "P\t3\n"<<
                "Q\t5\n"<<
                "R\t1\n"<<
                "S\t1\n"<<
                "T\t1\n"<<
                "U\t1\n"<<
                "V\t4\n"<<
                "Y\t4\n"<<
                "Z\t10\n" << endl;

    do{
        subD = new Diccionario();
        while(subD->empty()){
            bolsa = L.generarLetras(numLtr);
            *subD = D.crearSubdiccionario(bolsa);
            if(!subD->empty()){
                bool valida_letras = false,
                    valida_existe = false;
                do{
                    cout<<"\nEscriba su palabra: ";
                    cin>>entrada;
                    valida_letras = (int)entrada.size() <= numLtr;
                    if(valida_letras)
                        valida_letras = bolsa.letrasValidas(entrada);
                    if(!valida_letras)
                        cout<<"\nEntrada no valida. La palabra "<<entrada<<" contiene letras no especificadas"<<endl;
                    valida_existe = subD->Esta(entrada);
                    if(!valida_existe)
                        cout<<"\nEntrada no valida. La palabra "<<entrada<<" no se encuentra en el diccionario"<<endl; 
                }while(!valida_letras || !valida_existe);
                cout<<entrada<<"   Puntuación: "<<L.calcularPuntuacion(entrada, tipo)<<endl<<endl;
            }
            else
                cout<<"\nNo se puede crear ninguna palabra con estas letras, generando nuevas..."<<endl;
        }

        solucion = mostrarMejorPuntuacion(tipo, numLtr, *subD, L);
        cout<<"Mejor solución: "<<solucion<<endl;

        cout<<endl<<"************************************"<<endl;
        cout<<"¿Quieres seguir jugando?[S/N]: ";
        cin>>seguir;
        seguir = toupper(seguir);
        cout<<"************************************"<<endl;
        delete subD;
    }while(seguir == 'S');

}
