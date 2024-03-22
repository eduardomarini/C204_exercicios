#include <iostream>
using namespace std;

int main () {

    int n; // tamanho do vetor
    cin >> n;

    //Aloca dinamicamente vetor de tamanho n
    int *v = new int[n];
    int contador_positivo_par = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] >= 0 && v[i]%2 == 0) // condição para verificar se elemento é positivo e par
            contador_positivo_par++; // incremento para elemente positivo e par
    }

    cout << contador_positivo_par;

    // Libera memória alocada
    delete[] v;
 
    return 0;
}