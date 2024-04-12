 #include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // Criando um array de arrays para representar as listas de adjacência
    int lista_adj[N + 1][N + 1] = {0}; // matriz de adjacência inicializando todos os elementos com 0

    // Lendo e armazenando os caminhos
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        // Adicionando os caminhos à lista de adjacência
        lista_adj[A][0]++; // Incrementa o número de conexões para a cidade A
        lista_adj[B][0]++; // Incrementa o número de conexões para a cidade B
        lista_adj[A][lista_adj[A][0]] = B; // Armazena B na próxima posição disponível de A
        lista_adj[B][lista_adj[B][0]] = A; // Armazena A na próxima posição disponível de B (bidirecional)
    }

    // Imprimindo as cidades conectadas diretamente a cada cidade
    for (int i = 1; i <= N; i++) {
        cout << lista_adj[i][0] << " "; // Imprime o número de cidades conectadas a cidade i
        for (int j = 1; j <= lista_adj[i][0]; j++) {
            cout << lista_adj[i][j] << " "; // Imprime as cidades conectadas a cidade i
        }
        cout << endl; // Nova linha para a próxima cidade
    }

    return 0;
}
