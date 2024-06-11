#include <iostream> 
#include <cmath> 
#include <iomanip>
using namespace std; 

struct Ponto { // Define uma estrutura de dados para um ponto no espaço 2D
    int x, y; // As coordenadas x e y do ponto
};

Ponto p0; // Declara uma variável global do tipo Ponto

// Função para calcular a distância quadrada entre dois pontos
int distanciaQuadrada(Ponto p1, Ponto p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// Função para determinar a orientação de um conjunto ordenado de três pontos no plano
int orientacao(Ponto p, Ponto q, Ponto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Os pontos são colineares
    return (val > 0)? 1: 2; // Retorna 1 se for no sentido horário, 2 se for no sentido anti-horário
}

// Função para comparar dois pontos de acordo com a orientação
int comparar(Ponto p1, Ponto p2) {
    int o = orientacao(p0, p1, p2);
    if (o == 0)
        return (distanciaQuadrada(p0, p2) >= distanciaQuadrada(p0, p1))? -1 : 1;
    return (o == 2)? -1: 1;
}

// Função para ordenar um array de pontos usando o algoritmo Bubble Sort
void bubbleSort(Ponto pontos[], int n) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (comparar(pontos[j], pontos[j + 1]) > 0) {
                swap(pontos[j], pontos[j + 1]); // Troca os pontos se eles estiverem na ordem errada
            }
        }
    }
}

// Função para encontrar o casco convexo de um conjunto de pontos
void cascoConvexo(Ponto pontos[], int n) {
    int ymin = pontos[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = pontos[i].y;
        if ((y < ymin) || (ymin == y && pontos[i].x < pontos[min].x))
            ymin = pontos[i].y, min = i; // Encontra o ponto com a menor coordenada y (ou o mais à esquerda em caso de empate)
    }
    swap(pontos[0], pontos[min]); // Coloca o ponto mais à esquerda na primeira posição
    p0 = pontos[0];
    bubbleSort(pontos + 1, n - 1); // Ordena os pontos restantes de acordo com a orientação
    int m = 1;
    for (int i=1; i<n; i++) {
        while (i < n-1 && orientacao(p0, pontos[i], pontos[i+1]) == 0)
            i++; // Ignora os pontos colineares
        pontos[m] = pontos[i];
        m++; // Incrementa o contador de pontos únicos
    }
    if (m < 3) return; // Se houver menos de 3 pontos, não é possível formar um polígono
    Ponto S[m]; // Cria um array para armazenar os pontos do casco convexo
    int topo = -1;
    S[++topo] = pontos[0];
    S[++topo] = pontos[1];
    S[++topo] = pontos[2]; // Adiciona os três primeiros pontos ao casco
    for (int i = 3; i < m; i++) {
        while (orientacao(S[topo-1], S[topo], pontos[i]) != 2)
            topo--; // Remove os pontos do topo enquanto eles formam um ângulo não à esquerda com os pontos[i]
        S[++topo] = pontos[i]; // Adiciona pontos[i] ao casco
    }
    Ponto primeiro = S[0];
    double perimetro = 0;
    Ponto anterior = primeiro;
    for (int i = 1; i <= topo; i++) {
        Ponto atual = S[i];
        perimetro += sqrt(distanciaQuadrada(anterior, atual)); // Calcula a distância entre os pontos consecutivos
        anterior = atual;
    }
    perimetro += sqrt(distanciaQuadrada(anterior, primeiro)); // Adiciona a distância do último ponto ao primeiro
    cout << fixed << setprecision(4); // Define a precisão da saída para 4 casas decimais
    cout << perimetro << endl; // Imprime o perímetro do casco convexo 
}

int main() {
    int n;
    cin >> n; 
    Ponto pontos[n]; // Cria um array para armazenar os pontos
    for (int i = 0; i < n; i++)
        cin >> pontos[i].x >> pontos[i].y; 
    cascoConvexo(pontos, n); // Chama a função para encontrar o casco convexo
    return 0;
}