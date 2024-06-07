#include<iostream> 
using namespace std; 

// Estrutura para representar um nó da árvore
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
};

// Função para criar um novo nó com um valor específico
Node* newNode(int data) { 
    Node* node = new Node(); 
    node->data = data; 
    node->left = node->right = nullptr; 
    return node; 
}

// Função para inserir um novo valor na árvore
Node* insert(Node* node, int data) { 
    if (node == nullptr) { 
        return newNode(data); 
    }
    if (data < node->data) { 
        node->left = insert(node->left, data); 
    } else if (data > node->data) { 
        node->right = insert(node->right, data); 
    }
    return node; 
}

// Função para fazer uma travessia em ordem inversa da árvore (direita, raiz, esquerda)
void reverseInorder(Node* node) {
    if (node != nullptr) {
        reverseInorder(node->right);
        cout << node->data << " ";
        reverseInorder(node->left);
    }
}

// Função principal
int main() { 
    Node* root = nullptr; 
    int data; 
    cin >> data; 
    while (data != -1) { 
        root = insert(root, data); 
        cin >> data; 
    }
    reverseInorder(root);
    return 0; 
}