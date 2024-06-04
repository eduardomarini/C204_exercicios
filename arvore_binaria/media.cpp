#include<iostream> 
#include<iomanip> 
using namespace std; 

// Estrutura para representar um nó da árvore
struct treenode { 
    int valor; // Valor armazenado no nó
    treenode* esquerda; // Ponteiro para o nó filho à esquerda
    treenode* direita; // Ponteiro para o nó filho à direita
};

// Função para criar um novo nó com um valor específico
treenode* novoNo(int valor) { 
    treenode* no = new treenode; // Cria um novo nó
    no->valor = valor; // Atribui o valor ao nó
    no->esquerda = no->direita = nullptr; // Inicializa os ponteiros para os nós filhos como nulos
    return no; // Retorna o nó criado
}

// Função para inserir um novo valor na árvore
treenode* inserir(treenode* raiz, int valor) { 
    if (raiz == nullptr) { // Se a árvore estiver vazia
        return novoNo(valor); // Cria um novo nó com o valor e retorna
    }
    if (valor < raiz->valor) { // Se o valor for menor que o valor da raiz
        raiz->esquerda = inserir(raiz->esquerda, valor); // Insere o valor na subárvore à esquerda
    } else { // Se o valor for maior ou igual ao valor da raiz
        raiz->direita = inserir(raiz->direita, valor); // Insere o valor na subárvore à direita
    }
    return raiz; 
}

// Variáveis globais para armazenar a soma dos valores dos nós e o número total de nós
int soma = 0;
int contagem = 0;

// Função para calcular a soma dos valores dos nós e o número total de nós
void calcularSomaEContagem(treenode* raiz) {
    if (raiz != nullptr) { // Se a árvore não estiver vazia
        calcularSomaEContagem(raiz->esquerda); // Calcula a soma e a contagem para a subárvore à esquerda
        soma += raiz->valor; // Adiciona o valor do nó à soma
        contagem++; // Incrementa a contagem
        calcularSomaEContagem(raiz->direita); // Calcula a soma e a contagem para a subárvore à direita
    }
}

// Função para calcular a média dos valores dos nós
float media(treenode* raiz) {
    calcularSomaEContagem(raiz); // Calcula a soma e a contagem
    return (float)soma / contagem; // Calcula e retorna a média
}


int main() { 
    treenode* raiz = nullptr; // Cria uma árvore vazia
    int valor; 
    cin >> valor; 
    
    while (valor != -1) { 
        raiz = inserir(raiz, valor); // Insere o valor lido na árvore
        cin >> valor; // Lê o próximo valor
    }
    
    cout << "Media: " << fixed << setprecision(2) << media(raiz) << endl;
    return 0; 
}