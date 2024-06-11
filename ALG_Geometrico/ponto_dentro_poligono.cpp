#include <iostream> // Inclui a biblioteca padrão de entrada/saída
using namespace std; // Usa o namespace padrão

// Define uma estrutura para um ponto com coordenadas x e y
struct Ponto {
    int x, y;
};

// Função para verificar se o ponto q está no segmento de linha 'pr'
bool onSegmento(Ponto p, Ponto q, Ponto r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true; // Retorna verdadeiro se o ponto q está no segmento de linha 'pr'
    return false; // Caso contrário, retorna falso
}

// Função para encontrar a orientação do trio ordenado (p, q, r)
int orientacao(Ponto p, Ponto q, Ponto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

// Função que retorna verdadeiro se os segmentos de linha 'p1q1' e 'p2q2' se intersectam
bool doIntersect(Ponto p1, Ponto q1, Ponto p2, Ponto q2) {
    int o1 = orientacao(p1, q1, p2);
    int o2 = orientacao(p1, q1, q2);
    int o3 = orientacao(p2, q2, p1);
    int o4 = orientacao(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true; // Retorna verdadeiro se os segmentos de linha se intersectam
    if (o1 == 0 && onSegmento(p1, p2, q1)) return true;
    if (o2 == 0 && onSegmento(p1, q2, q1)) return true;
    if (o3 == 0 && onSegmento(p2, p1, q2)) return true;
    if (o4 == 0 && onSegmento(p2, q1, q2)) return true;
    return false; // Caso contrário, retorna falso
}

// Função para verificar se o ponto P está dentro do polígono ou não
bool estaDentro(Ponto poligono[], int n, Ponto p) {
    if (n < 3) return false; // Deve haver pelo menos 3 vértices no polígono
    Ponto pontoInfinito = {101, p.y}; // Cria um ponto para a linha de p ao infinito
    int cont = 0, i = 0; // Contagem de interseções da linha acima com os lados do polígono
    do {
        int prox = (i + 1) % n;
        if (doIntersect(poligono[i], poligono[prox], p, pontoInfinito)) {
            if (orientacao(poligono[i], p, poligono[prox]) == 0)
                return onSegmento(poligono[i], p, poligono[prox]);
            cont++;
        }
        i = prox;
    } while (i != 0);
    return (cont % 2 == 1); // Retorna verdadeiro se a contagem é ímpar, falso caso contrário
}

// Código principal
int main() {
    int n; // Número de vértices no polígono
    cin >> n;
    Ponto poligono[100]; // Array de pontos para o polígono
    for (int i = 0; i < n; i++)
        cin >> poligono[i].x >> poligono[i].y; // Entrada dos vértices do polígono
    Ponto p; // Ponto a ser verificado
    cin >> p.x >> p.y;
    if (estaDentro(poligono, n, p)) // Verifica se o ponto está dentro do polígono
        cout << "DENTRO" << endl;
    else
        cout << "!(DENTRO)" << endl;
    return 0;
}