#include <iostream> 
#include <list> 
using namespace std; 

// Estrutura para representar uma aresta
struct Aresta {
    int origem; // Vértice de origem da aresta
    int destino; // Vértice de destino da aresta
    int peso; // Peso da aresta
};

// Função para implementar o algoritmo de Prim
void prim(list<Aresta> adj[], int nVertices, int start) {
    bool intree[nVertices]; // Array para armazenar se o vértice está na árvore ou não
    int distance[nVertices]; // Array para armazenar as distâncias dos vértices à árvore
    int parent[nVertices];   // Array para armazenar os pais dos vértices na árvore

    // Inicialização
    for (int u = 0; u < nVertices; ++u) {
        intree[u] = false; // Inicialmente, nenhum vértice está na árvore
        distance[u] = 999999; // Inicialmente, a distância de todos os vértices à árvore é infinita
        parent[u] = -1; // Inicialmente, nenhum vértice tem um pai
    }

    distance[start] = 0; // A distância do vértice inicial à árvore é 0
    int v = start; // Começa pelo vértice inicial

    // Loop principal do algoritmo de Prim
    while (!intree[v]) { // Enquanto o vértice v não estiver na árvore
        intree[v] = true; // Adiciona o vértice v à árvore
        for (auto p : adj[v]) { // Para cada aresta que sai de v
            int dest = p.destino; // Obtém o vértice de destino da aresta
            int weight = p.peso; // Obtém o peso da aresta
            if (!intree[dest] && distance[dest] > weight) { // Se o vértice de destino não estiver na árvore e a distância dele à árvore for maior que o peso da aresta
                distance[dest] = weight; // Atualiza a distância do vértice de destino à árvore
                parent[dest] = v; // Atualiza o pai do vértice de destino
            }
        }

        // Encontrar o próximo vértice a ser adicionado à árvore
        v = 0; // Inicializa o próximo vértice a ser adicionado à árvore
        int dist = 999999; // Inicializa a distância do próximo vértice à árvore
        for (int u = 0; u < nVertices; ++u) { // Para cada vértice u
            if (!intree[u] && dist > distance[u]) { // Se u não estiver na árvore e a distância de u à árvore for menor que a distância atual
                dist = distance[u]; // Atualiza a distância
                v = u; // Atualiza o próximo vértice a ser adicionado à árvore
            }
        }
    }

    int custo_total = 0; // Inicializa o custo total da árvore geradora mínima

    // Imprimir a árvore geradora mínima
    cout << "Arvore Geradora Minima:" << endl;
    for (int u = 0; u < nVertices; ++u) { // Para cada vértice u
        if (parent[u] != -1) { // Se u tem um pai
            cout << parent[u] << " " << u << endl; // Imprime a aresta do pai de u a u
        }
        custo_total += distance[u]; // Adiciona a distância de u à árvore ao custo total
    }
    cout << "Custo: " << custo_total << endl; // Imprime o custo total da árvore geradora mínima
}

int main() {
    // Número de vértices, se o grafo é orientado (1) ou não (0) e vértice inicial
    int nVertices, isDirected, start;
    cin >> nVertices >> isDirected >> start; // Lê o número de vértices, se o grafo é orientado ou não e o vértice inicial

    // Lista de adjacência para representar o grafo
    list<Aresta> adj[nVertices]; // Cria uma lista de adjacência para cada vértice

    // Ler os pesos das arestas até encontrar o fim da entrada
    int origem, destino, peso;
    while (true) { // Loop infinito
        cin >> origem >> destino >> peso; // Lê a origem, o destino e o peso de uma aresta
        if (origem == -1 && destino == -1 && peso == -1)
            break; // Se a origem, o destino e o peso forem -1, termina o loop

        // Adicionar a aresta nos dois sentidos, se o grafo for não direcionado
        adj[origem].push_back({origem, destino, peso}); // Adiciona a aresta da origem ao destino
        if (!isDirected) { // Se o grafo for não direcionado
            adj[destino].push_back({destino, origem, peso}); // Adiciona a aresta do destino à origem
        }
    }

    // Encontrar a Árvore Geradora Mínima usando o algoritmo de Prim
    prim(adj, nVertices, start); // Chama a função prim para encontrar a Árvore Geradora Mínima

    return 0; // Termina o programa
}