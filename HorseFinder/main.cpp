#include <iostream>
#include <random>
using namespace std;

int matriz[8][8];

typedef struct coords{
    int fila;
    int columna;
}Coords;

Coords checkearPosicion(Coords coords) {

    Coords coordsFinales = {-1,-1};

    if (!(coords.fila < 0 || coords.fila > 7) && !(coords.columna < 0 || coords.columna > 7) && matriz[coords.fila][coords.columna] == 0 ){
         coordsFinales = coords;
    }

    return coordsFinales;
}

// Generacion de numero random (ni idea)
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 7);

Coords movimientoPosible(int fila, int columna){

    Coords coordsFinales;

    Coords posCandidata1 = {fila + 2,columna + 1};
    Coords posCandidata2 = {fila + 2,columna - 1};
    Coords posCandidata3 = {fila - 2,columna + 1};
    Coords posCandidata4 = {fila - 2,columna - 1};

    Coords posCandidata5 = {fila + 1,columna + 2};
    Coords posCandidata6 = {fila + 1,columna - 2};
    Coords posCandidata7 = {fila - 1,columna + 2};
    Coords posCandidata8 = {fila - 1,columna - 2};

    Coords posCandidatas[8] = {posCandidata1, posCandidata2, posCandidata3, posCandidata4, posCandidata5, posCandidata6, posCandidata7, posCandidata8};

    for (int i = 0; i<8; i++){
        bool numeroValido = false;

        while (!numeroValido){
            int numeroRandom = dist(mt);

            Coords posCandidataActual = posCandidatas[numeroRandom];

            // cout << "Numero Tomado: " << numeroRandom << ". Iteracion actual: " << i << endl;

            if (posCandidataActual.fila != -10){
                coordsFinales = checkearPosicion(posCandidataActual);
                if (coordsFinales.fila != -1){
                    return coordsFinales;
                }
                numeroValido = true;
                posCandidatas[numeroRandom].fila = -10;
                posCandidatas[numeroRandom].columna = -10;

            }
        }
    }

    return coordsFinales;
}

void printearMatriz(Coords coordenadaARestaltar){
    for (int fila = 0; fila < 8; fila++){
        for (int columna = 0; columna < 8; columna++){
            cout<< matriz[fila][columna] << " ";
            if (matriz[fila][columna] < 10){
                cout << " ";
            }
        }
        cout<<endl;
    }
}

int main() {

    while(true) {

        for (int fila = 0; fila < 8; fila++) {
            for (int columna = 0; columna < 8; columna++) {
                matriz[fila][columna] = 0;
            }
        }

        int filaInicial = 4;
        int columnaInicial = 6;

        /*
        cout << "Ingrese fila inicial: (0,7)" << endl;
        cin >> filaInicial;

        cout << "Ingrese columna inicial: (0,7)" << endl;
        cin >> columnaInicial;
         */

        if (filaInicial > 7 || filaInicial < 0 || columnaInicial > 7 || columnaInicial < 0) {
            cout << "Tanto la fila como la columna debe ser un numero de 0 a 7!!" << endl;
            continue;
        }

        Coords posActual = {filaInicial, columnaInicial};

        matriz[posActual.fila][posActual.columna] = 1;

        //cout << "Matriz Inicial: " << endl;
        //printearMatriz(posActual);

        int numIteracion = 2;

        while (true) {
            Coords movimientoPosibleAUsar = movimientoPosible(posActual.fila, posActual.columna);
            if (movimientoPosibleAUsar.fila != -1) {
                matriz[movimientoPosibleAUsar.fila][movimientoPosibleAUsar.columna] = numIteracion;
                posActual.fila = movimientoPosibleAUsar.fila;
                posActual.columna = movimientoPosibleAUsar.columna;
            } else if (numIteracion == 65) {
                cout << "Encontre una combinacion que completa todo!!!!."<<endl;
                cout << "Matriz en iteracion: " << numIteracion << endl;
                printearMatriz(posActual);
                return 1;
            } else {
                cout << "No hay mas movimientos posibles... aborto. Itearaciones: " << numIteracion << endl;
                if (numIteracion >= 60){
                    printearMatriz(posActual);
                }
                break;
            }

            //cout << "Matriz en iteracion: " << numIteracion << endl;
            numIteracion++;
        }

    }
    return 0;
}


