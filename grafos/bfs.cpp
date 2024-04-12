#include <iostream> // Inclui a biblioteca de entrada e saída padrão
#include <list> // Inclui a biblioteca de lista

using namespace std; // Usa o namespace padrão para evitar ter que digitar "std::" antes de cada uso de objetos e funções da biblioteca padrão

// Definição de uma estrutura 'no' para representar os vértices e pesos das arestas
struct no {
    int v, peso; // 'v' representa o vértice, 'peso' representa o peso da aresta
    no(int _v, int _peso) : v(_v), peso(_peso) {} // Construtor da estrutura
};

// Função para realizar uma busca em largura (BFS) em um grafo representado por uma lista de adjacências
void bfs(list<no> adj[], int nVertices, int s) {
    char estado[nVertices]; // Array para armazenar o estado de cada vértice ('u' para não descoberto, 'd' para descoberto, 'p' para processado)
    int pai[nVertices]; // Array para armazenar o pai de cada vértice durante a busca
    for (int u = 0; u < nVertices; u++) { // Inicialização dos arrays de estado e pai
        estado[u] = 'u'; // Inicialmente, todos os vértices são não descobertos
        pai[u] = -1; // Inicialmente, nenhum vértice tem pai definido
    }

    estado[s] = 'd'; // Marca o vértice inicial como descoberto
    pai[s] = -1; // O vértice inicial não tem pai
    list<int> fila; // Cria uma lista para armazenar os vértices a serem processados
    fila.push_back(s); // Adiciona o vértice inicial à fila

    while (!fila.empty()) { // Enquanto houver vértices na fila
        int u = fila.front(); // Obtém o primeiro vértice da fila
        fila.pop_front(); // Remove o primeiro vértice da fila
        cout << u << endl; // Imprime o vértice atual

        for (auto p = adj[u].begin(); p != adj[u].end(); p++) { // Percorre todos os vértices adjacentes ao vértice atual
            int v = p->v; // Obtém o vértice adjacente
            cout << u << " " << v << endl; // Imprime a aresta entre u e v

            if (estado[v] == 'u') { // Se o vértice adjacente ainda não foi descoberto
                estado[v] = 'd'; // Marca o vértice adjacente como descoberto
                pai[v] = u; // Define o pai do vértice adjacente como o vértice atual
                fila.push_back(v); // Adiciona o vértice adjacente à fila para ser processado posteriormente
            }
        }
        estado[u] = 'p'; // Marca o vértice atual como processado
    }
}

// Função principal
int main() {
    int nVertices, verticeInicial; // Declaração das variáveis para o número de vértices e o vértice inicial
    cin >> nVertices >> verticeInicial; // Lê o número de vértices e o vértice inicial a partir da entrada padrão

    list<no> adj[nVertices]; // Cria um array de listas para representar o grafo

    int u, v, peso; // Declaração das variáveis para as arestas e pesos
    while (true) { // Loop para ler as arestas e pesos até que uma condição de saída seja satisfeita
        cin >> u >> v >> peso; // Lê a próxima aresta e peso da entrada padrão
        if (u == -1 && v == -1 && peso == -1) // Se os valores lidos forem todos iguais a -1, encerra o loop
            break;
        adj[u].push_back(no(v, peso)); // Adiciona a aresta ao vértice u na lista de adjacências
        adj[v].push_back(no(u, peso)); // Assume um grafo não direcionado, então adiciona a mesma aresta ao vértice v
    }

    //cout << verticeInicial << endl; // Imprime uma mensagem indicando o início do percurso em largura
    bfs(adj, nVertices, verticeInicial); // Chama a função bfs para realizar o percurso em largura a partir do vértice inicial
    cout << endl; // Imprime uma linha em branco

    return 0; // Retorna 0 para indicar que o programa foi concluído com sucesso
}
