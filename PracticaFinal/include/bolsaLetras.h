#ifndef _bolsaletras_h_
#define _bolsaletras_h_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/** 
 * @class BolsaLetras
 * @brief T.D.A. BolsaLetras
 * 
 * Una instancia @e c del tipo de datos abstracto @c BolsaLetras es un objeto
 * en el que se almacena una BolsaLetras, es decir, un conjunto de letras sin orden.
 * 
 * Un ejemplo de uso puede verse en:
 * @include letras.cpp
 * 
 * @author Pablo Cordero Romero
 * @date Enero 2019
 */
class BolsaLetras{
    private:
        /**
         * @page repBolsaLetras Rep del TDA BolsaLetras
         * @section invBolsaLetras Invariante de representación
         * Un objeto @e bl del TDA BolsaLetras debe cumplir:
         * - @c bl.letras.size() >= 0
         * @section faBolsaLetras Funcion de abstracción
         * Un objeto válido @e bl del TDA BolsaLetras representa al valor 
         * - @c bl.letras[0] ... d.letras[d.letras.size()-1]
         */ 
        vector<char> letras; /**< Vector de letras*/
    public:
        /**
         * @brief Construye una bolsa de letras vacía
         */
        BolsaLetras();

        /**
         * @brief Añade un elemento al vector de letras
         * @param L: Letra a añadir
         */
        void addElemento(char L);

        /**
         * @brief Elimina una letra del vector
         * @param Letra a eliminar
         * @return true si se ha eliminado correctamente
         */
        bool eliminarLetra(char L);

        /**
         * @brief Comprueba si todas las letras de una palabra están en la bolsa de letras
         * @param palabra: Palabra con la que comprobar
         * @return true si todas las letras de la palabra están en la bolsa, false si no 
         */
        bool letrasValidas(string palabra) const;
};

#endif