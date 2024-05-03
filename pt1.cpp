#include<iostream>
#include<list>
#include<string>
using namespace std;

#define INT_MAX 99999

struct Upgrade{
    int orig;
    int dest;
    int custo;
};

struct Habilidade {
    string nome;
    int codigo;
    float poder; 
    list<Upgrade> upgrades;
};

void prim(Habilidade adj[], int vertices, int start){
    bool intree[vertices];
    int distance[vertices], parent[vertices];
    for(int i=0; i<vertices; i++){
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
        list<Upgrade>::iterator p;
        for(p = adj[v].upgrades.begin();p != adj[v].upgrades.end(); p++){
            int dest = p->dest;
            int weigth =p->custo;
            if(distance[dest] > weigth && intree[dest]==false){
                distance[dest] = weigth;
                parent[dest] = v;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for(int i=0; i<vertices; i++){
            if(intree[i]==false && dist>distance[i]){
                dist = distance[i];
                v = i;
            }
        }
    }

    // somatório do custo_minimo
    int custo_minimo = 0;
    for(int i=1; i<vertices; i++){
        custo_minimo += distance[i];
    }
    // mostra custo_minimo
    cout << custo_minimo << endl;
}

int main(){
    
    int num_habilidades;
    cin >> num_habilidades;
    
    Habilidade habilidades[num_habilidades];
    
    for(int i=0; i< num_habilidades; i++){
        habilidades[i].codigo = i;
        cin >> habilidades[i].nome;
        cin >> habilidades[i].poder;
    }
    
    int num_upgrades, origem, destino, custo;
    cin >> num_upgrades;
    
    for(int j=0; j < num_upgrades; j++){
        cin >> origem;
        cin >> destino;
        cin >> custo;
        habilidades[origem].upgrades.push_back({origem, destino, custo});
    }
    
    prim(habilidades, num_habilidades, 0);

    return 0;
}





