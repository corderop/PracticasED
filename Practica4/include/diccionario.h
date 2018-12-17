/**
 * @file diccionario.h
 * @brief Fichero de cabecera del TDA Diccionario
 */

#ifndef DICCIONARIO
#define DICCIONARIO
#include <cctype>
#include <set>
#include "termino.h"

using namespace std;

/**
 * @class Diccionario
 * @brief T.D.A. Diccionario
 *
 * Una instancia @e c del tipo de datos abstracto @c Diccionario es un objeto
 * en el que se almacena un diccionario, es decir, un conjunto de Términos,
 * que se representan de la siguiente forma:
 *
 * termino1, termino2...
 * 
 * Un ejemplo de uso puede verse en:
 * @include pruebadiccionario.cpp
 *
 * @author Francisco Beltrán Sánchez
 * @author Pablo Cordero Romero
 * @date Diciembre 2018
 */
class Diccionario{
    private:
        /**
         * @page repConjunto Rep del TDA Diccionario
         * @section invConjunto Invariante de representación
         * Un objeto @e d del TDA Diccionario debe cumplir:
         * - @c d.numTerminos >= 0
         * - @c d.term.second pueda albergar d.numTerminos términos
         * @section faConjunto Funcion de abstracción
         * Un objeto válido @e d del TDA Diccionario representa al valor 
         * - @c d.conjunto[1] ... d.conjunto[d.numTerminos-1]
         */ 
        set<Termino> conjunto; /**< conjunto de Términos del diccionario*/
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
         * @param palabra Palabra para la que buscar sus definiciones
         * @return Vector con el conjunto de definiciones de la palabra
         */ 
        vector<string> getDefiniciones(string palabra);

        /**
         * @brief Consultor de los Términos del diccionario
         * @return set con el conjunto de términos del diccionario
         */
        set<Termino> getTerminos();

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
         * @param t Termino a eliminar
         */
        void quitTermino(const Termino &t);

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
         * @return Diccionario con las definiciones que contengan la palabra especificada.
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

        typedef set<Termino>::iterator iterator;
        typedef set<Termino>::const_iterator const_iterator;

        /**
         * @brief Iterador de comienzo del contenedor
         */
        Diccionario::iterator begin();
        
        /**
         * @brief Iterador constante de comienzo del contenedor
         */
        Diccionario::const_iterator begin() const;
        
        /**
         * @brief Iterador de final del contenedor
         */
        Diccionario::iterator end();
        
        /**
         * @brief Iterador constante de final del contenedor
         */
        Diccionario::const_iterator end() const;

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