// Faça uma função para verificar se um ponto p esta a direita, a esquerda ou alinhado com o segmento ab
// retorna: 1 se p estiver a esquerda de ab, -1 se p estiver a direita de ab, 0 se p estiver alinhado com ab
// int lado (ponto a, ponto b, ponto p) 

#include<iostream>
using namespace std;

struct ponto {
    int x, y;
};

int lado(ponto a, ponto b, ponto p) {
    int produto_vetorial = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);

    if (produto_vetorial > 0) {
        cout << "P a esquerda do segmento AB" << endl;
        return 1;  // p está à esquerda de ab
    } else if (produto_vetorial < 0) {
        cout << "P a direita do segmento AB" << endl;
        return -1;  // p está à direita de ab
    } else {
        cout << "P alinhado com o segmento AB" << endl;
        return 0;  // p está alinhado com ab
    }
}

int main() {
    ponto a, b, p;

    cin >> a.x >> a.y; // ponto a

    cin >> b.x >> b.y; // ponto b 

    cin >> p.x >> p.y; // ponto p

    int resultado = lado(a, b, p);
    cout << "Resultado: " << resultado << endl;

    return 0;
}