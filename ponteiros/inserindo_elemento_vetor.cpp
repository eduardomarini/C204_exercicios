#include <iostream>
using namespace std;

int main() {

    int n; // tamanho vetor
    int *v; // ponteiro para o vetor

    cin >> n;

    // Aloca dinamicamente o vetor de tamanho n
    v = new int[n];

    int *p = v; // ponteiro para percorrer o vetor

    //Lendo os elementos do vetor usando um ponteiro
    for(int i = 0; i < n; i++) {
        cin >> *p; // insere o elemento no vetor usando o ponteiro
        p++; // move o ponteiro para a próxima posição do vetor
    }

    //Exibe os elementos do vetor usando um ponteiro
    p = v; // redefine o ponteiro para o início do vetor
    for(int i = 0; i < n; i++) {
        cout << *p << " "; // exibe o elemento do vetor usando um ponteiro
        p++; // move o ponteiro para o proximo elemento do vetor
    }

    //Libera memória alaocada para o vetor
    delete[] v;

    return 0;
}