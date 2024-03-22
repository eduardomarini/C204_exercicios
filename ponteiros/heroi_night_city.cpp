#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Dados {
    char nome[150];
    char fabricante[150];
    int tier;
    float psicose;
};

int main() {

    int n;
    cin >> n;

    // Cria um array de ponteiros para a struct
    Dados *ponteiroDados = new Dados[n];

    float soma_psicose = 0;

    for(int i = 0; i < n; i++) {
        cin.ignore();
        cin.getline(ponteiroDados[i].nome, 150); 
        cin >> ponteiroDados[i].fabricante >> ponteiroDados[i].tier >> ponteiroDados[i].psicose;
        soma_psicose += ponteiroDados[i].psicose;  
    }

    //for(int i = 0; i < n; i++) {
        //cout << "Nome: " << ponteiroDados[i].nome << endl;
        //cout << "Fabricante: " << ponteiroDados[i].fabricante << endl;
        //cout << "Tier: " << ponteiroDados[i].tier << endl;
        //cout << "Psicose: " << ponteiroDados[i].psicose << endl; 
    //}
    
    //cout << soma_psicose << endl;

    if (soma_psicose <= 60)
        cout << "Vamos tchum! Temos uma cidade pra conquistar" << endl;
    else    
        cout << "Alerta! Recompensa de 50000 edinhos pela cabeça do Ciberpsicopata." << endl;

    // Liberar a memória alocada
    delete[] ponteiroDados;

    return 0;
} 