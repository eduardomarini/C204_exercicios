#include <iostream>
using namespace std;

// Estrutura para representar um ponto com coordenadas x e y
struct Ponto {
    int x, y;
};

// Função para calcular o quadrado da distância entre dois pontos
int distSq(Ponto p1, Ponto p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// Função para encontrar a orientação de um trio ordenado de pontos
// Retorna 0 se os pontos são colineares, 1 se são no sentido horário e 2 se são no sentido anti-horário
int orientacao(Ponto p, Ponto q, Ponto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) {
        return 0; // Pontos são colineares
    } else if (val > 0) {
        return 1; // Pontos estão em sentido horário
    } else {
        return 2; // Pontos estão em sentido anti-horário
    }
}


// Função principal que implementa o algoritmo do Casco Convexo
void cascoConvexo(Ponto pontos[], int n) {
    // Se há menos de 3 pontos, não podemos formar um casco convexo
    if (n < 3) return;

    // Encontra o ponto mais à esquerda
    int l = 0;
    for (int i = 1; i < n; i++)
        if (pontos[i].x < pontos[l].x)
            l = i;

    // Começa a partir do ponto mais à esquerda e continua se movendo no sentido anti-horário
    int p = l, q;
    do {
        // Imprime o ponto atual
        cout << pontos[p].x << " " << pontos[p].y << endl;
        // Escolhe o ponto mais à direita do ponto atual
        q = (p+1)%n;
        for (int i = 0; i < n; i++) {
           // Se o ponto i é mais anti-horário do que o ponto atual, atualiza q
           if (orientacao(pontos[p], pontos[q], pontos[i]) == 2)
               q = i;
           // Se o ponto i é colinear com p e q, e mais distante de p, atualiza q
           else if (orientacao(pontos[p], pontos[q], pontos[i]) == 0 && distSq(pontos[p], pontos[i]) > distSq(pontos[p], pontos[q]))
               q = i;
        }

        // Atualiza o ponto atual para o próximo ponto
        p = q;

    } while (p != l); // Enquanto não voltamos ao ponto inicial
}


int main() {
    // Lê o número de pontos
    int n;
    cin >> n;
    // Cria um array para armazenar os pontos
    Ponto pontos[n];
    // Lê as coordenadas dos pontos
    for (int i = 0; i < n; i++)
    cin >> pontos[i].x >> pontos[i].y;
    // Chama a função cascoConvexo para encontrar e imprimir os pontos no casco convexo
    cascoConvexo(pontos, n);
    return 0;
}