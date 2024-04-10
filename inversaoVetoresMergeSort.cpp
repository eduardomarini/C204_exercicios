#include <iostream>
using namespace std;

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
    int i = 0, j = 0, k = l, swaps = 0;
    while (i < m - l + 1 && j < r - m) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            // Incrementar o número de inversões quando um elemento da parte direita é menor que um elemento da parte esquerda
            swaps += (m + 1) - (l + i);
        }
    }
    // Copiar os elementos restantes, se houver, de left e right para arr
    while (i < m - l + 1)
        arr[k++] = left[i++];
    while (j < r - m)
        arr[k++] = right[j++];

    return swaps; // Retorna o número total de inversões
}

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
    int arr[] = {9, 5, 6, 4, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Chama mergeSortAndCount para classificar o array e contar o número de inversões
    cout << "O número de inversões é: " << mergeSortAndCount(arr, 0, n - 1) << endl;
    return 0;
}
