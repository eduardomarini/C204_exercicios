#include <iostream>  
#include <string>    

using namespace std; 

// Estrutura para armazenar informações do filme
struct Filme {
    string nome;       
    string genero;     
    int duracao;       
    int idadeMinima;   
    int ano;           

    Filme* left;       // Ponteiro para o filho à esquerda na árvore binária
    Filme* right;      // Ponteiro para o filho à direita na árvore binária
};

// Função para criar um novo nó da árvore
Filme* createNewNode(string nome, string genero, int duracao, int idadeMinima, int ano) {
    Filme* newNode = new Filme(); // Alocação de memória para um novo nó do tipo Filme
    if (!newNode) {  // Verificação de erro na alocação de memória
        cout << "Erro na alocação de memória.\n"; // Mensagem de erro
        exit(0); // Saída do programa em caso de erro
    }
    newNode->nome = nome;  // Inicialização do campo nome
    newNode->genero = genero;  // Inicialização do campo genero
    newNode->duracao = duracao;  // Inicialização do campo duracao
    newNode->idadeMinima = idadeMinima;  // Inicialização do campo idadeMinima
    newNode->ano = ano;  // Inicialização do campo ano
    newNode->left = newNode->right = nullptr;  // Inicialização dos ponteiros para filhos
    return newNode;  // Retorno do novo nó
}

// Função para inserir um novo filme na árvore
Filme* insertMovie(Filme* root, string nome, string genero, int duracao, int idadeMinima, int ano) {
    // Se a árvore estiver vazia, atribua um novo nó de endereço ao root
    if (root == nullptr) {
        root = createNewNode(nome, genero, duracao, idadeMinima, ano); // Cria e atribui novo nó à raiz
        return root;  // Retorna a nova raiz
    }

    // Se a árvore não estiver vazia, insira os dados recursivamente
    if (nome < root->nome) {  // Se o nome for menor que o nome do nó atual
        root->left = insertMovie(root->left, nome, genero, duracao, idadeMinima, ano); // Insere à esquerda
    }
    else {  // Se o nome for maior ou igual ao nome do nó atual
        root->right = insertMovie(root->right, nome, genero, duracao, idadeMinima, ano); // Insere à direita
    }

    return root;  
}

// Função para pesquisar um filme na árvore
Filme* searchMovie(Filme* root, string nome) {
    // Caso base: root é nulo ou a chave está presente na root
    if (root == nullptr || root->nome == nome)
       return root;  // Retorna o nó encontrado ou nullptr

    // A chave é maior que a chave da root
    if (root->nome < nome)
       return searchMovie(root->right, nome); // Pesquisa no subárvore à direita

    // A chave é menor que a chave da root
    return searchMovie(root->left, nome); // Pesquisa no subárvore à esquerda
}

// Função para imprimir as informações de um filme
void printMovie(Filme* filme) {
    if (filme == nullptr) {  // Verifica se o filme foi encontrado
        cout << "Filme nao encontrado\n";  // Mensagem de erro
        return;  // Retorna sem fazer nada
    }

    cout << "Nome: " << filme->nome << "\n";  
    cout << "Genero: " << filme->genero << "\n";  
    cout << "Duracao: " << filme->duracao << " mins\n";  
    cout << "Classificacao: " << filme->idadeMinima << "\n";  
    cout << "Ano: " << filme->ano << "\n";  
}


int main() {
    Filme* root = nullptr;  // Inicialização da raiz da árvore como nullptr
    int option;  
    string nome, genero;  
    int duracao, idadeMinima, ano;  

    while (true) {  
        cin >> option;  
        cin.ignore(); 
        switch (option) {  // Switch case para as opções do usuário
            case 1:
                getline(cin, nome);  
                getline(cin, genero);  
                cin >> duracao >> idadeMinima >> ano;  
                root = insertMovie(root, nome, genero, duracao, idadeMinima, ano);  
                break;  
            case 2:
                getline(cin, nome);  
                printMovie(searchMovie(root, nome));  
                break;  
            case 0:
                exit(0);  
            default:
                cout << "Operação inválida\n";  
        }
    }

    return 0;  
}
