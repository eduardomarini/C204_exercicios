/* Considerando o exercício anterior, faça um programa em que, após inserir todos as tortas,  o usuário possa informar uma faixa de valores de preço e todos as tortas 
com preço nessa faixa sejam exibidas em ordem crescente (incluindo os valores limites). 

Não se esqueça de liberar a memória alocada.  

Entrada
A primeira linha da entrada é a quantidade de tortas T.
Em seguida serão informadas T linhas com 4 números reais indicando:

- espessura da massa (EM) da torta T[i];

- peso (P) da torta T[i];

- altura (A) da torta T[i];

- e diâmetro (D) da torta T[i];

onde 0 <= i < T.

Por fim, serão informados dois valores inteiros PFmin e PFmax indicando respectivamente o valor mínimo e máximo da faixa de preço.

Saída
Na saída, o programa deve mostrar o número i e o preço PF de cada torta (no formato i:PF) que têm preço dentro da faixa [PFmin, PFmax] em ordem crescente de preço.

Exemplo de entrada:
4
5.1 2.8 8.1 29.8
4.85 3.1 7.9 31.1
4.98 2.89 8 30.9
3.8 2.1 7.95 26.5
150 300

Exemplo de saída:
0:153
2:154
1:157

Exemplo de entrada:
3
5 3.2 4 28
9 3.4 3 25
6 3.3 5 21
0 120

Exemplo de saída:
0:96
1:119   */

#include <iostream>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType; // Define o tipo de chave como int
typedef int ValueType; // Define o tipo de valor como int

struct DataType { // Estrutura para armazenar os dados
    KeyType key; // Chave
    ValueType value; // Valor
};

struct Node { // Estrutura para um nó da árvore
    DataType data; // Dados do nó
    Node * right; // Ponteiro para o nó direito
    Node * left; // Ponteiro para o nó esquerdo
} ;

// Função para inserir um nó na árvore
void insert(Node *& curr, DataType data){	
    if(curr == NULL){
        curr = new Node;
        curr->data = data;
        curr->right = NULL;
        curr->left = NULL;
    } else {
        if(data.value >= curr->data.value){
            insert(curr->right, data);
        } else if(data.value < curr->data.value) {
            insert(curr->left, data);
        }		
    }	
}

// Função para buscar um nó na árvore
Node * search(Node * curr, KeyType key){
    if(curr == NULL)
        return NULL;
    if(key == curr->data.key){
        return curr;
    } else {
        if(key > curr->data.key){
            return search(curr->right, key);
        } else if(key < curr->data.key){
            return search(curr->left, key);
        }
    }
    return NULL;
}

// Função para exibir os nós da árvore em ordem
void show_ordered(Node * curr){
    if(curr->left != NULL)
        show_ordered(curr->left);
    cout << curr->data.key << ":" << curr->data.value << endl;
    if(curr->right != NULL)
        show_ordered(curr->right);
}

// Função para desconectar o nó menor da árvore
Node * disconnect_lesser(Node *& curr){
    Node * aux = curr;
    if(aux->left == NULL){ 	
        curr = curr->right; 
        return aux;			
    } else {				
        return disconnect_lesser(curr->left);
    }
}

// Função para remover um nó da árvore
int remove(Node *& curr, KeyType old_key){
    if(curr == NULL){
        return 0;
    }
    Node * aux;
    if(curr->data.key == old_key){
        aux = curr;		
        if(curr->left == NULL){
            curr = aux->right;
        } else if(curr->right == NULL){
            curr = aux->left;
        } else {
            aux = disconnect_lesser(curr->right);
            curr->data = aux->data;
        }		
        delete aux;
        return 1;		
    } else {
        if(old_key > curr->data.key){
            return remove(curr->right, old_key);
        } else if(old_key < curr->data.key) {
            return remove(curr->left, old_key);
        }
    }
    return 0;
}

// Função para destruir a árvore
void destruct(Node *& curr){
    if(curr->left != NULL)
        destruct(curr->left);
    if(curr->right != NULL)
       	destruct(curr->right);
    delete curr;
    curr = NULL;
    return;
}

// Função para exibir os nós da árvore que estão dentro de um intervalo
void show_in_range(Node * curr, ValueType min, ValueType max) {
    if(curr == NULL) return;
    if(curr->left != NULL && curr->data.value >= min)
        show_in_range(curr->left, min, max);
    if(curr->data.value >= min && curr->data.value <= max)
        cout << curr->data.key << ":" << curr->data.value << endl;
    if(curr->right != NULL && curr->data.value <= max)
        show_in_range(curr->right, min, max);
}

// Função principal
int main() { 
    int T; 
    cin >> T; 

    Node * root = NULL; 

    for(int i = 0; i < T; i++) { 
        double EM, P, D, A; 
        cin >> EM >> P >> A >> D; 

        double PF = (EM * P * A) + (D + A); 

        DataType data; 
        data.key = i; 
        data.value = PF; 

        insert(root, data); 
    }

    ValueType PFmin, PFmax;
    cin >> PFmin >> PFmax;

    show_in_range(root, PFmin, PFmax); 

    destruct(root); 

    return 0; 
}

