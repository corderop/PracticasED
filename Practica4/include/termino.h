/**
 * @file termino.h
 * @brief Fichero de cabecera del TDA Termino
 */

#ifndef TERMINO
#define TERMINO
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

/**
 * @class Termino
 * @brief T.D.A. Termino
 *
 * Una instancia @e c del tipo de datos abstracto @c Termino es un objeto
 * en el que se almacena un termino, es decir, una palabra, y sus deficiones
 * asociadas, se representa de la siguiente forma:
 *
 * palabra: definiciones
 *
 * @author Francisco Beltrán Sánchez
 * @author Pablo Cordero Romero
 * @date Diciembre 2018
 */
class Termino{

    private: 
        /**
         * @page repConjunto Rep del TDA Termino
         * @section invConjunto Invariante de representación
         * Un objeto @e t del TDA Termino debe cumplir:
         * - @c t.num_def >= 0
         * - @c t.term.second pueda albergar t.num_def definiciones
         * @section faConjunto Funcion de abstracción
         * Un objeto válido @e t del TDA Termino representa al valor 
         * - @c t.term.first, (t.term.second[0], t.term.second[1],..., t.term.second[num_def-1])
         */
        pair < string, vector<string> > term; /**< pair de termino, almacena la palabra y sus definiciones*/
        int num_def; /**< numero de definiciones*/

    public:
        /**
         * @brief Constructor por defecto. Crea un objeto sin definiciones ni palabra.
         */
        Termino();

        /**
         * @brief Constructor por parametros
         * @param pal Nombre del término 
         * @param def Puntero a las distintas definiciones que tiene el término
         * @param numero Numero de definiciones que tiene el término
         * @pre numero debe ser mayor que 0, si no se creará un objeto vacío.
         */
        Termino(string pal, string* def, int numero);

        /**
         * @brief Constructor de copia
         * @param ter Término a copiar
         */
        Termino(const Termino& ter);

        /**
         * @brief Consultor del atributo palabra
         * @return Valor del atributo palabra
         */
        string getPalabra() const;

        /**
         * @brief Modificador del atributo palabra
         * @param pal Nuevo nombre para el término
         */
        void setPalabra(string pal);

        /**
         * @brief Consultor del atributo definiciones
         * @return vector que contienes las definiciones del término
         */
        vector<string> getDefiniciones() const;

        /**
         * @brief Función para acceder a la definición de una posición concreta
         * @param pos Posición a la que se quiere acceder
         * @return Definición del término a la que se ha accedido
         */
        string getDefinicionPos(int pos) const;

        /**
         * @brief Añade una nueva definición al vector de definiciones
         * @param def Nueva definición a añadir en el término
         */
        void nuevaDefinicion(string def);

        /**
         * @brief Consultor del numero de definiciones
         * @return Valor del atributo num_def
         */
        int getNumeroDefiniciones() const;

        typedef vector<string>::iterator iterator;
        typedef vector<string>::const_iterator const_iterator;
        
        /**
         * @brief Iterador de comienzo del contenedor
         */
        Termino::iterator begin();

        /**
         * @brief Iterador constante de comienzo del contenedor
         */
        Termino::const_iterator begin() const;
        
        /**
         * @brief Iterador de final del contenedor
         */
        Termino::iterator end();
        
        /**
         * @brief Iterador constante de final del contenedor
         */
        Termino::const_iterator end() const;
   
        /**
         * @brief Sobrecarga del operador menos
         * @param ot Termino a comparar
         * @return true si el objeto con el que se usa es menor. Si no false
         */
        bool operator<(Termino const& ot) const;

        friend bool operator==(const Termino &uno, const Termino &dos);
        friend ostream& operator<< (ostream & os, const Termino & t);

};

/**
 * @brief Sobrecarga del operador de salida
 * @param os Flujo de salida para el termino
 * @param t Termino que se lleva al flujo de salida
 * @return Flujo de salida, para poder concatenar varias salidas
 */
ostream& operator<< (ostream & os, const Termino & t);

/**
 * @brief Sobrecarga del operador de comparacion
 * @param uno Termino primero
 * @param dic Termino segundo
 * @return true si ambos términos son iguales, false si no lo son
 */
bool operator==(const Termino &uno, const Termino &dos);

#endif
