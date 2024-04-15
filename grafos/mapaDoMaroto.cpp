#include <iostream>  // Inclui a biblioteca iostream para entrada e saída
#include <list>  // Inclui a biblioteca list para usar listas

using namespace std;  // Usa o namespace std para evitar ter que digitar std:: antes de cada uso de um elemento do namespace

int main() {  // Início da função principal
    int N, ehDirecionado;  // Declara duas variáveis inteiras, N (número de vértices) e ehDirecionado (se o grafo é direcionado ou não)
    cin >> N >> ehDirecionado;  // Lê N e ehDirecionado da entrada padrão

    list<list<pair<int, int>>> adj(N);  // Cria uma lista de listas de pares de inteiros para representar a lista de adjacências

    while (true) {  // Inicia um loop infinito
        int u, v, w;  // Declara três variáveis inteiras, u (vértice de origem), v (vértice de destino) e w (peso da aresta)
        cin >> u >> v >> w;  // Lê u, v e w da entrada padrão
        if (u == -1 && v == -1 && w == -1) break;  // Se u, v e w são todos -1, sai do loop

        // Adiciona a aresta à lista de adjacências do vértice de origem
        auto it_u = adj.begin();  // Cria um iterador para o início da lista de adjacências
        advance(it_u, u);  // Avança o iterador para a posição u
        it_u->push_back({v, w});  // Adiciona o par (v, w) à lista de adjacências do vértice u

        // Se o grafo não é direcionado, adiciona a aresta à lista de adjacências do vértice de destino
        if (!ehDirecionado) {  // Se ehDirecionado é falso (ou seja, o grafo não é direcionado)
            auto it_v = adj.begin();  // Cria um iterador para o início da lista de adjacências
            advance(it_v, v);  // Avança o iterador para a posição v
            it_v->push_back({u, w});  // Adiciona o par (u, w) à lista de adjacências do vértice v
        }
    }

    // Imprime a lista de adjacências
    int i = 0;  // Declara uma variável inteira i e inicializa com 0
    for (auto& lista_adj : adj) {  // Para cada lista de adjacências na lista de adjacências
        for (auto& aresta : lista_adj) {  // Para cada aresta na lista de adjacências
            cout << i << " " << aresta.first << " " << aresta.second << endl;  // Imprime i, o primeiro elemento da aresta (vértice de destino) e o segundo elemento da aresta (peso)
        }
        i++;  // Incrementa i
    }

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}  // Fim da função principal