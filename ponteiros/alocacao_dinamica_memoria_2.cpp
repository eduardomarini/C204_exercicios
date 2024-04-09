#include <iostream>
#include <iomanip>
using namespace std;


struct Notas {
    int nota_1;
    int nota_2;
    int nota_3;
    int nota_4;
    float media;
};

int main() {

    //Criar um ponteiro para a struct
    Notas *ponteiroNotas;

    //Alocar memória para struct
    ponteiroNotas = new Notas;

    int n; // número de alunos 
    cin >> n;

    int soma_notas = 0;

    //Lendo notas
    for(int i = 0; i < n; i++) {
        cin >> ponteiroNotas->nota_1 >> ponteiroNotas->nota_2 >> ponteiroNotas->nota_3 >> ponteiroNotas->nota_4;
        soma_notas += (ponteiroNotas->nota_1 + ponteiroNotas->nota_2 + ponteiroNotas->nota_3 + ponteiroNotas->nota_4); 
    }

    ponteiroNotas->media = (soma_notas / (n*4.0));

    cout << fixed << setprecision(2);
    cout << ponteiroNotas->media << endl;

    //Liberar memória alocada
    delete ponteiroNotas;

    return 0;
}