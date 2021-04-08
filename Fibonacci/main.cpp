#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n<= 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return fibonacci(n -1) + fibonacci(n - 2);
    }
}

int main() {
    int num;

    cout << "Ingrese un numero para saber los fibonacci hasta ese numero:" << endl;
    cin >> num;

    for (int i = 0; i<= num; i++){
        cout << "El fibonacchi numero " << i << " es: " << fibonacci(i) << endl;
    }
    return 0;
}