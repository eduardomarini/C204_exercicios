#include <iostream>

using namespace std;

struct No { // Define uma estrutura chamada No
    int dado; // Declara um membro inteiro chamado dado
    No *esquerda, *direita; // Declara dois ponteiros para No, chamados esquerda e direita
};

void initNo(No* no, int valor) { // Define uma função para inicializar um nó
    no->dado = valor; // Atribui o valor ao membro dado do nó
    no->esquerda = nullptr; // Define o ponteiro esquerda do nó como nullptr
    no->direita = nullptr; // Define o ponteiro direita do nó como nullptr
}

No* inserirRec(No* no, int dado) { // Define uma função para inserir um nó de forma recursiva
    if (!no) { // Se o nó for nullptr
        no = new No; // Cria um novo nó
        initNo(no, dado); // Inicializa o novo nó com o dado
    } else if (dado < no->dado) { // Se o dado for menor que o dado do nó
        no->esquerda = inserirRec(no->esquerda, dado); // Insere o dado na subárvore esquerda
    } else { // Se o dado for maior ou igual ao dado do nó
        no->direita = inserirRec(no->direita, dado); // Insere o dado na subárvore direita
    }
    return no; 
}

void preOrdem(No* no, int* resultado, int &indice) { // Define uma função para percorrer a árvore em pré-ordem
    if (!no) return; // Se o nó for nullptr, retorna
    resultado[indice++] = no->dado; // Adiciona o dado do nó ao array resultado e incrementa o índice
    preOrdem(no->esquerda, resultado, indice); // Percorre a subárvore esquerda em pré-ordem
    preOrdem(no->direita, resultado, indice); // Percorre a subárvore direita em pré-ordem
}

void emOrdem(No* no, int* resultado, int &indice) { // Define uma função para percorrer a árvore em ordem
    if (!no) return; // Se o nó for nullptr, retorna
    emOrdem(no->esquerda, resultado, indice); // Percorre a subárvore esquerda em ordem
    resultado[indice++] = no->dado; // Adiciona o dado do nó ao array resultado e incrementa o índice
    emOrdem(no->direita, resultado, indice); // Percorre a subárvore direita em ordem
}

void posOrdem(No* no, int* resultado, int &indice) { // Define uma função para percorrer a árvore em pós-ordem
    if (!no) return; // Se o nó for nullptr, retorna
    posOrdem(no->esquerda, resultado, indice); // Percorre a subárvore esquerda em pós-ordem
    posOrdem(no->direita, resultado, indice); // Percorre a subárvore direita em pós-ordem
    resultado[indice++] = no->dado; // Adiciona o dado do nó ao array resultado e incrementa o índice
}

int main() { // Define a função principal
    No* raiz = nullptr; // Declara um ponteiro para No chamado raiz e o define como nullptr
    int cidade; 
    int tamanhoMaximo = 100; // Declara uma variável inteira chamada tamanhoMaximo e a define como 100
    
    while (cin >> cidade && cidade != -1) { 
        raiz = inserirRec(raiz, cidade); 
    }

    int cidadeChocolate; 
    cin >> cidadeChocolate; 

    int *resultadoPreOrdem = new int[tamanhoMaximo]; 
    int *resultadoEmOrdem = new int[tamanhoMaximo]; 
    int *resultadoPosOrdem = new int[tamanhoMaximo]; 

    int indicePreOrdem = 0, indiceEmOrdem = 0, indicePosOrdem = 0; // Declara e inicializa três índices

    preOrdem(raiz, resultadoPreOrdem, indicePreOrdem); // Preenche o array resultadoPreOrdem com a árvore em pré-ordem
    emOrdem(raiz, resultadoEmOrdem, indiceEmOrdem); // Preenche o array resultadoEmOrdem com a árvore em ordem
    posOrdem(raiz, resultadoPosOrdem, indicePosOrdem); // Preenche o array resultadoPosOrdem com a árvore em pós-ordem

    int posPreOrdem = -1, posEmOrdem = -1, posPosOrdem = -1; // Declara e inicializa três variáveis para guardar as posições

    for (int i = 0; i < indicePreOrdem; ++i) { // Para cada elemento em resultadoPreOrdem
        if (resultadoPreOrdem[i] == cidadeChocolate) { // Se o elemento for igual a cidadeChocolate
            posPreOrdem = i; // Guarda a posição
            break; // Sai do loop
        }
    }

    for (int i = 0; i < indiceEmOrdem; ++i) { // Para cada elemento em resultadoEmOrdem
        if (resultadoEmOrdem[i] == cidadeChocolate) { // Se o elemento for igual a cidadeChocolate
            posEmOrdem = i; // Guarda a posição
            break; // Sai do loop
        }
    }

    for (int i = 0; i < indicePosOrdem; ++i) { // Para cada elemento em resultadoPosOrdem
        if (resultadoPosOrdem[i] == cidadeChocolate) { // Se o elemento for igual a cidadeChocolate
            posPosOrdem = i; // Guarda a posição
            break; 
        }
    }

    if (posPreOrdem < posEmOrdem && posPreOrdem < posPosOrdem) { // Se a posição em pré-ordem for a menor
        cout << "Pre" << endl;
    } else if (posEmOrdem < posPreOrdem && posEmOrdem < posPosOrdem) { // Se a posição em ordem for a menor
        cout << "Em" << endl; 
    } else { // Se a posição em pós-ordem for a menor
        cout << "Pos" << endl; 
    }

    delete[] resultadoPreOrdem;
    delete[] resultadoEmOrdem;
    delete[] resultadoPosOrdem;

    return 0; 
}
