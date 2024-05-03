#include<iostream>
#include<string>
#include<list>
using namespace std;

#define INT_MAX 99999

struct Estrada{
    int orig;
    int dest;
    int distancia;
};

struct Cidade {
    string nome;
    int codigo;
    float idh;
    list<Estrada> vizinhos;
};

int shortest_path_dijkstra(list<Estrada>adj[], int vertices, int start, int end, float idh, Cidade cidades[]){
    bool intree[vertices];
    int distance[vertices], parent[vertices];
    
    for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }
    distance[start] = 0;
    while(true){
        int v = -1;
        for(int u = 0; u < vertices; u++){
            if(!intree[u] && (v == -1 || distance[u] < distance[v])){
                v = u;
            }
        }
        if(v == -1) break;
        intree[v] = true;
        list<Estrada>::iterator p;
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            int dest = p->dest;
            int weight = p->distancia;
            if(distance[dest] > distance[v]+weight && cidades[dest].idh >= idh){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
            }
        }
    }
    return distance[end];
}

int main(){
    
    int num_cidades;
    cin >> num_cidades;
    
    Cidade cidades[num_cidades];
    list<Estrada> adj[num_cidades]; // Create adjacency list
    
    for(int i=0; i< num_cidades; i++){
        cidades[i].codigo = i;
        cin >> cidades[i].nome;
        cin >> cidades[i].idh;
    }
    
    int num_estradas, origem, destino, distancia;
    cin >> num_estradas;
    
    for(int j=0; j < num_estradas; j++){
        cin >> origem;
        cin >> destino;
        cin >> distancia;
        cidades[origem].vizinhos.push_back({origem, destino, distancia});
        adj[origem].push_back({origem, destino, distancia}); // Add to adjacency list
    }
    
    float idh;
    
    cin>>origem>>destino>>idh;
    
    cout << shortest_path_dijkstra(adj, num_cidades,origem, destino, idh, cidades) << endl; // Pass adjacency list
}