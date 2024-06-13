/*Soebad desenvolveu um sistema de visão computacional que identifica algumas características das tortas. Ele quer usar esses dados para tomar decisões 
mais assertivas na hora fazer as vendas.

Inicialmente, dada uma imagem da torta, ele consegue identificar alguns pontos: As extremidades esquerda e direita da borda da torta e as extremidades 
esquerda e direita da circunferência da base da torta. A figura abaixo mostra essas características:

Dados as coordenadas desses pontos, ele quer saber qual é a espessura da massa, o diâmetro e a altura da torta. Considere que o diâmetro da 
circunferência da base é o mesmo do topo e a altura da torta é calculada a partir da base até o topo da torta.

Entrada
A entrada é composta por quatro linhas. Em cada linha são informadas as coordenadas x e y de cada um dos pontos A, B, C e D, respectivamente.

Saída
O programa deve informar três linhas contendo os valores inteiros da espessura da massa, do diâmetro e da altura da torta.

Exemplo de entrada:
1 10
2 10
1 2
22 2

Exemplo de saída:
1
21
8
*/

#include <iostream>  
#include <math.h>  
using namespace std;  

struct Ponto {  // Define uma estrutura Ponto com dois membros inteiros x e y
    int x;
    int y;	
};

// Função para calcular a área de um triângulo dado por três pontos
double area_triangulo(Ponto a, Ponto b, Ponto c) {
    return ((a.x*b.y) - (a.y*b.x) + (a.y*c.x) - (a.x*c.y) + (b.x*c.y) - (b.y*c.x))/2.0;  
}

// Função para calcular a distância entre dois pontos
double distancia(Ponto p1, Ponto p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// Função para determinar a orientação de três pontos
int orientacao(Ponto a, Ponto b, Ponto c) {
    double area = area_triangulo(a,b,c);
    if(area > 0){
        return 1;  
    } else if(area < 0){
        return -1;  
    } else {
        return 0;  
    }
}

int main() {  
    Ponto A, B, C, D;  
    cin >> A.x >> A.y;  
    cin >> B.x >> B.y; 
    cin >> C.x >> C.y;  
    cin >> D.x >> D.y;  

    int espessura = abs(A.x - B.x);  
    int diametro = distancia(C, D); 
    int altura = abs(A.y - C.y);  

    cout << espessura << endl;  
    cout << diametro << endl;  
    cout << altura << endl;  

    return 0;  
}