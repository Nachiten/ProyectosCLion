#include <iostream>
using namespace std;

int main() {
    int number, iteracion = 0;

    cout<<"Inserte numero inicial: "<<endl;
    cin>>number;

    while (number != 1){

        cout<<iteracion<<" | Siguiente numero: "<<number<<endl;

        if (number % 2 == 0){
            number /= 2;
        } else {
            number = number * 3 + 1;
        }

        iteracion++;
    }
    return 0;
}
