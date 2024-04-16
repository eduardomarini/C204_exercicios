#include <iostream>
#include <list>
using namespace std;

const int INF = 1e9; // Use um valor grande o suficiente para representar o infinito

struct Aresta {
    int origem, destino, peso;
};

void dijkstra(list<Aresta> adj[], int nVertices, int inicio, int fim) {
    // Declaração de variáveis e estruturas de dados
    bool intree[nVertices]; // Marca se um vértice está na árvore de caminhos mínimos
    int distancia[nVertices]; // Armazena as distâncias mínimas
    int pai[nVertices];   // Armazena os pais de cada vértice no caminho mínimo

    // Inicialização das estruturas de dados
    for (int u = 0; u < nVertices; ++u) {
        intree[u] = false;
        distancia[u] = INF;
        pai[u] = -1;
    }

    // Inicialização do vértice de partida
    distancia[inicio] = 0;
    int v = inicio;

    // Algoritmo de Dijkstra
    while (!intree[v]) {
        intree[v] = true;
        // Atualização das distâncias mínimas
        for (auto p : adj[v]) {
            int dest = p.destino;
            int peso = p.peso;
            if (!intree[dest] && distancia[dest] > distancia[v] + peso) {
                distancia[dest] = distancia[v] + peso;
                pai[dest] = v;
            }
        }

        // Encontrar o próximo vértice a ser adicionado à árvore de caminhos mínimos
        v = 0;
        int dist = INF;
        for (int u = 0; u < nVertices; ++u) {
            if (!intree[u] && dist > distancia[u]) {
                dist = distancia[u];
                v = u;
            }
        }
    }

    // Reconstrução do caminho mínimo
    int caminho[nVertices];
    int count = 0;
    int u = fim;
    while (u != -1) {
        caminho[count++] = u;
        u = pai[u];
    }

    cout << "Menor caminho: ";
    // Impressão do caminho mínimo e custo total
    for (int i = count - 1; i >= 0; --i) {
        cout << caminho[i] << " ";
    }
    cout << "\nCusto: " << distancia[fim] << endl;
}

int main() {
    // Leitura da entrada
    int nVertices, isDirecionado, inicio, fim;
    cin >> nVertices >> isDirecionado >> inicio >> fim;

    // Lista de adjacência para armazenar as arestas do grafo
    list<Aresta> adj[nVertices];

    // Leitura das arestas do grafo
    int origem, destino, peso;
    while (true) {
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1)
            break;

        // Adiciona a aresta à lista de adjacência
        adj[origem].push_back({origem, destino, peso});
        if (!isDirecionado) {
            adj[destino].push_back({destino, origem, peso});
        }
    }

    // Chama o algoritmo de Dijkstra
    dijkstra(adj, nVertices, inicio, fim);

    return 0;
}
