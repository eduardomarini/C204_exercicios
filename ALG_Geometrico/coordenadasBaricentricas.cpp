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
    
    // Initialize the points a, b, and c before using them
    a = {0, 0};
    b = {0, 0};
    c = {0, 0};

    float resultado = area_triangulo(a, b, c);
    cout << resultado << endl;
    if(resultado > 0) {
        cout << "Triangulo orientado no sentido horario" << endl;
    } else if(resultado < 0) {
        cout << "Triangulo orientado no sentido anti-horario" << endl;
    } else {
        cout << "Os pontos são colineares" << endl;
    }

    ponto p = {3, 2};
    ponto p1 = {1, 2};
    ponto p2 = {4, 4};
    ponto p3 = {4, 1};
    float area = area_triangulo(p1, p2, p3); // Changed variable name from 'a' to 'area'
    float l1 = area_triangulo(p, p2, p3) / area;
    float l2 = area_triangulo(p1, p, p3) / area;
    float l3 = area_triangulo(p1, p2, p) / area;

    cout << l1 << endl;
    cout << l2 << endl;
    cout << l3 << endl;

    return 0;
    
}