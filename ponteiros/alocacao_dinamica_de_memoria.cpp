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

    // Criar um ponteiro para uma struct
    Notas *ponteiroNotas;

    // Alocar memória para e struct
    ponteiroNotas = new Notas;

    // leitura das notas
    cin >> ponteiroNotas->nota_1 >> ponteiroNotas->nota_2 >> ponteiroNotas->nota_3 >> ponteiroNotas->nota_4;

    // Cálculo da média
    ponteiroNotas->media = (float)(ponteiroNotas->nota_1 + ponteiroNotas->nota_2 + ponteiroNotas->nota_3 + ponteiroNotas->nota_4) / 4;

    cout << fixed << setprecision (2);
    cout << "Media = " << ponteiroNotas->media << endl; 

    delete ponteiroNotas;

    return 0;
}