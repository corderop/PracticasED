#ifndef DICCIONARIO
#define DICCIONARIO
/*
"diccionario.h"
    ** Función de abstracción:
    ----------------------
    fA : r ----> conjunto[numTerminos]

    ** Invariante de Representación:
    ----------------------------
    Cualquier objeto del tipo_rep, diccionario, debe cumplir:
    - numTerminos>=0
*/

#include <iostream>
#include <cctype>
#include "termino.h"

using namespace std;

/**
 * @class Diccionario
 * @brief Diccionario que recoge una serie de terminos con sus respectivas definiciones
 */
class Diccionario{
    private:
        /**
         * @page repConjunto Rep del TDA Diccionario
         * @section faConjunto Funcion de abstracción
         * Un objeto válido @e rep del TDA Diccionario representa al valor
         * (rep.conjunto, rep.numTerminos)
         */ 
        Termino *conjunto; /**< conjunto de Términos del diccionario*/
        int numTerminos; /**< numero de Términos del diccionario*/
    
    public:
        /**
         * @brief Constructor por defecto
         */ 
        Diccionario();

        /**
         * @brief Constructor por parametros
         * @param numeroTermino Número de terminos que hay dentro del diccionario
         * @param *conjunto Puntero a los términos que contiene el diccionario
         */
        Diccionario(int numeroTermino, const Termino *conjunto);

        /**
         * @brief Constructor de copia 
         * @param cp Diccionario que se va a copiar en el nuevo objeto
         */ 
        Diccionario(const Diccionario &cp);

        /**
         * @brief Consultor de una determinada definicion del diccionario
         * @param pos Número de la posicion del Término que contiene las definiciones
         * @return Puntero a las definiciones del Término solicitado
         */ 
        string* getDefiniciones(const Termino &t);

        /**
         * @brief Consultor de los Términos del diccionario
         * @return Puntero a los Términos del diccionario
         */
        Termino* getTerminos();

        /**
         * @brief Consultor del número de Términos que contiene el diccionario
         * @return Número de Términos del diccionario
         */
        int getNumTerminos();
        
        /**
         * @brief Añade un nuevo Término al diccionario
         * @param t Término a añadir
         */  
        void addTermino(const Termino &t);

        /**
         * @brief Elimina un Término del diccionario
         * @param pos Posición del Término a eliminar
         */
        void quitTermino(int pos);

        /**
         * @brief Función para encontrar todos los terminos y sus definiciones comprendidas entre dos letras
         * @param min Caracter mínimo del intervalo a buscar
         * @paran max Caracter máximo del intervalo a buscar
         * @return Diccionario acortado según el intervalo
         */
        Diccionario filtradoPorIntervalo(char min, char max);

        /**
         * @brief Función para encontrar todos los terminos cuyas definiciones contengan una palabra especificada.
         * @param palabra Palabra a buscar entre las definiciones del diccionario.
         * @return Diccionario con las definiciones que contienen la palabra especificada.
         */
        Diccionario filtradoPorPalabra(string palabra);

        /**
         * @brief Devuelve el número de definiciones totales del diccionario
         * @return Número de definiciones totales del diccionario
         */
        int totalDefiniciones();

        /**
         * @brief Devuelve el número de definiciones máxima dentro de una sola palabra
         * @return Número máximo de definiciones dentro de una sola palabra
         */
        int maxDefinicionesPalabra();

        /**
         * @brief Devuelve el número de definiciones media por Término
         * @return Media de definiciones por Término
         */
        double promedioDefiniciones();

        friend ostream& operator<<(ostream &flujo, const Diccionario &dic);
        friend istream& operator>>(istream &flujo, Diccionario &dic);
};

/**
 * @brief Sobrecarga del operador de salida
 * @param flujo Flujo de salida para el diccionario
 * @param dic Diccionario que se va a llevar al flujo de salida
 * @return Flujo de salida, para poder concatenar varias salidas de diccionarios 
 */
ostream& operator<<(ostream &flujo, const Diccionario &dic);

/**
 * @brief Sobrecarga del operador de entrada
 * @param flujo Flujo de entrada para el diccionario
 * @param dic Diccionario que se va a llevar al flujo de entrada
 * @return Flujo de entrada, para poder concatenar varias salidas de diccionarios
 */
istream& operator>>(istream &flujo, Diccionario &dic);

#endif
