#include<iostream> 
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

// Função para contar o número de folhas na árvore
int contaFolhas(treenode* raiz) {
    if (raiz == nullptr) { // Se a árvore estiver vazia
        return 0; 
    }
    if (raiz->esquerda == nullptr && raiz->direita == nullptr) { // Se o nó for uma folha (não tem filhos)
        return 1; 
    }
    // Retorna a soma do número de folhas na subárvore à esquerda e na subárvore à direita
    return contaFolhas(raiz->esquerda) + contaFolhas(raiz->direita);
}


int main() { 
    treenode* raiz = nullptr; // Cria uma árvore vazia
    int valor; 
    cin >> valor; 
    // Loop para ler valores do usuário até que -1 seja inserido
    while (valor != -1) { 
        raiz = inserir(raiz, valor); // Insere o valor lido na árvore
        cin >> valor; // Lê o próximo valor
    }
    
    cout << contaFolhas(raiz) << endl;
    return 0; 
}