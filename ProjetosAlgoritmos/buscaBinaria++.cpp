#include <iostream>
using namespace std;

// Função para realizar a busca binária
int busca_binaria(int vetor[], int valor, int inicio, int fim) {
    if (inicio > fim) { // Se o índice de início é maior que o índice de fim, o valor não está no vetor
        return -1;
    }
    int meio = inicio + (fim - inicio) / 2; // Calcula o índice do meio do vetor
    if (vetor[meio] == valor) { // Se o valor no meio do vetor é o valor buscado
        return meio; // Retorna o índice do meio
    } else if (vetor[meio] > valor) { // Se o valor no meio do vetor é maior que o valor buscado
        return busca_binaria(vetor, valor, inicio, meio - 1); // Realiza a busca na metade esquerda do vetor
    } else { // Se o valor no meio do vetor é menor que o valor buscado
        return busca_binaria(vetor, valor, meio + 1, fim); // Realiza a busca na metade direita do vetor
    }
}

int main() {
    int N;
    cin >> N; // Lê o tamanho do vetor
    int vetor[N]; // Cria o vetor
    for (int i = 0; i < N; i++) { // Lê os elementos do vetor
        cin >> vetor[i];
    }
    int valor;
    cin >> valor; // Lê o valor a ser buscado
    int resultado = busca_binaria(vetor, valor, 0, N - 1); // Realiza a busca binária
    cout << resultado << endl; // Imprime o resultado
    return 0;
}