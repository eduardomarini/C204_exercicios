#include <iostream> 
#include <list> 
using namespace std; 

struct No { // Define uma estrutura para os nós do grafo
    int valor; // Valor do nó
    No* proximo; // Ponteiro para o próximo nó
};

void visita_dfs(int u, list<No*> adj[], bool visitado[]) { // Função que realiza a visita em profundidade a partir de um vértice u
    visitado[u] = true; // Marca o vértice u como visitado
    cout << u << " "; // Imprime o vértice u
    for (No* p : adj[u]) { // Para cada vértice adjacente a u
        int v = p->valor; // Obtém o valor do vértice adjacente
        if (!visitado[v]) { // Se o vértice adjacente ainda não foi visitado
            visita_dfs(v, adj, visitado); // Visita o vértice adjacente
        }
    }
}

void dfs(list<No*> adj[], int nVertices) { // Função que realiza a busca em profundidade no grafo
    bool visitado[nVertices]; // Array para marcar os vértices visitados
    for (int u = 0; u < nVertices; u++) { // Para cada vértice do grafo
        visitado[u] = false; // Inicializa o vértice como não visitado
    }
    for (int u = 0; u < nVertices; u++) { // Para cada vértice do grafo
        if (!visitado[u]) { // Se o vértice ainda não foi visitado
            visita_dfs(u, adj, visitado); // Realiza a visita em profundidade a partir do vértice
        }
    }
}

int main() { // Função principal
    int nVertices, ehDirecionado; // Número de vértices e flag para indicar se o grafo é direcionado
    cin >> nVertices >> ehDirecionado; // Lê o número de vértices e a flag de direcionamento
    list<No*> adj[nVertices]; // Lista de adjacências para representar o grafo
    while (true) { // Loop para ler as arestas do grafo
        int u, v; // Vértices da aresta
        cin >> u >> v; // Lê os vértices da aresta
        if (u == -1 && v == -1) break; // Se os vértices são -1, termina a leitura das arestas
        No* p = new No; // Cria um novo nó
        p->valor = v; // Atribui o valor do vértice ao nó
         p->proximo = nullptr; // Certifique-se de que o próximo nó seja inicializado como nullptr
        adj[u].push_back(p); // Adiciona o nó à lista de adjacências do vértice u
        if (!ehDirecionado) { // Se o grafo não é direcionado
            No* q = new No; // Cria um novo nó
            q->valor = u; // Atribui o valor do vértice ao nó
            q->proximo = nullptr; // Certifique-se de que o próximo nó seja inicializado como nullptr
            adj[v].push_back(q); // Adiciona o nó à lista de adjacências do vértice v
        }
    }
    dfs(adj, nVertices); // Realiza a busca em profundidade no grafo
    return 0; // Termina a execução do programa
}