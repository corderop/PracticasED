#ifndef TERMINO
#define TERMINO
#include <iostream>
/**
 * Pablo Cordero Romero
 * Francisco Beltrán Sánchez
 */

using namespace std;
/**
 * @class Termino
 * @brief Palabra con su conjunto de definiciones asociadas
 */
class Termino{

    private: 
        string palabra; /**< palabra*/
        string* definiciones; /**< puntero a definiciones*/
        int num_def; /**< numero de definiciones*/

    public:
        /**
         * @brief Constructor por defecto
         */
        Termino();

        /**
         * @brief Constructor por parametros
         * @param pal Nombre del término 
         * @param def Puntero a las distintas definiciones que tiene el término
         * @param numero Numero de definiciones que tiene el término
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
         * @return Puntero a las definiciones que posee el termino
         */
        string* getDefiniciones();

        /**
         * @brief Función para acceder a la definición de una posición concreta
         * @param pos Posición a la que se quiere acceder
         * @return Definición del término a la que se ha accedido
         */
        string getDefinicionPos(int pos);

        /**
         * @brief Añade una nueva definición al puntero definiciones
         * @param def Nueva definición a añadir en el término
         */
        void nuevaDefinicion(string def);

        /**
         * @brief Consultor del numero de definiciones
         * @return Valor del atributo num_def
         */
        int getNumeroDefiniciones();
};

#endif
