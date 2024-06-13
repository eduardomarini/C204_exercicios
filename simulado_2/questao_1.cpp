/*Faça um programa que leia inicialmente a quantidade de tortas T a serem cadastradas no sistema.

Depois, o programa deve ler as características de cada torta T[i] (0 <= i < T), que são números reais representando a espessura da massa (EM), o peso (P), 
o diâmetro (D) e a altura (A) da torta. O preço final PF da torta é calculado de acordo com a formula: PF = (EM*P*A+D+A). Insira o código i e o preço final PF de 
cada torta T[i] em uma árvore binária de busca e faça uma listagem em ordem crescente do preço.

Não esqueça de liberar a memória no final do programa!

Entrada

A primeira linha da entrada é a quantidade de tortas T.
Em seguida serão informadas T linhas com 4 números reais indicando:
- espessura da massa (EM) da torta T[i];

- peso (P) da torta T[i];

- altura (A) da torta T[i];

- e diâmetro (D) da torta T[i];

onde 0 <= i < T.

Saída
Na saída, o programa deve mostrar número i e o preço PF de cada torta (no formato i:PF) em ordem crescente de preço.

Exemplo de entrada   

4
5.1 2.8 8.1 29.8
4.85 3.1 7.9 31.1
4.98 2.89 8 30.9
3.8 2.1 7.95 26.5	

Exemplo de saída

3:97
0:153
2:154
1:157

Exemplo de entrada  
3
5 3.2 4 28
9 3.4 3 25
6 3.3 5 21


Exemplo de saída
0:96
1:119
2:124 */

#include <iostream> 

using namespace std; 

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType; // Define KeyType como um alias para int
typedef int ValueType; // Define ValueType como um alias para double

struct DataType { // Define uma estrutura para armazenar os dados
    KeyType key; // Chave do nó
    ValueType value; // Valor do nó
};

struct Node { // Define uma estrutura para o nó da árvore
    DataType data; // Dados do nó
    Node * right; // Ponteiro para o nó direito
    Node * left; // Ponteiro para o nó esquerdo
};

void insert(Node *& curr, DataType data) { // Função para inserir um nó na árvore
    if(curr == NULL){ // Se o nó atual é NULL
        curr = new Node; // Cria um novo nó
        curr->data = data; // Atribui os dados ao nó
        curr->right = NULL; // Define o nó direito como NULL
        curr->left = NULL; // Define o nó esquerdo como NULL
    } else {
        if(data.value >= curr->data.value){ // Se o valor dos dados é maior ou igual ao valor dos dados do nó atual
            insert(curr->right, data); // Insere o nó à direita
        } else if(data.value < curr->data.value) { // Se o valor dos dados é menor que o valor dos dados do nó atual
            insert(curr->left, data); // Insere o nó à esquerda
        }       
    }   
}

void show_ordered(Node * curr){ // Função para exibir os nós em ordem
    if(curr->left != NULL) // Se o nó esquerdo não é NULL
        show_ordered(curr->left); // Exibe o nó esquerdo
    cout << curr->data.key << ":" << curr->data.value << endl; // Exibe a chave e o valor do nó atual
    if(curr->right != NULL) // Se o nó direito não é NULL
        show_ordered(curr->right); // Exibe o nó direito
}

void destruct(Node *& curr){ // Função para destruir a árvore
    if(curr->left != NULL) // Se o nó esquerdo não é NULL
        destruct(curr->left); // Destroi o nó esquerdo
    if(curr->right != NULL) // Se o nó direito não é NULL
        destruct(curr->right); // Destroi o nó direito
    delete curr; // Deleta o nó atual
    curr = NULL; // Define o nó atual como NULL
    return; 
}

// ----------------------------------------------------------------------------

int main() { 
    int T; // Número de tortas
    cin >> T; 

    Node * root = NULL; // Cria a raiz da árvore

    for(int i = 0; i < T; i++) { 
        double EM, P, D, A; 
        cin >> EM >> P >> A >> D; 

        double PF = (EM * P * A) + (D + A); // Calcula o preço final da torta

        DataType data; // Cria uma variável para armazenar os dados
        data.key = i; // Define a chave como o índice da torta
        data.value = PF; // Define o valor como o preço final da torta

        insert(root, data); // Insere os dados na árvore
    }

    show_ordered(root); // Exibe os nós em ordem

    destruct(root); // Destroi a árvore

    return 0; 
}