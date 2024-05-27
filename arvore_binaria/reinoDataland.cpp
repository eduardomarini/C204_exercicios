#include <iostream>
using namespace std;

// Estrutura do nó da Árvore Binária de Busca (BST)
struct Node {
    int key;        // Valor armazenado no nó
    Node* left;     // Ponteiro para o filho à esquerda
    Node* right;    // Ponteiro para o filho à direita
};

// Função para criar um novo nó
Node* newNode(int item) {
    Node* temp = new Node;       // Aloca memória para um novo nó
    temp->key = item;            // Define o valor do nó
    temp->left = nullptr;        // Inicializa o filho à esquerda como nullptr
    temp->right = nullptr;       // Inicializa o filho à direita como nullptr
    return temp;                 // Retorna o ponteiro para o novo nó
}

// Função para inserir um novo nó na BST
Node* insert(Node* node, int key) {
    if (node == nullptr)         // Se a árvore está vazia, retorna um novo nó
        return newNode(key);
    if (key < node->key)         // Se o valor é menor que o valor do nó atual
        node->left = insert(node->left, key); // Insere no lado esquerdo
    else if (key > node->key)    // Se o valor é maior que o valor do nó atual
        node->right = insert(node->right, key); // Insere no lado direito
    return node;                 // Retorna o ponteiro do nó (inalterado)
}

// Função para encontrar o menor valor de um nó
Node* minValueNode(Node* node) {
    Node* current = node;        // Inicializa current como o nó dado
    while (current && current->left != nullptr) // Percorre para a esquerda até encontrar o menor valor
        current = current->left;
    return current;              // Retorna o nó com o menor valor
}

// Função para deletar um nó da BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)         // Se a árvore está vazia, retorna nullptr
        return root;
    if (key < root->key)         // Se o valor a ser deletado é menor que o valor do nó atual
        root->left = deleteNode(root->left, key); // Chama a função recursivamente para o filho à esquerda
    else if (key > root->key)    // Se o valor a ser deletado é maior que o valor do nó atual
        root->right = deleteNode(root->right, key); // Chama a função recursivamente para o filho à direita
    else {                       // Se o valor é igual ao valor do nó atual, este é o nó a ser deletado
        if (root->left == nullptr) { // Nó com um único filho ou sem filhos
            Node* temp = root->right; // Armazena o filho à direita
            delete root;             // Deleta o nó atual
            return temp;             // Retorna o filho à direita
        }
        else if (root->right == nullptr) { // Nó com um único filho ou sem filhos
            Node* temp = root->left;  // Armazena o filho à esquerda
            delete root;             // Deleta o nó atual
            return temp;             // Retorna o filho à esquerda
        }
        Node* temp = minValueNode(root->right); // Nó com dois filhos: obtém o sucessor
        root->key = temp->key;      // Copia o valor do sucessor para o nó atual
        root->right = deleteNode(root->right, temp->key); // Deleta o sucessor
    }
    return root;                    
}

// Função para buscar um nó na BST
bool search(Node* root, int key) {
    if (root == nullptr)            // Se a árvore está vazia, retorna falso
        return false;
    if (root->key == key)           // Se o valor é encontrado, retorna verdadeiro
        return true;
    if (root->key > key)            // Se o valor é menor que o valor do nó atual
        return search(root->left, key); // Busca no lado esquerdo
    return search(root->right, key); // Busca no lado direito
}

int main() {
    int N;                           
    cin >> N;
    Node* root = nullptr;            
    while (N--) {                    // Decrementa N a cada iteração e executa o loop enquanto N for maior que 0
        char op;                     // Tipo de operação ('i', 'r', 'b')
        int x;                       // Valor associado à operação
        cin >> op >> x;              // Lê a operação e o valor
        if (op == 'i') {             // Se a operação é inserção
            root = insert(root, x);  // Insere o valor na BST
        } else if (op == 'r') {      // Se a operação é remoção
            root = deleteNode(root, x); // Remove o valor da BST
        } else if (op == 'b') {      // Se a operação é busca
            if (search(root, x)) {   // Busca o valor na BST
                cout << "Sim" << endl; 
            } else {
                cout << "Não" << endl; 
            }
        }
    }
    return 0;                       
}
