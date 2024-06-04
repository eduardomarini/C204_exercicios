#include<iostream>  
using namespace std; 

struct treenode {  // Define uma estrutura para os nós da árvore
    int valor;  // Valor do nó
    treenode* esquerda;  // Ponteiro para o filho à esquerda
    treenode* direita;  // Ponteiro para o filho à direita
};

treenode* novoNo(int valor) {  // Função para criar um novo nó
    treenode* no = new treenode;  // Aloca memória para o novo nó
    no->valor = valor;  // Atribui o valor ao nó
    no->esquerda = no->direita = nullptr;  // Inicializa os ponteiros para os filhos como nulos
    return no;  // Retorna o novo nó
}

treenode* inserir(treenode* raiz, int valor) {  // Função para inserir um valor na árvore
    if (raiz == nullptr) {  // Se a árvore estiver vazia
        return novoNo(valor);  // Cria um novo nó com o valor e retorna
    }
    if (valor < raiz->valor) {  // Se o valor for menor que o valor da raiz
        raiz->esquerda = inserir(raiz->esquerda, valor);  // Insere o valor na subárvore à esquerda
    } else {  // Se o valor for maior ou igual ao valor da raiz
        raiz->direita = inserir(raiz->direita, valor);  // Insere o valor na subárvore à direita
    }
    return raiz;  // Retorna a raiz da árvore
}

int menor(treenode* raiz) {  // Função para encontrar o menor valor na árvore
    treenode* atual = raiz;  // Começa pela raiz
    while (atual && atual->esquerda != nullptr) {  // Enquanto houver um nó à esquerda
        atual = atual->esquerda;  // Vai para o nó à esquerda
    }
    return atual->valor;  // Retorna o valor do nó mais à esquerda, que é o menor valor
}

int maior(treenode* raiz) {  // Função para encontrar o maior valor na árvore
    treenode* atual = raiz;  // Começa pela raiz
    while (atual && atual->direita != nullptr) {  // Enquanto houver um nó à direita
        atual = atual->direita;  // Vai para o nó à direita
    }
    return atual->valor;  // Retorna o valor do nó mais à direita, que é o maior valor
}

int main() {  // Função principal
    treenode* raiz = nullptr;  // Inicializa a raiz da árvore como nula
    int valor;  
    cin >> valor;  
    while (valor != -1) {  
        raiz = inserir(raiz, valor);  // Insere o valor na árvore
        cin >> valor;  
    }
    cout << menor(raiz) << " e " << maior(raiz) << endl;  
    return 0;  
}