#include <iostream>
#include <cmath>
using namespace std;

int calcularPotencia(int a, int n) {
    if(n == 0)
        return 1;
    
    return a * calcularPotencia(a, n - 1);
}

int main() {

    int a, n;

    cin >> a >> n;
     
    int resultado = calcularPotencia(a, n);

    cout << resultado << endl;

    return  0;
}