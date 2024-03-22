#include <iostream>
using namespace std;

int main() {

    int n; // tamanho do vetor
    cin >> n;

    // Aloca dinamicamente o vetor de tamanho "n" na memória
    int *v = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int maior_valor = v[0]; // assume que o primeiro elemento é o maior
    for (int i = 0; i < n; i++) {
        if (v[i] > maior_valor) 
            maior_valor = v[i];
    }

    cout << maior_valor;

    // Libera memória alocada
    delete[] v;

    return 0;
}