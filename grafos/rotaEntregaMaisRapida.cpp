#include <iostream>  
#include <list> 
using namespace std;  

const int INF = 1e9;  // Define uma constante para representar infinito

struct Aresta {  // Define uma estrutura para representar uma aresta
    int origem, destino, peso;  // Cada aresta tem uma origem, um destino e um peso
};

void dijkstra(list<Aresta> adj[], int nVertices, int inicio, int fim) {  // Função para executar o algoritmo de Dijkstra
    bool intree[nVertices];  // Array para verificar se um vértice está na árvore
    int distancia[nVertices];  // Array para armazenar a distância de cada vértice ao vértice inicial
    int pai[nVertices];  // Array para armazenar o pai de cada vértice

    for (int u = 0; u < nVertices; ++u) {  // Inicializa os arrays
        intree[u] = false;  // Nenhum vértice está na árvore no início
        distancia[u] = INF;  // A distância inicial para todos os vértices é infinita
        pai[u] = -1;  // O pai inicial de todos os vértices é indefinido
    }

    distancia[inicio] = 0;  // A distância do vértice inicial para ele mesmo é 0
    int v = inicio;  // Começa pelo vértice inicial

    while (!intree[v]) {  // Enquanto o vértice v não estiver na árvore
        intree[v] = true;  // Adiciona o vértice v na árvore
        for (auto p : adj[v]) {  // Para cada aresta que sai do vértice v
            int dest = p.destino;  // Obtém o destino da aresta
            int peso = p.peso;  // Obtém o peso da aresta
            if (!intree[dest] && distancia[dest] > distancia[v] + peso) {  // Se o destino não está na árvore e a distância conhecida é maior que a nova distância
                distancia[dest] = distancia[v] + peso;  // Atualiza a distância
                pai[dest] = v;  // Atualiza o pai
            }
        }

        v = 0;  // Reinicia o vértice v
        int dist = INF;  // Reinicia a distância
        for (int u = 0; u < nVertices; ++u) {  // Para cada vértice u
            if (!intree[u] && dist > distancia[u]) {  // Se u não está na árvore e a distância conhecida é maior que a nova distância
                dist = distancia[u];  // Atualiza a distância
                v = u;  // Atualiza o vértice v
            }
        }
    }

    cout << distancia[fim] << endl;  // Imprime a distância do vértice inicial ao vértice final
}

int main() {  // Função principal
    int nVertices, nEstradas;  // Declara as variáveis para o número de vértices e arestas
    cin >> nVertices >> nEstradas;  // Lê o número de vértices e arestas

    list<Aresta> adj[nVertices];  // Cria uma lista de adjacências para cada vértice

    for (int i = 0; i < nEstradas; i++) {  // Para cada aresta
        int origem, destino, peso;  // Declara as variáveis para a origem, destino e peso
        cin >> origem >> destino >> peso;  // Lê a origem, destino e peso
        origem--; destino--;  // Ajusta para 0-indexação
        adj[origem].push_back({origem, destino, peso});  // Adiciona a aresta na lista de adjacências da origem
        adj[destino].push_back({destino, origem, peso});  // Adiciona a aresta na lista de adjacências do destino (para grafos não direcionados)
    }

    int inicio, fim;  // Declara as variáveis para o vértice inicial e final
    cin >> inicio >> fim;  // Lê o vértice inicial e final
    inicio--; fim--;  // Ajusta para 0-indexação

    dijkstra(adj, nVertices, inicio, fim);  // Executa o algoritmo de Dijkstra

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}