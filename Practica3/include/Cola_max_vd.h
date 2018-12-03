#ifndef __COLA_VD
#define __COLA_VD

/**
 * Pablo Cordero Romero
 * Francisco Beltrán Sánchez
 */
#include <iostream>
#include <cassert>

using namespace std;

/**
 * @struct Celda vector dinámico
 * @brief Struct de valores del vector dinámico
 */
template <class T>
struct Celda{
    T datocel; /**< Celda valor */
    T vmax; /**< Celda máximo */

};

/**
 * @class Cola máxima de vector dinámico
 * @brief Cola con máximos hecha con un vector dinámico
 */
template <class T>
class Cola_max{

    private:

        Celda<T>* datos; /**< Celda de datos */
        int reservados; /**< Número de reservados */
        int anterior; /**< Elemento anterior */
        int posterior; /**< Elementos posterior */
        int nelementos; /**< Número de elementos */

    public: 
        /**
         * @brief Constructor por defecto
         */ 
        Cola_max();

        /**
         * @brief Constructor por copia
         * @param c El objeto a copiar
         */        
        Cola_max(const Cola_max& c);

        /**
         * @brief Destructor
         */         
        ~Cola_max();

        /**
         * @brief Sobrecarga del operador de asignación
         * @param c La cola que se quiere asignar
         * @return Una cola por referencia
         */        
        Cola_max& operator=(const Cola_max& c);

        /**
         * @brief Devuelve si la cola está vacía o no
         * @return True si está vacía, false si no lo está
         */
        bool vacia() const;

        /**
         * @brief Inserta un elemento en la cola
         * @param valor El elemento a insertar
         */
        void poner(const T& valor);

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
        T maximo();

        /**
         * @brief Actualiza el máximo de la cola
         */
        void ajustarMaximo();

        /**
         * @brief Consultor del numero de elementos de la cola
         * @return El número de elementos de la cola
         */
        int num_elementos();
        
    private:
        /**
         * @brief Copia una cola
         * @param c La cola a copiar
         */
        void copiar(const Cola_max& c);

        /**
         * @brief Libera memoria
         */
        void liberar();

        /**
         * @brief Redimensiona el vector
         * @param n El numero de elementos final del vector
         */
        void resize(const int n);
};

#include "Cola_max_vd.tpp"
#endif