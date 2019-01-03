#ifndef _conjuntodeletras_h_
#define _conjuntodeletras_h_

#include "letra.h"
#include "bolsaLetras.h"
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

/** 
 * @class ConjuntoDeLetras
 * @brief T.D.A. ConjuntoDeLetras
 * 
 * Una instancia @e c del tipo de datos abstracto @c ConjuntoDeLetras es un objeto
 * en el que se almacena un ConjuntoDeLetras ordenadas alfabéticamente.
 * 
 * Un ejemplo de uso puede verse en:
 * @include letras.cpp
 * 
 * @author Pablo Cordero Romero
 * @date Enero 2019
 */
class ConjuntoDeLetras{
    private:
        /**
         * @page repConjuntoDeLetras Rep del TDA ConjuntoDeLetras
         * @section invConjunto Invariante de representación
         * Un objeto @e cl del TDA ConjuntoDeLetras debe cumplir:
         * - @c cl.letras.size() >= 0
         * @section faConjunto Funcion de abstracción
         * Un objeto válido @e d del TDA ConjuntoDeLetras representa al valor 
         * - @c cl.letras[0] ... cl.letras[d.letras.size()-1]
         */ 
        set<Letra> letras; /**< Contenedor que almacena el conjunto de letras */
    
    public:
        /**
         * @brief Construye un conjunto de letras vacío.
         */
        ConjuntoDeLetras();
        
        /**
         * @brief Consulto del tamaño del conjunto de letras
         * @return int correspondiente al número de letras almacenadas
         */
        int getTamano() const;

        /**
         * @brief Consultor de la puntuación de una letra concreta
         * @param letra: char con la letra sobre la que queremos saber la puntuación
         * @return int correspondiente a la puntuación de la letra. O si no esta la letra en el conjunto
         */
        int getPuntuacion(char letra) const;

        /**
         * @brief Añade una letra al conjunto
         * @param lt: Letra a añadir en el contenedor
         */
        void addLetra(const Letra &lt);

        /**
         * @brief Elimina una letra del conjunto
         * @param letra: char con la letra a eliminar del contenedor
         */
        void eliminarLetra(char letra);

        /**
         * @brief Consultor para saber si una letra está en el conjunto
         * @param L: char con la letra a buscar en el conjunto
         * @return true si se encuentra la letra, false si no se encuentra
         */
        bool estaLetra(char L) const;

        /**
         * @brief Genera una bolsa de letras aleatoriamente con letras del conjunto
         * @param num: numero de letras a generar
         * @pre Se debe cumplir que num>0
         * @return Bolsa de letras generada
         */
        BolsaLetras generarLetras(int num) const;

        /**
         * @brief Calcula la puntuación conseguida mediante una palabra
         * @param palabra: palabra con la que calcular la puntuación
         * @param tipo: tipo de juego. Puntuación o Longuitud
         * @pre tipo deber ser 'P' o 'L'
         * @return puntuación o 0 si no se cumple la precondición
         */
        int calcularPuntuacion(string palabra, char tipo) const;

        /**
         * @class ConjuntoDeLetras::iterator
         * @brief T.D.A. ConjuntoDeLetras::iterator
         *
         * Una instancia @e c del tipo de datos abstracto @c ConjuntoDeLetras::iterator
         * es un objeto usado para poder acceder a los diferentes elementos del 
         * ConjuntoDeLetras:
         * 
         * Un ejemplo de uso puede verse en:
         * @include letras.cpp
         *
         * @author Pablo Cordero Romero
         * @date Diciembre 2018
         */
        class iterator{
            private:
                set<Letra>::iterator it;/**<Iterador del mismo tipo que el atributo de la clase padre*/
            public:
                /**
                 * @brief Construye un iterador vacío.
                 */
                iterator();

                /**
                 * @brief Sobrecarga del operador * para poder acceder a los elementos apuntados
                 * @return string del elemento al que apunta el iterador
                 */
                Letra operator*();

                /**
                 * @brief Sobrecarga del operador ++ para poder incrementar el iterador
                 * @return iterador por referencia para poder encadenar los operadores
                 */
                ConjuntoDeLetras::iterator& operator++();

                /**
                 * @brief Sobrecarga del operador += para poder incrementar el iterador en varias posiciones de una vez. Hecho para facilitar la generación de bolsas aleatorias
                 * @return iterador por referencia para poder encadenar los operadores
                 */
                ConjuntoDeLetras::iterator& operator+=(int num);

