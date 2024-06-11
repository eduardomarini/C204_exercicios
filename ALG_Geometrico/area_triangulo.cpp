#include <iostream> 
#include <cmath> 
#include <iomanip> 
using namespace std; 

struct Ponto { // Define uma estrutura para um ponto com coordenadas x e y
    int x, y;
};

// Função para calcular a área de um triângulo
double areaTriangulo(Ponto p1, Ponto p2, Ponto p3) {
    // Retorna a área do triângulo usando a fórmula de área de um triângulo com coordenadas cartesianas
    return abs((p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2.0);
}


int main() {
    Ponto p1, p2, p3; // Pontos para armazenar as coordenadas dos vértices do triângulo
    // Lê as coordenadas dos vértices do triângulo
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << fixed << setprecision(1); // Define a precisão da saída para 1 casa decimal
    // Imprime a área do triângulo
    cout << areaTriangulo(p1, p2, p3) << endl;
    return 0; 
}