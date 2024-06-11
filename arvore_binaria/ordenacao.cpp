#include<iostream> 
using namespace std; 

// Estrutura para representar um nó da árvore
struct Node { 
    int data; // Dado armazenado no nó
    Node* left; // Ponteiro para o filho à esquerda
    Node* right; // Ponteiro para o filho à direita
};

// Função para criar um novo nó com um valor específico
Node* newNode(int data) { 
    Node* node = new Node(); // Cria um novo nó
    node->data = data; // Atribui o valor ao nó
    node->left = node->right = nullptr; // Inicializa os ponteiros para os filhos como nulos
    return node; 
}

// Função para inserir um novo valor na árvore
Node* insert(Node* node, int data) { 
    if (node == nullptr) { // Se o nó é nulo, cria um novo nó com o valor
        return newNode(data); 
    }
    if (data < node->data) { // Se o valor é menor que o do nó, insere à esquerda
        node->left = insert(node->left, data); 
    } else if (data > node->data) { // Se o valor é maior que o do nó, insere à direita
        node->right = insert(node->right, data); 
    }
    return node; 
}

// Função para fazer uma travessia em ordem inversa da árvore (direita, raiz, esquerda)
void reverseInorder(Node* node) {
    if (node != nullptr) { // Se o nó não é nulo
        reverseInorder(node->right); // Visita o filho à direita
        cout << node->data << " "; 
        reverseInorder(node->left); // Visita o filho à esquerda
    }
}


int main() { 
    Node* root = nullptr; // Inicializa a raiz da árvore como nula
    int data; 
    cin >> data; 
    while (data != -1) { 
        root = insert(root, data); 
        cin >> data; 
    }
    reverseInorder(root); // Faz a travessia em ordem inversa da árvore
    return 0; 
}