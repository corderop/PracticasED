#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Matriz{

private:
    int** f;
    int tamfil;
    int tamcol;

public: 
    Matriz(int tm){
     
        reservarmemoria(tm);
        
    }
    
    ~Matriz(){
     
        liberarmemoria();
        
    }
    
    void reservarmemoria(int tm){
 
        tamfil=tm;
        tamcol=tm;
        
        f=new int* [tamfil];
    
        for(int i=0; i<tamfil; i++){
        
            f[i]=new int[tamcol];
            
        }
    }

    void liberarmemoria(){
 
        for(int i = 0; i < tamfil; i++)
            delete [] f[i];
        
        delete [] f;
        
        f=NULL;
    }
    
    void rellenarMatriz(int vmax) {
        
        srand(time(0));
        for(int i = 0; i < tamfil; i++)
            for(int j = 0; j < tamcol; j++)
                f[i][j] = rand() % vmax;
}
    
    int getPosicion(int i, int j){
        return f[i][j];
    }
    
    void multiplicamatriz(const Matriz &m1,const Matriz &m2){
     
        int col=0;
        int suma;

        for(int i=0; i<m1.tamfil; i++){     
            for(int j=0; j<m1.tamcol; j++){
                suma=0;
                for(int h=0; h<m1.tamfil; h++){
                    suma += m1.f[i][h]*m2.f[h][j];
                }
                this->f[i][j] = suma;
            }
        }
    }

};

void sintaxis(){
    cout<<"¡¡ Parametros mal introducidos !!"<<endl;
    cout<<"Introduce el tamaño de la siguiente forma:"<<endl;
    cout<<"./ejecutable tamaño valormax";
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){

    int tam, vmax;
    clock_t tini, tfin;

    if (argc!=3)
        sintaxis();

    if (argv[2] > 0){
        vmax = atoi(argv[2]);
        if(argv[1] > 0)
            tam = atoi(argv[1]);
        else
            sintaxis();
    }
    else
        sintaxis();

    Matriz m1(tam), m2(tam), m3(tam);
    
    m1.rellenarMatriz(vmax);
    m2.rellenarMatriz(vmax);
    
    tini=clock();

    m3.multiplicamatriz(m1, m2);

    tfin=clock();

    cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
  
}
