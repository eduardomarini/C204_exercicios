#include <iostream>
#include <list>

using namespace std;

// Função para adicionar uma aresta não direcionada ao grafo
void addAresta(list<int> *adj, int u, int v) {
    adj[u].push_back(v); // adicionando o vértive "v" a lista de adjacência do vértice "u" (grafo não direcionado)
    adj[v].push_back(u); // adicionando o vértive "u" a lista de adjacência do vértice "v" (grafo não direcionado)
}

// Função que realiza a busca em largura (BFS) a partir de um vértice de origem
bool bfs(list<int> *adj, int vertices, int origem) {
    bool *visitado = new bool[vertices]; // Vetor para marcar os vértices visitados
    for (int i = 0; i < vertices; ++i) {
        visitado[i] = false;
    }

    list<int> fila_visitacao; // Lista para a BFS

    // Marca o vértice inicial como visitado e o insere na fila
    visitado[origem] = true;
    fila_visitacao.push_back(origem);

    // Enquanto a fila não estiver vazia, continua a BFS
    while (!fila_visitacao.empty()) {
        int u = fila_visitacao.front(); // Obtém o vértice da frente da fila
        fila_visitacao.pop_front();

        // Percorre todos os vértices adjacentes ao vértice atual
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            // Se o vértice ainda não foi visitado, marca como visitado e o insere na fila
            if (!visitado[*it]) {
                visitado[*it] = true;
                fila_visitacao.push_back(*it);
            }
        }
    }

    // Verifica se todos os vértices foram visitados
    for (int i = 0; i < vertices; ++i) {
        // Se algum vértice não foi visitado, o grafo não é conexo
        if (!visitado[i]) {
            delete[] visitado;
            return false;
        }
    }

    delete[] visitado;
    // Se todos os vértices foram visitados, o grafo é conexo
    return true;
}

int main() {
    int num_vertices, vertice_inicial;
    cin >> num_vertices >> vertice_inicial;

    // Aloca memória para a lista de adjacências
    list<int> *adj = new list<int>[num_vertices];

    int u, v; // vértice de origem e destino de uma aresta
    cin >> u >> v;

    // Enquanto a entrada não for -1 -1, adiciona arestas ao grafo
    while (u != -1 && v != -1) {
        addAresta(adj, u, v);
        cin >> u >> v;
    }

    // Verifica se o grafo é conexo a partir do vértice inicial
    if (bfs(adj, num_vertices, vertice_inicial)) {
        cout << "Conexo" << endl;
    } else {
        cout << "Nao conexo" << endl;
    }

    // Libera a memória alocada para a lista de adjacências
    delete[] adj;

    return 0;
}
