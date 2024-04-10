#include <iostream>
using namespace std;

// Função para combinar duas metades ordenadas e contar inversões
// l-> índice do primeiro elemento da parte esquerda
// m-> índice do meio
// r-> índice do último elemento
int mergeAndCount(int* arr, int l, int m, int r) {
    // Criação de arrays temporários para armazenar as partes esquerda e direita do array principal
    int* left = new int[m - l + 1];
    int* right = new int[r - m];

    // Copiar elementos para os arrays temporários
    for (int i = 0; i < m - l + 1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < r - m; i++)
        right[i] = arr[m + 1 + i];

    // Combinar as partes esquerda e direita de forma ordenada e contar as inversões
    int i = 0, j = 0, k = l, invers = 0;
    while (i < m - l + 1 && j < r - m) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            // Incrementar o número de inversões quando um elemento da parte direita é menor que um elemento da parte esquerda
            invers += (m + 1) - (l + i);
        }
    }
    // Copiar os elementos restantes, se houver, de left e right para arr
    while (i < m - l + 1)
        arr[k++] = left[i++];
    while (j < r - m)
        arr[k++] = right[j++];

    // Liberar memória alocada para os arrays temporários
    delete[] left;
    delete[] right;

    return invers; // Retorna o número total de inversões
}

// Função principal de ordenação e contagem de inversões usando o algoritmo Merge Sort
int mergeSortAndCount(int* arr, int l, int r) {
    int count = 0;
    if (l < r) {
        // Encontra o meio do array
        int m = (l + r) / 2;
        // Recursivamente chama mergeSortAndCount para as duas metades e soma o número de inversões em cada chamada
        count += mergeSortAndCount(arr, l, m);
        count += mergeSortAndCount(arr, m + 1, r);
        // Combina as duas metades ordenadas e conta o número de inversões ao fazer isso
        count += mergeAndCount(arr, l, m, r);
    }
    return count; // Retorna o número total de inversões
}

int main() {

    int n; // define amanho do vetor

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) { // lê os elementos do vetor
        cin >> arr[i];
    }

    int tamanho_vetor = sizeof(arr) / sizeof(arr[0]); // calcula o numero de elementos do array
    
    // Chama mergeSortAndCount para classificar o array e contar o número de inversões
    cout << mergeSortAndCount(arr, 0, tamanho_vetor - 1) << endl;
    return 0;
}
