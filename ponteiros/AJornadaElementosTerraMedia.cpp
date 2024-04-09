#include <iostream>
using namespace std;

int main() {

    int *artefato = new int[5]; // aponta para o primeiro elemento do vetor 
    int *p = artefato; // ponteiro auxiliar para percorrer o vetor
    int soma_artefatos = 0;

    for(int i = 0; i < 5; i++) {
        cin >> *(p + i);
        soma_artefatos += *(p + i);
    }

    p = artefato; // reinicializa o ponteiro auxiliar para apontar para o primeiro elemento do vetor

    for(int i = 0; i < 5; i++) 
        cout << "Artefato coletado na terra " << i << ": " <<  *(p + i) << endl;
    
    cout << "Fim da jornada! Soma total dos artefatos: " << soma_artefatos << endl;

    return 0;
}