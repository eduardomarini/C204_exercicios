#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int n; // tamanho do vetor
    int *v; // ponteiro para o vetor            

    cin >> n;

    // Aloca dinamicamente o vetor de tamanho n
    v = new int[n];

    int *p = v; // ponteiro para percorrer o vetor

    int soma_valores_vetor = 0;
    //Lendo os elementos do vetor usando o ponteiro
    for (int i = 0; i < n; i++) {
        cin >> *p; // insere elemento utilizando um ponteiro
        soma_valores_vetor += *p;
        p++; // move o ponteiro para a proxima posição do vetor
    }

    float media;

    media = (float)soma_valores_vetor / n;

    cout << fixed << setprecision(2);
    cout << media;

    //Libera memória alocada
    delete[] v;

    return 0;
}