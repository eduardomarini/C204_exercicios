#include <iostream>  
#include <list>  
using namespace std;  

// Define uma estrutura para uma aresta com origem, destino e peso
struct Aresta {
    int origem;
    int destino;
    int peso;
};

// Função para implementar o algoritmo de Prim
int prim(list<Aresta> adj[], int nVertices) {
    bool intree[nVertices];  // Array para verificar se um vértice está incluído na MST
    int distance[nVertices];  // Array para armazenar o peso da aresta para a MST
    int parent[nVertices];  // Array para armazenar o pai de um vértice na MST

    // Inicializa todos os vértices como não incluídos na MST, com distância infinita e sem pai
    for (int u = 0; u < nVertices; ++u) {
        intree[u] = false;
        distance[u] = 999999;
        parent[u] = -1;
    }

    // Começa pelo primeiro vértice
    distance[0] = 0;
    int v = 0;

    // Enquanto houver vértices não incluídos na MST
    while (!intree[v]) {
        // Inclui o vértice na MST
        intree[v] = true;
        // Para todas as arestas do vértice
        for (auto p : adj[v]) {
            int dest = p.destino;
            int weight = p.peso;
            // Se o destino não está na MST e o peso é menor que a distância atual
            if (!intree[dest] && distance[dest] > weight) {
                // Atualiza a distância e o pai
                distance[dest] = weight;
                parent[dest] = v;
            }
        }

        // Encontra o vértice com a distância mínima não incluído na MST
        v = 0;
        int dist = 999999;
        for (int u = 0; u < nVertices; ++u) {
            if (!intree[u] && dist > distance[u]) {
                dist = distance[u];
                v = u;
            }
        }
    }

    // Calcula o custo total da MST
    int custo_total = 0;
    for (int u = 0; u < nVertices; ++u) {
        if (parent[u] != -1) {
            custo_total += distance[u];
        }
    }
    // Retorna o custo total
    return custo_total;
}

// Função principal
int main() {
    int nVertices, nArestas;  // Número de vértices e arestas
    cin >> nVertices >> nArestas;  // Lê o número de vértices e arestas

    list<Aresta> adj[nVertices];  // Lista de adjacência para o grafo

    int origem, destino, peso;  // Variáveis para a origem, destino e peso de uma aresta
    // Lê as arestas
    for (int i = 0; i < nArestas; ++i) {
        cin >> origem >> destino >> peso;  // Lê a origem, destino e peso
        --origem;  // Subtrai 1 da origem para começar de 0
        --destino;  // Subtrai 1 do destino para começar de 0
        // Adiciona a aresta à lista de adjacência
        adj[origem].push_back({origem, destino, peso});
        adj[destino].push_back({destino, origem, peso});
    }

    // Calcula o custo total da MST
    int custo_total = prim(adj, nVertices);
    cout << custo_total << endl;  // Imprime o custo total

    return 0;  // Fim do programa
}