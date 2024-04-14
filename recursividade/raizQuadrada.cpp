#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float calcularRaiz(float x0, float x, float e) {

    if (abs(pow(x0, 2) - x) <= e)
        return x0;
    
    float raiz = (pow(x0, 2) + x) / (2 * x0);
    
    return calcularRaiz(raiz, x, e);
}

int main() {

    float x, x0, e;
    cin >> x >> x0 >> e;

    cout << fixed << setprecision(4);
    cout << calcularRaiz(x0, x, e) << endl;

    return 0;
}
