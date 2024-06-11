#include <iostream> 
using namespace std; 

struct NoArvore { // Define a estrutura de um nó da árvore
    int dado; // Valor armazenado no nó
    NoArvore* esquerda; // Ponteiro para o nó filho à esquerda
    NoArvore* direita; // Ponteiro para o nó filho à direita
};

NoArvore* criarNo(int dado) { // Função para criar um novo nó
    NoArvore* novoNo = new NoArvore(); // Aloca memória para o novo nó
    if (!novoNo) { // Se a alocação falhar
        cout << "Erro de memória\n"; // Imprime uma mensagem de erro
        return NULL; 
    }
    novoNo->dado = dado; // Atribui o valor ao nó
    novoNo->esquerda = novoNo->direita = NULL; // Inicializa os ponteiros para os nós filhos como NULL
    return novoNo; 
}

NoArvore* inserirNo(NoArvore* raiz, int dado) { // Função para inserir um nó na árvore
    if (raiz == NULL) { // Se a árvore estiver vazia
        raiz = criarNo(dado); // Cria um novo nó com o valor dado
        return raiz; 
    }

    if (dado < raiz->dado) { // Se o valor for menor que o valor da raiz
        raiz->esquerda = inserirNo(raiz->esquerda, dado); // Insere o valor na subárvore à esquerda
    }
    else { // Se o valor for maior ou igual ao valor da raiz
        raiz->direita = inserirNo(raiz->direita, dado); // Insere o valor na subárvore à direita
    }

    return raiz; 
}

bool ehPrimo(int n) { // Função para verificar se um número é primo
    if (n <= 1) return false; // Se o número for menor ou igual a 1, não é primo
    if (n <= 3) return true; // Se o número for 2 ou 3, é primo

    if (n % 2 == 0 || n % 3 == 0) return false; // Se o número for divisível por 2 ou 3, não é primo

    for (int i = 5; i * i <= n; i = i + 6) { // Para i de 5 até a raiz quadrada de n
        if (n % i == 0 || n % (i + 2) == 0) return false; // Se o número for divisível por i ou i+2, não é primo
    }

    return true; // Se passou por todas as verificações, o número é primo
}

int contarPrimos(NoArvore* raiz) { // Função para contar os números primos na árvore
    if (raiz == NULL) return 0; // Se a árvore estiver vazia, retorna 0

    int contagem = ehPrimo(raiz->dado) ? 1 : 0; // Se o valor da raiz for primo, contagem é 1, senão é 0

    return contagem + contarPrimos(raiz->esquerda) + contarPrimos(raiz->direita); // Retorna a contagem da raiz mais a contagem das subárvores à esquerda e à direita
}

int main() { // Função principal
    NoArvore* raiz = NULL; // Inicializa a raiz da árvore como NULL
    int dado; // Variável para armazenar os valores lidos da entrada

    while (cin >> dado && dado != -1) { // Enquanto for possível ler um valor da entrada e esse valor for diferente de -1
        raiz = inserirNo(raiz, dado); // Insere o valor lido na árvore
    }

    cout << contarPrimos(raiz) << " numeros primos\n"; 

    return 0; 
}