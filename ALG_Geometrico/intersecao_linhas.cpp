#include <iostream> 
using namespace std; 

struct Ponto { // Define a estrutura de um ponto com coordenadas x e y
    int x, y;
};

int calcularOrientacao(Ponto p, Ponto q, Ponto r) { // Função para calcular a orientação de três pontos
    int valor = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); // Calcula o valor da orientação
    if (valor == 0) return 0; // Se o valor é 0, os pontos são colineares
    return (valor > 0)? 1: 2; // Se o valor é positivo, os pontos são no sentido horário, caso contrário, são no sentido anti-horário
}

bool verificarIntersecao(Ponto p1, Ponto q1, Ponto p2, Ponto q2) { // Função para verificar se dois segmentos de linha se intersectam
    int o1 = calcularOrientacao(p1, q1, p2); // Calcula a orientação dos pontos p1, q1 e p2
    int o2 = calcularOrientacao(p1, q1, q2); // Calcula a orientação dos pontos p1, q1 e q2
    int o3 = calcularOrientacao(p2, q2, p1); // Calcula a orientação dos pontos p2, q2 e p1
    int o4 = calcularOrientacao(p2, q2, q1); // Calcula a orientação dos pontos p2, q2 e q1

    if (o1 != o2 && o3 != o4) return true; // Se as orientações são diferentes, os segmentos de linha se intersectam

    return false; 
}

int main() { 
    Ponto p1, q1, p2, q2; // Define os pontos p1, q1, p2 e q2
    cin >> p1.x >> p1.y >> q1.x >> q1.y; // Lê as coordenadas dos pontos p1 e q1
    cin >> p2.x >> p2.y >> q2.x >> q2.y; // Lê as coordenadas dos pontos p2 e q2

    if (verificarIntersecao(p1, q1, p2, q2)) cout << "SIM" << endl; // Se os segmentos de linha se intersectam, imprime "SIM"
    else cout << "NAO" << endl; 

    return 0; 
}