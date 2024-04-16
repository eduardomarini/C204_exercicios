#include <iostream>

// Função para retornar o maior entre dois números
int maximo(int a, int b) { return (a > b) ? a : b; }

// Função para resolver o problema da mochila
int mochila(int W, int peso[], int valor[], int n) {
    // Criando a tabela para armazenar os valores máximos
    int K[n + 1][W + 1];
    // Preenchendo a tabela
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Inicializando a primeira linha e coluna com 0
            if (i == 0 || w == 0)
                K[i][w] = 0;
            // Se o peso do item for menor ou igual à capacidade da mochila
            else if (peso[i - 1] <= w)
                // Escolha o máximo entre o valor do item mais o valor da mochila sem esse item
                // e o valor máximo da mochila sem considerar esse item
                K[i][w] = maximo(valor[i - 1] + K[i - 1][w - peso[i - 1]], K[i - 1][w]);
            else
                // Se o peso do item for maior que a capacidade da mochila
                // então o valor máximo será o valor da mochila sem considerar esse item
                K[i][w] = K[i - 1][w];
        }
    }
    // Retornando o valor máximo que pode ser colocado na mochila
    return K[n][W];
}

// Função principal
int main() {
    // Número de testes
    int testes;
    std::cin >> testes;
    // Executando cada teste
    while (testes--) {
        // Número de itens
        int itens;
        std::cin >> itens;
        // Vetores para armazenar os valores e pesos dos itens
        int destruicao[itens], peso[itens];
        // Lendo os valores e pesos dos itens
        for (int i = 0; i < itens; i++) {
            std::cin >> destruicao[i] >> peso[i];
        }
        // Capacidade da mochila e resistência do castelo
        int capacidade, resistencia;
        std::cin >> capacidade >> resistencia;
        // Calculando o valor máximo que pode ser colocado na mochila
        int destruicaoTotal = mochila(capacidade, peso, destruicao, itens);
        // Verificando se a destruição total é maior ou igual à resistência do castelo
        if (destruicaoTotal >= resistencia) {
            std::cout << "Missao completada com sucesso\n";
        } else {
            std::cout << "Falha na missao\n";
        }
    }
    // Retornando 0 para indicar que o programa terminou com sucesso
    return 0;
}