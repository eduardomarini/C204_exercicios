#include <iostream>
#include <list>

using namespace std;

int main() {
    // Declare N e M para o número de vértices e arestas, respectivamente
    int N, M;
    cin >> N >> M;

    // Inicialize a matriz de adjacência com 0s
    list<list<int>> matriz;
    for(int i = 0; i < N; i++) {
        // Crie uma lista com N zeros, representando uma linha da matriz de adjacência
        list<int> linha(N, 0);
        // Adicione a linha à matriz
        matriz.push_back(linha);
    }

    // Leia as arestas e marque as conexões na matriz
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        // Marque a conexão entre A e B na matriz
        // Encontre o iterador para a linha A e a posição B na linha
        auto it = next(matriz.begin(), A-1);
        auto it2 = next(it->begin(), B-1);
        // Defina a conexão como 1
        *it2 = 1;

        // Marque a conexão entre B e A na matriz (a matriz é simétrica para grafos não direcionados)
        // Encontre o iterador para a linha B e a posição A na linha
        it = next(matriz.begin(), B-1);
        it2 = next(it->begin(), A-1);
        // Defina a conexão como 1
        *it2 = 1;
    }

    // Imprima a matriz de adjacência
    for(auto &linha : matriz) {
        for(auto &valor : linha) {
            // Imprima o valor seguido de um espaço
            cout << valor << " ";
        }
        // Imprima uma nova linha após cada linha da matriz
        cout << endl;
    }

    return 0;
}
