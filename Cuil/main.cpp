#include <iostream>
#include <string>
using namespace std;

int main() {
    int dni;

    cout << "Ingrese su DNI:" << endl;
    cin>>dni;

    bool inputInvalido = true;
    string sexo;

    int numGrande = 10000000;
    int nums[10];
    int productos[10] = {5,4,3,2,7,6,5,4,3,2};

    while (inputInvalido){
        cout << "Ingrese sexo: [H] = Hombre, [M] = Mujer, [E] = Empresa" << endl;
        cin>>sexo;

        inputInvalido = false;

        if (sexo == "H"){
            nums[0] = 2;
            nums[1] = 0;
        } else if (sexo == "M"){
            nums[0] = 2;
            nums[1] = 7;
        }else if (sexo == "E"){
            nums[0] = 3;
            nums[1] = 0;
        } else {
            cout << "Input invalido!!" << endl;
            inputInvalido = true;
        }
    }

    for (int i = 3; i<= 10; i++){

        if (i == 3){
            nums[i - 1] = (dni - dni % numGrande) / numGrande;
        } else {
            nums[i - 1] = ((dni - dni % numGrande) / numGrande) % 10;
        }

        numGrande /= 10;
    }

    int numsFinales[11] = {0,0,0,0,0,0,0,0,0,0,0};

    int valorFinal = 0;

    for (int i = 0; i < 10; i++){
        numsFinales[i] = nums[i];
        valorFinal += nums[i] * productos[i];
    }

    valorFinal = 11 - (valorFinal % 11);

    numsFinales[10] = valorFinal;

	cout << "Su CUIL es: " << endl;

    for (int unNumFinal : numsFinales){
        cout<<unNumFinal;
    }

    return 0;
}
