#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct Aresta{
    int origem;
    int destino;
    int peso;
};

// funcao de busca em largura
void prim(list<Aresta>adj[], int n, int start){
    bool intree[n];
    int distance[n];
    int parent[n];
    
    for(int u = 0; u < n; ++u){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }
    
    distance[start] = 0;
    int v = start;
    
    while(!intree[v]){
        intree[v] = true;
        list<Aresta>::iterator p;
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            int destino = p->destino;
            int peso = p->peso;
            if (distance[destino] > peso && !intree[destino]) {
                distance[destino] = peso;
                parent[destino] = v;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < n; ++u) {
            if (!intree[u] && dist > distance[u]) {
                dist = distance[u];
                v = u;
            }
        }
    }
    
    int custo_total = 0;
    cout << "Arvore Geradora Minima:" << endl;
    for(int i = 0; i < n; ++i) {
        if(parent[i] != -1) {
            cout << parent[i] << " " << i << endl;
            custo_total += distance[i];
        }
    }
    cout << "Custo: " << custo_total << endl;
}

int main(){
    // numero de vertices 
	int n, orientado, start, origem, destino;
	cin >> n >> orientado >> start;
	
	// lista de adjacencia p/ grafo
	list<Aresta> adj[n];
	
	// leitura dos dados das arestas
	int peso;
	do{
		cin >> origem >> destino >> peso;
		
		if(origem == -1 && destino == -1 && peso == -1)
		    break;
		
		if(peso != 0 && orientado == 0){
			adj[origem].push_back({origem, destino, peso});
			adj[destino].push_back({origem, destino, peso});
		}
		else if((peso != 0 && orientado == 1)){
		    adj[origem].push_back({origem, destino, peso});
		}
	}while(origem != -1 && destino != -1 && peso != -1);
	
	prim(adj, n, start);
	
    return 0;
}