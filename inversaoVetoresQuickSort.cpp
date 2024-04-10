#include <iostream>
using namespace std;

// Função para trocar dois elementos de um array
void swapElements(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Função para particionar o array e contar inversões
int partition(int arr[], int low, int high, int &inversions) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Troca arr[i] com arr[j]
            swapElements(arr, i, j);
        }
    }

    // Troca arr[i + 1] com arr[high] (posiciona o pivô na posição correta)
    swapElements(arr, i + 1, high);
    // Incrementa o número de inversões ao finalizar a partição
    inversions += i + 1 - low;
    // Retorna o índice do pivô
    return i + 1;
}

// Função recursiva para ordenar o array usando Quick Sort e contar inversões
void quickSort(int arr[], int low, int high, int &inversions) {
    if (low < high) {
        // Particiona o array e obtém o índice do pivô
        int pi = partition(arr, low, high, inversions);
        // Ordena os elementos antes e depois do pivô
        quickSort(arr, low, pi - 1, inversions);
        quickSort(arr, pi + 1, high, inversions);
    }
}

// Função para contar inversões usando Quick Sort
int countInversions(int arr[], int n) {
    // Inicializa o número de inversões como 0
    int inversions = 0;
    // Chama a função Quick Sort para ordenar o array e contar inversões
    quickSort(arr, 0, n - 1, inversions);
    // Retorna o número total de inversões
    return inversions;
}

// Função principal
int main() {
    // Array de entrada
    int arr[] = {9, 5, 6, 4, 7, 1};
    // Tamanho do array
    int n = sizeof(arr) / sizeof(arr[0]);
    // Chama a função para contar inversões e imprime o resultado
    cout << "O número de inversões é: " << countInversions(arr, n) << endl;
    return 0;
}
