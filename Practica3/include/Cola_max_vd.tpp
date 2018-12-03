using namespace std;

template <class T>
Cola_max<T>::Cola_max(){
    datos = new Celda<T>[1];
    reservados = 1;
    anterior = posterior = 0;
    nelementos = 0;

}

template<class T>
Cola_max<T>::Cola_max(const Cola_max<T>& c){

    copiar(c);

}

template<class T>
Cola_max<T>::~Cola_max(){

    liberar();

}

template<class T>
Cola_max<T>& Cola_max<T>::operator=(const Cola_max<T>& c){

    if(this!=c){
        liberar();
        copiar(c);
    }

    return (*this);

}

template<class T>
bool Cola_max<T>::vacia() const{

    return (nelementos==0);

}

template<class T>
void Cola_max<T>::poner(const T& valor){
    
    if(nelementos==reservados)
        resize(reservados*2);
    
    nelementos++;
    datos[posterior].datocel=valor;
    ajustarMaximo();
    posterior=(posterior+1)%reservados;

}

template<class T>
void Cola_max<T>::quitar(){

    assert(nelementos!=0);

    anterior = (anterior+1)%reservados;
    ajustarMaximo();
    nelementos--;

    if(nelementos < reservados/4)
        resize(reservados/2);

}

template<class T>
T Cola_max<T>::frente() const{

    assert(nelementos!=0);

    return datos[anterior].datocel;

}

template<class T>
T Cola_max<T>::maximo(){

    assert(nelementos!=0);

    return datos[anterior].vmax;

}

template<class T>
void Cola_max<T>::ajustarMaximo(){
    
    datos[posterior].vmax=datos[posterior].datocel;

    bool maximoEncontrado=false;
    int i=(posterior-1);

    while(i>=anterior && !maximoEncontrado ){
        
        if(datos[posterior].vmax>datos[i].vmax)
            datos[i].vmax=datos[posterior].vmax;            

        else
            maximoEncontrado=true;

        i--;

    }

}

template<class T>
int Cola_max<T>::num_elementos(){
    
    return nelementos;

}

template<class T>
void Cola_max<T>::copiar(const Cola_max<T>& c){
    
    reservados=c.reservados;
    datos=new Celda<T>[reservados];

    for(int i=0; i<reservados; i++)
        datos[i]=c.datos[i];
    
    anterior=c.anterior;
    posterior=c.posterior;
    nelementos=c.nelementos;

}

template<class T>
void Cola_max<T>::liberar(){

    delete[] datos;
    nelementos = anterior = reservados = posterior = 0;

}

template<class T>
void Cola_max<T>::resize(const int n){

    assert(n>0 && n>nelementos);

    Celda<T>* aux = new Celda<T>[n];
    for (int i=0; i<n; i++)
        aux[i]=datos[anterior+i];

    anterior = 0;
    posterior = nelementos;
    delete[] datos;
    datos = aux;
    reservados = n;

}