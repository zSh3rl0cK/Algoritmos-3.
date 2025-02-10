#include <iostream>
#include <list>
using namespace std;

struct no{
    int v;
    int peso;
};

// funcao de busca em largura
void bfs(list<no> adj[], int vertices, int origem){
    list<int> fila_espera; // fila de espera
    fila_espera.push_back(origem);
    
    bool visitados[vertices]; // bool para verificar se o vertice ja foi visitado
    for(int i = 0; i < vertices; i++){
        visitados[i] = false;
    }
    
    int atual; // valor atual da lista de espera
    
    // fazendo a varredura de cada no e imprimindo a aresta visitada e os vertices
    while(!fila_espera.empty()){
        atual = *fila_espera.begin();
        
        fila_espera.pop_front();
        cout << atual << endl;
        
        list<no>::iterator p;
        for(p = adj[atual].begin(); p != adj[atual].end(); p++){
            int v = p->v;
            cout << atual << " " << v << endl;
            if(visitados[v] == false){
                visitados[v] = true;
                fila_espera.push_back(v);
            }
        }
        visitados[atual] = true;
     }
}

int main(){
    int vertices, inicial; // numero de vertices e lista orientada ou nao
    cin >> vertices >> inicial;
    
    list<no> adj[vertices]; // lista de adjascencia
    
    // vertice de origem, vertice de destino e seu peso
    int v, destino, peso;
    cin >> v >> destino >> peso;
    
    // loop para criar a aresta baseado no peso
    while(v != -1 && destino != -1 && peso != -1){
        no aresta_destino;
        aresta_destino.v = destino;
        aresta_destino.peso = peso;
        
        adj[v].push_back(aresta_destino);
        
        no aresta_origem;
        aresta_origem.v = v;
        aresta_origem.peso = peso;
        
        adj[destino].push_back(aresta_origem);
        cin >> v >> destino >> peso;
    }
    
    // fazendo a busca em largura
    bfs(adj, vertices, inicial);
    
    return 0;
}
