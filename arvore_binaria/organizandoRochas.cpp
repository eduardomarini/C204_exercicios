#include <iostream> 
#include <string> 
using namespace std; 

// Definição da estrutura de um nó da árvore binária de busca
struct Node {
    string nome; // Nome da rocha
    string tipo; // Tipo da rocha
    Node* left; // Ponteiro para o filho esquerdo
    Node* right; // Ponteiro para o filho direito

    // Construtor do nó, inicializando nome, tipo, e ponteiros para null
    Node(string n, string t) : nome(n), tipo(t), left(nullptr), right(nullptr) {}
};

// Definição da classe BST (Binary Search Tree)
class BST {
private:
    Node* root; // Ponteiro para a raiz da árvore

    // Função recursiva para inserir um novo nó na árvore
    Node* insert(Node* node, string nome, string tipo) {
        if (node == nullptr) {
            return new Node(nome, tipo); // Cria um novo nó se a posição estiver vazia
        }
        if (nome < node->nome) {
            node->left = insert(node->left, nome, tipo); // Insere na subárvore esquerda
        } else if (nome > node->nome) {
            node->right = insert(node->right, nome, tipo); // Insere na subárvore direita
        }
        return node; // Retorna o ponteiro do nó atual
    }

    // Função recursiva para buscar um nó pelo nome
    Node* search(Node* node, string nome) {
        if (node == nullptr || node->nome == nome) {
            return node; // Retorna o nó se encontrado ou null se não encontrado
        }
        if (nome < node->nome) {
            return search(node->left, nome); // Busca na subárvore esquerda
        }
        return search(node->right, nome); // Busca na subárvore direita
    }

    // Função recursiva para remover um nó da árvore
    Node* remove(Node* node, string nome, string tipo, bool& removed) {
        if (node == nullptr) {
            removed = false; // Se o nó não existir, marca que não foi removido
            return node;
        }
        if (nome < node->nome) {
            node->left = remove(node->left, nome, tipo, removed); // Remove da subárvore esquerda
        } else if (nome > node->nome) {
            node->right = remove(node->right, nome, tipo, removed); // Remove da subárvore direita
        } else {
            if (node->tipo != tipo) {
                removed = false; // Se o tipo não corresponder, marca que não foi removido
                return node;
            }
            if (node->left == nullptr) {
                Node* temp = node->right; // Nó sem filho esquerdo
                delete node; // Deleta o nó atual
                removed = true; // Marca que foi removido
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left; // Nó sem filho direito
                delete node; // Deleta o nó atual
                removed = true; // Marca que foi removido
                return temp;
            }
            Node* temp = findMin(node->right); // Encontra o menor nó na subárvore direita
            node->nome = temp->nome; // Substitui o nome pelo menor nó da subárvore direita
            node->tipo = temp->tipo; // Substitui o tipo pelo menor nó da subárvore direita
            node->right = remove(node->right, temp->nome, temp->tipo, removed); // Remove o menor nó encontrado
        }
        return node; // Retorna o ponteiro do nó atual
    }

    // Função auxiliar para encontrar o nó com o menor valor (mais à esquerda)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left; // Continua indo para a esquerda até encontrar o menor nó
        }
        return node; // Retorna o menor nó encontrado
    }

public:
    // Construtor da árvore inicializando a raiz como null
    BST() : root(nullptr) {}

    // Função pública para inserir um novo nó na árvore
    void insert(string nome, string tipo) {
        root = insert(root, nome, tipo); // Chama a função recursiva de inserção
    }

    // Função pública para buscar um nó pelo nome
    void search(string nome) {
        Node* result = search(root, nome); // Chama a função recursiva de busca
        if (result != nullptr) {
            cout << "Nome: " << result->nome << endl; // Imprime o nome se encontrado
            cout << "Tipo: " << result->tipo << endl; // Imprime o tipo se encontrado
        } else {
            cout << "Rocha nao encontrada" << endl; // Mensagem se não encontrado
        }
    }

    // Função pública para remover um nó da árvore
    void remove(string nome, string tipo) {
        bool removed = false;
        root = remove(root, nome, tipo, removed); // Chama a função recursiva de remoção
        if (removed) {
            cout << "Rocha removida com sucesso" << endl; // Mensagem se removido com sucesso
        } else {
            cout << "Rocha nao encontrada para remocao" << endl; // Mensagem se não encontrado para remoção
        }
    }
};

// Função principal
int main() {
    BST tree; // Criação da árvore binária de busca
    int option; // Variável para a opção do usuário
    string nome, tipo; // Variáveis para nome e tipo da rocha

    while (true) {
        cin >> option; // Leitura da opção do usuário
        if (option == 0) break; // Se a opção for 0, termina o loop
        switch (option) {
            case 1:
                cin.ignore(); // Ignora o newline residual
                getline(cin, nome); // Lê o nome da rocha
                getline(cin, tipo); // Lê o tipo da rocha
                tree.insert(nome, tipo); // Insere a rocha na árvore
                break;
            case 2:
                cin.ignore(); // Ignora o newline residual
                getline(cin, nome); // Lê o nome da rocha para busca
                tree.search(nome); // Busca a rocha na árvore
                break;
            case 3:
                cin.ignore(); // Ignora o newline residual
                getline(cin, nome); // Lê o nome da rocha para remoção
                getline(cin, tipo); // Lê o tipo da rocha para remoção
                tree.remove(nome, tipo); // Remove a rocha da árvore
                break;
            default:
                cout << "Operacao invalida" << endl; // Mensagem para operação inválida
                break;
        }
    }
    return 0; // Retorna 0 para indicar término bem-sucedido do programa
}