                /**
                 * @brief Sobrecarga del operador == para comparar iteradores
                 * @param i iterador de ConjuntoDeLetras con el que se compara
                 * @return true si es igual, false si no lo es
                 */
                bool operator==(const ConjuntoDeLetras::iterator &i);

                /**
                 * @brief Sobrecarga del operador != para comparar iteradores
                 * @param i iterador de ConjuntoDeLetras con el que se compara
                 * @return true si no es igual, false si es igual
                 */
                bool operator!=(const ConjuntoDeLetras::iterator &i);

                friend class ConjuntoDeLetras;
        };

        /**
         * @class ConjuntoDeLetras::const_iterator
         * @brief T.D.A. ConjuntoDeLetras::const_iterator
         *
         * Una instancia @e c del tipo de datos abstracto @c ConjuntoDeLetras::const_iterator
         * es un objeto usado para poder acceder a los diferentes elementos del 
         * ConjuntoDeLetras:
         * 
         * Un ejemplo de uso puede verse en:
         * @include testConjuntoDeLetras.cpp
         *
         * @author Pablo Cordero Romero
         * @date Diciembre 2018
         */
        class const_iterator{
            private:
                set<Letra>::const_iterator it; /**<Iterador del mismo tipo que el atributo de la clase padre*/
            public:
                /**
                 * @brief Construye un iterador constante vacío.
                 */
                const_iterator();

                /**
                 * @brief Sobrecarga del operador * para poder acceder a los elementos apuntados
                 * @return string del elemento al que apunta el iterador constante
                 */
                Letra operator*();

                /**
                 * @brief Sobrecarga del operador ++ para poder incrementar el iterador constante
                 * @return iterador por referencia para poder encadenar los operadores
                 */
                ConjuntoDeLetras::const_iterator& operator++();

                /**
                 * @brief Sobrecarga del operador += para poder incrementar el iterador en varias posiciones de una vez. Hecho para facilitar la generación de bolsas aleatorias
                 * @return iterador por referencia para poder encadenar los operadores
                 */
                ConjuntoDeLetras::const_iterator& operator+=(int num);

                /**
                 * @brief Sobrecarga del operador == para comparar iteradores constantes
                 * @param i iterador de ConjuntoDeLetras con el que se compara
                 * @return true si es igual, false si no lo es
                 */
                bool operator==(const ConjuntoDeLetras::const_iterator &i) const;

                /**
                 * @brief Sobrecarga del operador != para comparar iteradores constantes
                 * @param i iterador de ConjuntoDeLetras con el que se compara
                 * @return true si no es igual, false si es igual
                 */
                bool operator!=(const ConjuntoDeLetras::const_iterator &i) const;

                friend class ConjuntoDeLetras;
        };

        /**
         * @brief Iterador de comienzo del contenedor
         * @return iterador de comienzo del contenedor
         */
        ConjuntoDeLetras::iterator begin();

        /**
         * @brief Iterador constate de comienzo del contenedor para cuando el objeto al que se accede es constante
         * @return iterador de comienzo del contenedor
         */
        ConjuntoDeLetras::const_iterator begin() const;

        /**
         * @brief Iterador constate de comienzo del contenedor para cuando el objeto que se accede no es constante
         * @return iterador de comienzo del contenedor
         */
        ConjuntoDeLetras::const_iterator cbegin() const;

        /**
         * @brief Iterador de final del contenedor
         * @return iterador de final del contenedor
         */
        ConjuntoDeLetras::iterator end();

        /**
         * @brief Iterador constante de final del contenedor para cuando el objeto al que se accede es constante
         * @return iterador de final del contenedor
         */
        ConjuntoDeLetras::const_iterator end() const;

        /**
         * @brief Iterador constante de final del contenedor para cuando el objeto al que se accede no es constante
         * @return iterador de final del contenedor
         */
        ConjuntoDeLetras::const_iterator cend() const;
        
        friend istream & operator>>(istream & is, ConjuntoDeLetras& cj);
        friend ostream & operator<<(ostream & os, const ConjuntoDeLetras &cj);
};

/**
 * @brief Lee de un flujo de entrada un conjunto de letras
 * @param is:flujo de entrada
 * @param cj: el objeto donde se realiza la lectura.
 * @return el flujo de entrada
 */
istream & operator>>(istream & is, ConjuntoDeLetras& cj);

/**
 * @brief Escribe en un flujo de salida un conjunto de letras
 * @param os:flujo de salida
 * @param cj: el objeto conjunto de letras que se escribe
 * @return el flujo de salida
 */
ostream & operator<<(ostream & os, const ConjuntoDeLetras &cj);

#endif