#include<iostream>
#include<list>
using namespace std;


// Definição da estrutura para representar um nó da lista de adjacências
struct no {
    int v; // vértice adjacente
    int peso; // peso de aresta
};

// Função para criar uma aresta no grafo
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado) {
    // Adiciona uma aresta do vértice u para o vértice v com peso p
    adj[u].push_back({v, p});

    // Se o grafo não for orientado, adiciona também uma aresta do vértice
    // v para o vértice u com o mesmo peso
    if (!orientado) {
        adj[v].push_back({u, p});
    }
}

int main() {

    int V, orientado;
    cin >> V >> orientado;

    // Cria uma lista de adjacências com V elementos
    list<no> *adj = new list<no>[V];

    int u, v, p;
    cin >> u >> v >> p;

    // Enquanto a entrada não for -1, -1, -1, cria uma aresta no grafo
    while (u != -1 && v != -1 && p != -1) {
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }

    // Imprime a lista de adjacência
    for (int i = 0; i < V; i++) {
        for (const auto& no : adj[i]) {
            cout << i << " " << no.v << " " << no.peso << endl;
        }
    }

    // Libera a memória alocada para a lista de adjacências
    delete[] adj;

    return 0;
}