#include <iostream> // Inclui a biblioteca de entrada e saída padrão
#include <list> // Inclui a biblioteca para usar a estrutura de dados lista

using namespace std; // Permite usar os elementos padrão da biblioteca C++ sem prefixo

void dfs(int v, list<list<int>>& adj, list<bool>& visitados) { // Define uma função de busca em profundidade
    auto it = visitados.begin(); // Declara um iterador para a lista de visitados
    advance(it, v); // Move o iterador para a posição 'v'
    *it = true; // Marca o vértice 'v' como visitado
    auto it_adj = adj.begin(); // Declara um iterador para a lista de adjacência
    advance(it_adj, v); // Move o iterador para a lista de adjacência do vértice 'v'
    for (int u : *it_adj) { // Loop sobre todos os vértices adjacentes a 'v'
        auto it_visitado = visitados.begin(); // Declara um iterador para a lista de visitados
        advance(it_visitado, u); // Move o iterador para o vértice adjacente 'u'
        if (!(*it_visitado)) // Verifica se o vértice 'u' ainda não foi visitado
            dfs(u, adj, visitados); // Chama recursivamente a busca em profundidade para o vértice 'u'
    }
}

int main() { // Função principal do programa
    int N, M; // Declaração das variáveis N (número de vértices) e M (número de arestas)
    cin >> N >> M; // Lê os valores de N e M a partir da entrada padrão

    list<list<int>> adj; // Declara uma lista de listas para representar o grafo
    for(int i = 0; i < N; i++) { // Loop para inicializar as listas de adjacência
        list<int> lista_adj; // Declara uma lista para os vértices adjacentes ao vértice 'i'
        adj.push_back(lista_adj); // Adiciona a lista de adjacência do vértice 'i' à lista de adjacências
    }

    for(int i = 0; i < M; i++) { // Loop para ler as arestas do grafo
        int A, B; // Declaração das variáveis A e B representando uma aresta de 'A' para 'B'
        cin >> A >> B; // Lê os vértices 'A' e 'B' representando uma aresta
        A--; B--; // Converte para índices 0-indexados
        auto it_A = adj.begin(); // Declara um iterador para a lista de adjacência do vértice 'A'
        advance(it_A, A); // Move o iterador para a lista de adjacência do vértice 'A'
        it_A->push_back(B); // Adiciona o vértice 'B' à lista de adjacência do vértice 'A'
        auto it_B = adj.begin(); // Declara um iterador para a lista de adjacência do vértice 'B'
        advance(it_B, B); // Move o iterador para a lista de adjacência do vértice 'B'
        it_B->push_back(A); // Adiciona o vértice 'A' à lista de adjacência do vértice 'B'
    }

    int X, Y; // Declaração das variáveis X e Y representando uma aresta a ser removida
    cin >> X >> Y; // Lê os vértices X e Y representando a aresta a ser removida
    X--; Y--; // Converte para índices 0-indexados

    // Remove a aresta
    auto it_X = adj.begin(); // Declara um iterador para a lista de adjacência do vértice 'X'
    advance(it_X, X); // Move o iterador para a lista de adjacência do vértice 'X'
    it_X->remove(Y); // Remove o vértice 'Y' da lista de adjacência do vértice 'X'
    auto it_Y = adj.begin(); // Declara um iterador para a lista de adjacência do vértice 'Y'
    advance(it_Y, Y); // Move o iterador para a lista de adjacência do vértice 'Y'
    it_Y->remove(X); // Remove o vértice 'X' da lista de adjacência do vértice 'Y'

    list<bool> visitados(N, false); // Declara uma lista de booleanos para marcar os vértices visitados
    dfs(X, adj, visitados); // Chama a função de busca em profundidade a partir do vértice 'X'

    // Imprime todas as cidades que se tornam inacessíveis
    int i = 0; // Declaração de uma variável de controle 'i'
    for (auto it = visitados.begin(); it != visitados.end(); ++it, ++i) { // Loop sobre todos os vértices
        if (!(*it)) { // Verifica se o vértice não foi visitado
            cout << i+1 << " "; // Imprime o índice do vértice 1-indexado
        }
    }

    return 0; // Indica que o programa foi executado com sucesso
}
