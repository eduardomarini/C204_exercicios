#include<iostream>
using namespace std;

struct ponto {
    int x, y;
};

float area_triangulo(ponto a, ponto b, ponto c) {
    float area = (a.x*b.y) - (a.y*b.x) + (b.x*c.y) - (b.y*c.x) + (c.x*a.y) - (c.y*a.x);
    area = area / 2;
    return area;
}

int main() {
    ponto a, b, c;
    a.x = 1;
    a.y = 2;
    b.x = 4;
    b.y = 4;
    c.x = 4;
    c.y = 1;

    float resultado = area_triangulo(a, b, c);
    cout << resultado << endl;
    if(resultado > 0) {
        cout << "Triangulo orientado no sentido horario" << endl;
    } else if(resultado < 0) {
        cout << "Triangulo orientado no sentido anti-horario" << endl;
    } else {
        cout << "Os pontos são colineares" << endl;
    }

    return 0;
    
}