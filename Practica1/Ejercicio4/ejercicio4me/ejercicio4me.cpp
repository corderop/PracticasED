#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/** Método de ordenación por burbuja
 * Eficiencia teórica calculada a mano: O(n^2)
 */
void ordenar(int *v, int n) {

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (v[j]>v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}

void sintaxis(){
    cout<<"¡¡ Parametros mal introducidos !!"<<endl;
    cout<<"Introduce el tamaño de la siguiente forma:"<<endl;
    cout<<"./ejecutable tamaño valormax";
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    int vmax, tam;
    clock_t tini, tfin;
    
    if (argc!=3)
        sintaxis();

    if (argv[2] > 0){
        vmax = atoi(argv[2]);
        if(argv[1]>0)
            tam = atoi(argv[1]);
        else
            sintaxis();
    }
    else
        sintaxis();

    // Creación del vector aleatorio
    int *v=new int[tam];
    srand(time(0));
    for (int i=0; i<tam; i++)
        v[i] = (vmax/tam)*i + rand() % ( ( (vmax/tam)*(i+1)+1 ) - (vmax/tam)*i );

    //Inicio medición
    tini = clock();

    ordenar(v, tam);

    // Finalización de medición
    tfin = clock();

    // Mostramos el tiempo que ha tardado
    cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

    delete [] v;
}
