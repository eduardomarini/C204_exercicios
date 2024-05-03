#include <iostream> 
using namespace std; 

struct Node { // Define uma estrutura para os nós da árvore
    int data; // Valor do nó
    Node* left; // Ponteiro para o filho à esquerda
    Node* right; // Ponteiro para o filho à direita
};

Node* newNode(int data) { // Função para criar um novo nó
    Node* node = new Node(); // Aloca memória para o novo nó
    node->data = data; // Atribui o valor ao nó
    node->left = NULL; // Inicializa o filho à esquerda como NULL
    node->right = NULL; // Inicializa o filho à direita como NULL
    return node; // Retorna o novo nó
}

Node* insert(Node* node, int data) { // Função para inserir um novo valor na árvore
    if (node == NULL) { // Se o nó atual é NULL (ou seja, a árvore está vazia ou chegamos a uma folha)
        return newNode(data); // Cria um novo nó com o valor
    }
    if (data < node->data) { // Se o valor é menor que o valor do nó atual
        node->left = insert(node->left, data); // Insere o valor na subárvore à esquerda
    } else if (data > node->data) { // Se o valor é maior que o valor do nó atual
        node->right = insert(node->right, data); // Insere o valor na subárvore à direita
    }
    return node; // Retorna o nó atual
}

bool search(Node* raiz, int x) { // Função para buscar um valor na árvore
    if (raiz == NULL) { // Se a árvore está vazia ou chegamos a uma folha sem encontrar o valor
        return false; // Retorna falso
    } else if (raiz->data == x) { // Se o valor do nó atual é igual ao valor procurado
        return true; // Retorna verdadeiro
    } else if (raiz->data > x) { // Se o valor do nó atual é maior que o valor procurado
        return search(raiz->left, x); // Busca o valor na subárvore à esquerda
    } else { // Se o valor do nó atual é menor que o valor procurado
        return search(raiz->right, x); // Busca o valor na subárvore à direita
    }
}

int main() { // Função principal
    Node* raiz = NULL; // Inicializa a árvore como vazia
    int N, X; // Declara as variáveis N (número de elementos a inserir) e X (elemento a procurar)
    cin >> N; // Lê o valor de N
    for (int i = 0; i < N; i++) { // Para cada elemento a inserir
        int num; // Declara a variável num (elemento a inserir)
        cin >> num; // Lê o valor de num
        raiz = insert(raiz, num); // Insere num na árvore
    }
    cin >> X; // Lê o valor de X
    if (search(raiz, X)) { // Se X está na árvore
        cout << "Encontrado" << endl; // Imprime "Encontrado"
    } else { // Se X não está na árvore
        cout << "Nao encontrado" << endl; // Imprime "Nao encontrado"
    }
    return 0; // Termina o programa
}