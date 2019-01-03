#ifndef _letras_h_
#define _letras_h_

#include <iostream>

using namespace std;

/** 
 * @class Letra
 * @brief T.D.A. Letra
 * 
 * Una instancia @e c del tipo de datos abstracto @c Letra es un objeto
 * en el que se almacena una letra, junto con la cantidad que puede aparecer en 
 * el juego y la puntuación que tiene cada una.
 * 
 * Un ejemplo de uso puede verse en:
 * @include conjuntodeletras.cpp
 * 
 * @author Pablo Cordero Romero
 * @date Enero 2019
 */
class Letra{
    /**
     * @page repConjunto Rep del TDA Letra
     * @section invConjunto Invariante de representación
     * Un objeto @e l del TDA Letra debe cumplir:
     * - @c ( l.letra >= 'a' && l.letra <= 'z' ) || ( l.letra >= 'A' && l.letra<= 'Z' )
     * - @c l.cantidad >= 0
     * - @c l.puntos >= 0
     * @section faConjunto Funcion de abstracción
     * Un objeto válido @e l del TDA Letra representa al valor 
     * - @c l.letra  l.cantidad  l.puntos
     */
    private:
        char letra; /**< Letra con la que trabaja el objeto */
        int cantidad; /**< Cantidad máxima que puede aparecer una letra en una ronda de juego */
        int puntos; /**< Puntos asignados a la letra en el modo de juego "Puntuación" */
    public:
        /**
         * @brief Construye una letra.
         */
        Letra();

        /**
         * @brief Constructor con parámetros.
         * @param ltr: letra
         * @param cntdd: cantidad
         * @param pnts: puntos
         */
        Letra(char ltr, int cntdd, int pnts);

        /**
         * @brief Consultor de letra
         * @return letra del objeto con el que es llamado
         */
        char getLetra() const;

        /**
         * @brief Consultor de cantidad
         * @return cantidad del objeto con el que es llamado
         */
        int getCantidad() const;

        /**
         * @brief Consultor de puntos
         * @return puntos del objeto con el que es llamado
         */
        int getPuntos() const;

        /**
         * @brief Sobrecarga del operador <
         * @param ot: letra con la que se va a comparar el objeto
         * @return true si el objeto es menor, false si es mayor o igual
         */
        bool operator<(Letra const& ot) const;

        friend istream & operator>>(istream & is, Letra& lt);
        friend ostream & operator<<(ostream & os, const Letra &lt);
};

/**
 * @brief Lee de un flujo de entrada una letra
 * @param is:flujo de entrada
 * @param lt: el objeto donde se realiza la lectura.
 * @return el flujo de entrada para concatenar flujos
 */
istream & operator>>(istream & is, Letra& lt);

/**
 * @brief Escribe en un flujo de salida una letra
 * @param os:flujo de salida
 * @param lt: el objeto letra que se escribe
 * @return el flujo de salida para concatenar flujos
 */
ostream & operator<<(ostream & os, const Letra &lt);

#endif