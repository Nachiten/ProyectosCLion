#include <iostream>

// Tamaño de la matriz
#define FILAS 20
#define COLUMNAS 20
// Cantidad de puntos de interes
#define CANT_PDI 2

using namespace std;

void computarEnemigos(int coord[][2], int matriz[][COLUMNAS]){

    for (int i = 0; i<CANT_PDI;i++){
    matriz[coord[i][0]][coord[i][1]] = 0;
    }

    int valor[CANT_PDI] = {0};
    int fila;
    int columna;
    int valorTest = 10000;

    for (int i = 0; i<FILAS;i++){
        for (int j = 0; j<COLUMNAS;j++){
            for (int k = 0; k<CANT_PDI;k++){

                // Calcula la distancia
                fila = coord[k][0] - i;
                columna =  coord[k][1] - j;

                //cout<<fila<<" ";
                //cout<<columna<<" | ";

                if (fila<0){
                    fila*=-1;
                }
                if (columna<0){
                    columna*=-1;
                }

                valor[k] = fila+columna;
                //cout<<valor[k]<<" ";

                if (valor[k] < valorTest) {
                    valorTest = valor[k];
                }
                //cout<<valorTest<<" ";

            }
            matriz[i][j] = valorTest;
            valorTest = 10000;
        }
        cout<<endl;
    }
}


void mostrarMatriz(int matriz[][COLUMNAS]){
    for (int i = 0; i<FILAS; i++){
        for (int j = 0; j<COLUMNAS;j++){
            cout<<matriz[i][j]<<" ";
            if (matriz[i][j] - 10 <0){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void vaciarMatriz(int matriz[][COLUMNAS]){
    for (int i = 0; i<FILAS; i++){
        for (int j = 0; j<COLUMNAS;j++){
            matriz[i][j] = 0;

        }
    }
    cout<<"MATRIZ VACIADA"<<endl;
}

int main(){

    int matriz[FILAS][COLUMNAS];

    int parOrdenado[CANT_PDI][2];

    for (int i = 0; i<CANT_PDI;i++){
        cout<<"Inserte coordenada X del punto de interes "<<i<<":";
        cin>>parOrdenado[i][0];
        cout<<endl;
        cout<<"Inserte coordenada Y del punto de interes "<<i<<":";
        cin>>parOrdenado[i][1];
        cout<<endl;
    }

    vaciarMatriz(matriz);

    computarEnemigos(parOrdenado,matriz);

    mostrarMatriz(matriz);


}
