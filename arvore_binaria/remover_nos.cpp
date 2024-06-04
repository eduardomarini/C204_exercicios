#include<iostream> 
using namespace std; 

struct treenode { // define a estrutura treenode
    int valor; // valor do nó
    treenode* esquerda; // ponteiro para o nó esquerdo
    treenode* direita; // ponteiro para o nó direito
};

treenode* novoNo(int valor) { // função para criar um novo nó
    treenode* no = new treenode; // cria um novo nó
    no->valor = valor; // atribui o valor ao nó
    no->esquerda = no->direita = nullptr; // inicializa os ponteiros esquerdo e direito como nullptr
    return no; // retorna o novo nó
}

treenode* inserir(treenode* raiz, int valor) { // função para inserir um valor na árvore
    if (raiz == nullptr) { // se a árvore estiver vazia
        return novoNo(valor); // cria um novo nó com o valor
    }
    if (valor < raiz->valor) { // se o valor for menor que o valor da raiz
        raiz->esquerda = inserir(raiz->esquerda, valor); // insere o valor na subárvore esquerda
    } else { // se o valor for maior ou igual ao valor da raiz
        raiz->direita = inserir(raiz->direita, valor); // insere o valor na subárvore direita
    }
    return raiz; // retorna a raiz da árvore
}

treenode* minValorNo(treenode* no) { // função para encontrar o nó com o valor mínimo na árvore
    treenode* atual = no; // nó atual é o nó dado
    while (atual && atual->esquerda != nullptr) { // enquanto o nó atual e o nó esquerdo do atual não forem nullptr
        atual = atual->esquerda; // vai para o nó esquerdo
    }
    return atual; // retorna o nó com o valor mínimo
}

treenode* remover(treenode* raiz, int valor) { // função para remover um valor da árvore
    if (raiz == nullptr) return raiz; // se a árvore estiver vazia, retorna nullptr
    if (valor < raiz->valor) { // se o valor for menor que o valor da raiz
        raiz->esquerda = remover(raiz->esquerda, valor); // remove o valor da subárvore esquerda
    } else if (valor > raiz->valor) { // se o valor for maior que o valor da raiz
        raiz->direita = remover(raiz->direita, valor); // remove o valor da subárvore direita
    } else { // se o valor for igual ao valor da raiz
        if (raiz->esquerda == nullptr) { // se o nó esquerdo for nullptr
            treenode* temp = raiz->direita; // guarda o nó direito em temp
            delete raiz; 
            return temp; 
        } else if (raiz->direita == nullptr) { // se o nó direito for nullptr
            treenode* temp = raiz->esquerda; // guarda o nó esquerdo em temp
            delete raiz; 
            return temp; 
        }
        treenode* temp = minValorNo(raiz->direita); // encontra o nó com o valor mínimo na subárvore direita
        if (temp->valor != valor) { // se o valor mínimo não for igual ao valor a ser removido
            raiz->valor = temp->valor; // substitui o valor da raiz pelo valor de temp
            raiz->direita = remover(raiz->direita, temp->valor); // remove o valor de temp da subárvore direita
        } else { // se o valor mínimo for igual ao valor a ser removido
            treenode* temp = raiz->direita; // guarda o nó direito em temp
            delete raiz; 
            return temp; 
        }
    }
    return raiz; // retorna a raiz da árvore
}

void imprimirOrdem(treenode* raiz) { 
    if (raiz != nullptr) { 
        imprimirOrdem(raiz->esquerda); 
        cout << raiz->valor << " "; 
        imprimirOrdem(raiz->direita); 
    }
}

int main() { 
    treenode* raiz = nullptr; // inicializa a raiz como nullptr
    int valor; 
    cin >> valor; 
    while (valor != 0) { 
        raiz = inserir(raiz, valor); 
        cin >> valor; 
    }
    int x; // valor a ser removido da árvore
    cin >> x; 
    raiz = remover(raiz, x); // remove x da árvore
    imprimirOrdem(raiz); 
    return 0; 
}