#include <iostream> 
using namespace std; 

struct NoArvore { // Define a estrutura de um nó da árvore
    int valor; // Valor do nó
    NoArvore* esquerda; // Ponteiro para o nó filho à esquerda
    NoArvore* direita; // Ponteiro para o nó filho à direita
};

NoArvore* criarNo(int valor) { // Função para criar um novo nó
    NoArvore* novoNo = new NoArvore(); // Aloca memória para o novo nó
    novoNo->valor = valor; // Atribui o valor ao nó
    novoNo->esquerda = novoNo->direita = NULL; // Inicializa os ponteiros dos nós filhos como NULL
    return novoNo; 
}

NoArvore* inserirNo(NoArvore* raiz, int valor) { // Função para inserir um nó na árvore
    if (raiz == NULL) { // Se a árvore estiver vazia
        raiz = criarNo(valor); // Cria um novo nó
    }
    else if (valor < raiz->valor) { // Se o valor for menor que o valor da raiz
        raiz->esquerda = inserirNo(raiz->esquerda, valor); // Insere o valor à esquerda
    }
    else { // Se o valor for maior ou igual ao valor da raiz
        raiz->direita = inserirNo(raiz->direita, valor); // Insere o valor à direita
    }
    return raiz; 
}

void imprimirNivel(NoArvore* raiz, int nivel) { // Função para imprimir os nós em um determinado nível
    if (raiz == NULL) return; // Se a árvore estiver vazia, retorna
    if (nivel == 1) cout << raiz->valor << " "; // Se o nível for 1, imprime o valor da raiz
    else if (nivel > 1) { // Se o nível for maior que 1
        imprimirNivel(raiz->esquerda, nivel-1); // Imprime os nós à esquerda
        imprimirNivel(raiz->direita, nivel-1); // Imprime os nós à direita
    }
}

int altura(NoArvore* no) { // Função para calcular a altura da árvore
    if (no == NULL) return 0; // Se a árvore estiver vazia, retorna 0
    else {
        int alturaEsquerda = altura(no->esquerda); // Calcula a altura da subárvore à esquerda
        int alturaDireita = altura(no->direita); // Calcula a altura da subárvore à direita
        if (alturaEsquerda > alturaDireita) return(alturaEsquerda + 1); // Retorna a maior altura + 1
        else return(alturaDireita + 1); // Retorna a maior altura + 1
    }
}

void deletarArvore(NoArvore* raiz) { // Função para deletar a árvore
    if (raiz == NULL) return; // Se a árvore estiver vazia, retorna

    deletarArvore(raiz->esquerda); // Deleta a subárvore à esquerda
    deletarArvore(raiz->direita); // Deleta a subárvore à direita

    delete raiz; 
}

int main() { 
    NoArvore* raiz = NULL; // Inicializa a raiz da árvore como NULL
    int valor; // Variável para armazenar o valor a ser inserido na árvore

    while (cin >> valor && valor != -1) { // Lê os valores até que -1 seja inserido
        raiz = inserirNo(raiz, valor); // Insere o valor na árvore
    }

    int h = altura(raiz); // Calcula a altura da árvore
    for (int i=1; i<=h; i++) imprimirNivel(raiz, i); // Imprime os nós em cada nível
    cout << endl; // 

    deletarArvore(raiz); // Deleta a árvore

    return 0; 
}