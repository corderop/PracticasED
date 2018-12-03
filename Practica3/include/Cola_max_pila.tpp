#include <cassert>

using namespace std;
    template <class T>
    Cola_max<T>::Cola_max(){
        insercciones = new stack<T>;
        consYBorr = new stack<valores<T>>;
        nelement = 0;
    }

    template <class T>
    Cola_max<T>::Cola_max(const Cola_max &cp){
        stack<T> aux = cp->insercciones;
        delete insercciones;
        insercciones = new stack<T>;
        insercciones = aux;

        aux = cp->consYBorr;
        delete consYBorr;
        consYBorr = new stack<valores<T>>;
        consYBorr = aux;
    }

    template <class T>
    Cola_max<T>::~Cola_max(){
        delete insercciones;
        delete consYBorr;
    }

    template <class T>
    int Cola_max<T>::num_elementos() const{
        return nelement;
    }

    template <class T>
    bool Cola_max<T>::vacia() const{
        return nelement == 0;
    }

    template <class T>
    void Cola_max<T>::poner(const T &valor){
        insercciones->push(valor);
        nelement++;
        this->pasarEntrePilasItoB();
    }
    
    template <class T>
    void Cola_max<T>::pasarEntrePilasItoB(){
        stack<T> aux = *insercciones;
        T mayor = aux.top();
        
        delete consYBorr;
        consYBorr = new stack<valores<T>>;

        for(int i=0; i<nelement; i++){
            valores<T> auxStruct;
            auxStruct.valor = aux.top();
            aux.pop();

            if( auxStruct.valor > mayor)
                mayor = auxStruct.valor;
            auxStruct.maximo = mayor;

            consYBorr->push(auxStruct);
        }      
    }        

    template <class T>
    void Cola_max<T>::pasarEntrePilasBtoI(){
        stack<valores<T>> aux = *consYBorr;

        delete insercciones;
        insercciones = new stack<T>;

        for(int i=0; i<nelement; i++)
            insercciones->push(consYBorr->pop().valor;
    }

    template <class T>
    void Cola_max<T>::quitar(){
        consYBorr->pop();
        nelement--;
        pasarEntrePilasBtoI();
    }

    template <class T>
    T Cola_max<T>::frente() const{
        return consYBorr->top().valor;
    }

    template <class T>
    T Cola_max<T>::maximo() const{
        return consYBorr->top().maximo;
    }