#ifndef COLA_MAX_PILA
#define COLA_MAX_PILA

/**
 * Pablo Cordero Romero
 * Francisco Beltrán Sánchez
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * @struct Valores pila consulta
 * @brief Struct de valores de pila de consulta y borrado
 */
template <typename T>
struct valores{
    T valor; /**< Celda valor */
    T maximo; /**< Celda máximo */
};

/**
 * @class Cola máxima pilas
 * @brief Cola con máximos hecha con pilas
 */
template <class T>
class Cola_max{
    private:
        stack<T> *insercciones; /**< Pila inserciones */
        stack<valores<T>> *consYBorr; /**< Pila consulta y borrado */
        int nelement; /**< Número de elementos */
        
    public:
        /**
         * @brief Constructor por defecto
         */        
        Cola_max();

        /**
         * @brief Constructor por copia
         * @param cp El objeto a copiar
         */
        Cola_max(const Cola_max &cp);

        /**
         * @brief Destructor
         */
        ~Cola_max();

        /**
         * @brief Consultor del numero de elementos de la cola
         * @return El número de elementos de la cola
         */
        int num_elementos() const;

        /**
         * @brief Devuelve si la cola está vacía o no
         * @return True si está vacía, false si no lo está
         */
        bool vacia() const;

        /**
         * @brief Inserta un elemento en la cola
         * @param valor El elemento a insertar
         */
        void poner(const T &valor);

        /**
         * @brief Pasa la pila de inserciones a la de borrado y consulta
         */
        void pasarEntrePilasItoB();

        /**
         * @brief Pasa la pila de borrado y consulta a la de inserciones
         */
        void pasarEntrePilasBtoI();

        /**
         * @brief Elimina el último elemento añadido a la cola
         */
        void quitar();

        /**
         * @brief Devuelve el elemento en el frente de la cola
         * @return El elemento en el frente de la cola
         */
        T frente() const;

        /**
         * @brief Devuelve el maximo de la cola
         * @return El máximo de la cola
         */
        T maximo() const;    

};
#include "Cola_max_pila.tpp"
#endif