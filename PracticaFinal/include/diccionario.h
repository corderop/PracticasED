#ifndef __Diccionario_h__
#define __Diccionario_h__
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include "bolsaLetras.h"

using namespace std;

/** 
 * @class Diccionario
 * @brief T.D.A. Diccionario
 * 
 * Una instancia @e c del tipo de datos abstracto @c Diccionario es un objeto
 * en el que se almacena un diccionario, es decir, un conjunto de palabras
 * ordenadas alfabéticamente.
 * 
 * Un ejemplo de uso puede verse en:
 * @include testdiccionario.cpp
 * 
 * @author Pablo Cordero Romero
 * @date Enero 2019
 */
class Diccionario{
    private:
        /**
         * @page repDiccionario Rep del TDA Diccionario
         * @section invConjunto Invariante de representación
         * Un objeto @e d del TDA Diccionario debe cumplir:
         * - @c d.datos.size() >= 0
         * @section faConjunto Funcion de abstracción
         * Un objeto válido @e d del TDA Diccionario representa al valor 
         * - @c d.datos[0] ... d.datos[d.datos.size()-1]
         */ 
        set<string> datos; /**< Conjunto de palabras del diccionario */
    public:

        /**
         * @brief Construye un diccionario vacío.
         */
        Diccionario();

        /**
         * @brief Devuelve el numero de palabras en el diccionario
         * @return int con el número de palabras del diccionario
         */
        int size() const;

        /**
         * @brief Obtiene todas las palabras en el diccionario de un longitud dada
         * @param longitud: la longitud de las palabras de salida
         * @return un vector con las palabras de longitud especifica en el parametro de entrada
         */
        vector<string> PalabrasLongitud(int longitud) const;
        
        /**
         * @brief Indica si una palabra está en el diccionario o no
         * @param palabra la palabra que se quiere buscar
         * @return true si la palabra esta en el diccionario. False en caso contrario
         */
        bool Esta(string palabra) const;

        /**
         * @brief Indica si el diccionario está vacío
         * @return true si esta vacío. false en caso contrario
         */
        bool empty() const;

        /**
         * @brief Crea un diccionario formado por las palabras que contiene solo letras de la bolsa de letras pasada como parámetro.
         * @param bl bolsa de letras que contiene las letras
         * @return Subdiccionario creado
         */
        Diccionario crearSubdiccionario(const BolsaLetras &bl) const;

        /**
         * @class Diccionario::iterator
         * @brief T.D.A. Diccionario::iterator
         *
         * Una instancia @e c del tipo de datos abstracto @c Diccionario::iterator
         * es un objeto usado para poder acceder a los diferentes elementos del 
         * diccionario:
         * 
         * Un ejemplo de uso puede verse en:
         * @include testdiccionario.cpp
         *
         * @author Pablo Cordero Romero
         * @date Diciembre 2018
         */
        class iterator{
            private:
                set<string>::iterator it;/**<Iterador del mismo tipo que el atributo de la clase padre*/
            public:
                /**
                 * @brief Construye un iterador vacío.
                 */
                iterator();

                /**
                 * @brief Sobrecarga del operador * para poder acceder a los elementos apuntados
                 * @return string del elemento al que apunta el iterador
                 */
                string operator*();

                /**
                 * @brief Sobrecarga del operador ++ para poder incrementar el iterador
                 * @return iterador por referencia para poder encadenar los operadores
                 */
                Diccionario::iterator& operator++();

                /**
                 * @brief Sobrecarga del operador == para comparar iteradores
                 * @param i iterador de diccionario con el que se compara
                 * @return true si es igual, false si no lo es
                 */
                bool operator==(const Diccionario::iterator &i);

                /**
                 * @brief Sobrecarga del operador != para comparar iteradores
                 * @param i iterador de diccionario con el que se compara
                 * @return true si no es igual, false si es igual
                 */
                bool operator!=(const Diccionario::iterator &i);

                friend class Diccionario;
        };

        /**
         * @class Diccionario::const_iterator
         * @brief T.D.A. Diccionario::const_iterator
         *
         * Una instancia @e c del tipo de datos abstracto @c Diccionario::const_iterator
         * es un objeto usado para poder acceder a los diferentes elementos del 
         * diccionario:
         * 
         * Un ejemplo de uso puede verse en:
         * @include testdiccionario.cpp
         *
         * @author Pablo Cordero Romero
         * @date Diciembre 2018
         */
        class const_iterator{
            private:
                set<string>::const_iterator it;/**<Iterador del mismo tipo que el atributo de la clase padre*/
            public:
                /**
                 * @brief Construye un iterador constante vacío.
                 */
                const_iterator();

                /**
                 * @brief Sobrecarga del operador * para poder acceder a los elementos apuntados
                 * @return string del elemento al que apunta el iterador constante
                 */
                string operator*();

                /**
                 * @brief Sobrecarga del operador ++ para poder incrementar el iterador constante
                 * @return iterador por referencia para poder encadenar los operadores
                 */
                Diccionario::const_iterator& operator++();

                /**
                 * @brief Sobrecarga del operador == para comparar iteradores constantes
                 * @param i iterador de diccionario con el que se compara
                 * @return true si es igual, false si no lo es
                 */
                bool operator==(const Diccionario::const_iterator &i) const;

                /**
                 * @brief Sobrecarga del operador != para comparar iteradores constantes
                 * @param i iterador de diccionario con el que se compara
                 * @return true si no es igual, false si es igual
                 */
                bool operator!=(const Diccionario::const_iterator &i) const;

                friend class Diccionario;
        };
        
        /**
         * @brief Iterador de comienzo del contenedor
         * @return iterador de comienzo del contenedor
         */
        Diccionario::iterator begin();

        /**
         * @brief Iterador constate de comienzo del contenedor para cuando el objeto al que se accede es constante
         * @return iterador de comienzo del contenedor
         */
        Diccionario::const_iterator begin() const;

        /**
         * @brief Iterador constate de comienzo del contenedor para cuando el objeto que se accede no es constante
         * @return iterador de comienzo del contenedor
         */
        Diccionario::const_iterator cbegin() const;

        /**
         * @brief Iterador de final del contenedor
         * @return iterador de final del contenedor
         */
        Diccionario::iterator end();

        /**
         * @brief Iterador constante de final del contenedor para cuando el objeto al que se accede es constante
         * @return iterador de final del contenedor
         */
        Diccionario::const_iterator end() const;

        /**
         * @brief Iterador constante de final del contenedor para cuando el objeto al que se accede no es constante
         * @return iterador de final del contenedor
         */
        Diccionario::const_iterator cend() const;
        
        friend istream & operator>>(istream & is,Diccionario &D);
        friend ostream & operator<<(ostream & os, const Diccionario &D);
};

/**
 * @brief Lee de un flujo de entrada un diccionario
 * @param is: flujo de entrada
 * @param D: el objeto donde se realiza la lectura.
 * @return el flujo de entrada para concatenar flujos
 */
istream & operator>>(istream & is,Diccionario &D);

/**
 * @brief Escribe en un flujo de salida un diccionario
 * @param os:flujo de salida
 * @param D: el objeto diccionario que se escribe
 * @return el flujo de salida para concatenar flujos
 */
ostream & operator<<(ostream & os, const Diccionario &D);

#endif