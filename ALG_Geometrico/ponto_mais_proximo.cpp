#include <iostream> 
#include <cmath> 
using namespace std; 

struct Ponto { // Define uma estrutura para um ponto com coordenadas x e y
    int x, y;
};

// Função para calcular a distância entre dois pontos
double distancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); // Retorna a distância euclidiana entre p1 e p2
}

// Função para encontrar o ponto mais próximo do usuário
Ponto pontoMaisProximo(Ponto pontos[], int n, Ponto usuario) {
    double menorDistancia = distancia(pontos[0], usuario); // Inicializa a menor distância com a distância do primeiro ponto
    Ponto pontoProximo = pontos[0]; // Inicializa o ponto mais próximo como o primeiro ponto

    // Loop para percorrer todos os pontos
    for (int i = 1; i < n; i++) {
        double dist = distancia(pontos[i], usuario); // Calcula a distância do ponto atual ao usuário
        // Se a distância atual é menor que a menor distância ou se a distância é igual e o ponto atual tem x ou y menor
        if (dist < menorDistancia || (dist == menorDistancia && (pontos[i].x < pontoProximo.x || (pontos[i].x == pontoProximo.x && pontos[i].y < pontoProximo.y)))) {
            menorDistancia = dist; // Atualiza a menor distância
            pontoProximo = pontos[i]; // Atualiza o ponto mais próximo
        }
    }

    return pontoProximo; 
}


int main() {
    int n; // Número de pontos
    cin >> n; // Lê o número de pontos
    Ponto pontos[100]; // Array para armazenar os pontos
    // Loop para ler os pontos
    for (int i = 0; i < n; i++)
        cin >> pontos[i].x >> pontos[i].y; // Lê as coordenadas x e y do ponto
    Ponto usuario; // Ponto para armazenar a posição do usuário
    cin >> usuario.x >> usuario.y; // Lê as coordenadas x e y do usuário
    Ponto proximo = pontoMaisProximo(pontos, n, usuario); // Encontra o ponto mais próximo do usuário
    cout << proximo.x << " " << proximo.y << endl; 
    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}