#include <iostream> 
#include <string> 
using namespace std; 

struct Node { // Define uma estrutura para os nós da árvore de busca binária
    int data; // Os dados armazenados no nó
    Node* left; // Ponteiro para o nó filho à esquerda
    Node* right; // Ponteiro para o nó filho à direita
};

Node* newNode(int data) { // Função para criar um novo nó
    Node* node = new Node(); // Aloca memória para o novo nó
    node->data = data; // Define os dados do nó
    node->left = NULL; // Inicializa o filho à esquerda como NULL
    node->right = NULL; // Inicializa o filho à direita como NULL
    return node; // Retorna o novo nó
}

Node* insert(Node* node, int data) { // Função para inserir um nó na árvore de busca binária
    if (node == NULL) { // Se a árvore está vazia
        return newNode(data); // Cria um novo nó
    }
    if (data < node->data) { // Se os dados são menores que os dados do nó
        node->left = insert(node->left, data); // Insere na subárvore à esquerda
    } else if (data > node->data) { // Se os dados são maiores que os dados do nó
        node->right = insert(node->right, data); // Insere na subárvore à direita
    }
    return node; // Retorna o nó
}

bool search(Node* root, int x) { // Função para buscar um valor na árvore de busca binária
    if (root == NULL) { // Se a árvore está vazia
        return false; // O valor não foi encontrado
    } else if (root->data == x) { // Se os dados da raiz são iguais ao valor
        return true; // O valor foi encontrado
    } else if (root->data > x) { // Se os dados da raiz são maiores que o valor
        return search(root->left, x); // Busca na subárvore à esquerda
    } else { // Se os dados da raiz são menores que o valor
        return search(root->right, x); // Busca na subárvore à direita
    }
}

int main() { // A função principal
    Node* root = NULL; // Inicializa a raiz da árvore como NULL
    int N; // O número de operações
    cin >> N; // Lê o número de operações
    for (int i = 0; i < N; i++) { // Para cada operação
        char operation; // A operação ('i' para inserir, 'b' para buscar)
        int manuscript; // O valor para inserir ou buscar
        cin >> operation >> manuscript; // Lê a operação e o valor
        if (operation == 'i') { // Se a operação é inserir
            root = insert(root, manuscript); // Insere o valor na árvore
        } else if (operation == 'b') { // Se a operação é buscar
            if (search(root, manuscript)) { // Se o valor é encontrado na árvore
                cout << "Sim" << endl; // Imprime "Sim"
            } else { // Se o valor não é encontrado na árvore
                cout << "Nao" << endl; // Imprime "Nao"
            }
        }
    }
    return 0; // Retorna 0 para indicar execução bem-sucedida
}