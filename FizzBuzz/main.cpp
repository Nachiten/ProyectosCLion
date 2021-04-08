#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;

    cout << "Ingrese el numero hasta el que se generará el juego FizzBuzz" << endl;
    cin >> num;

    for (int i = 1; i<= num; i++){
        string palabra;

        if (i % 3 == 0){
            palabra += "Fizz";
        }
        if (i % 5 == 0){
            palabra += "Buzz";
        }

        if (palabra.empty()){
            palabra = to_string(i);
        }

        cout << palabra << endl;
    }

    return 0;
}
