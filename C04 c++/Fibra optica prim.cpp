#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct aresta{
	int dest;
    int v;
    int peso;
};

void cria_aresta(list<aresta> adj[], int u, int v, int peso, int orientado){
    aresta aux; // auxiliar para incluir na lista

    aux.dest = v; // destino vertice V
    aux.v = u; // origem vertice U
    aux.peso = peso;
    adj[u].push_back(aux); // vertice de origem (u) tem caminho para destino (v)
    
    // se nao for orientado, caminho bidirecional
    if(orientado == 0){
        aux.dest = u; // destino vertice U
        aux.v = v; // origem vertice V
        adj[v].push_back(aux);
    }
}

// funcao de busca em largura
void prim(list<aresta>adj[], int n, int start){
    bool intree[n]; // visitados
    int distance[n]; // distancia
    int parent[n]; // pai do vertice n
    
    for(int u = 0; u < n; ++u){
        intree[u] = false; // marcando o vertice u como nao visitado
        distance[u] = INT_MAX; // inicializando distancia do vertice u
        parent[u] = -1; // inicializando pai do vertice u
    }
    
    distance[start] = 0;
    int v = start;
    
    while(!intree[v]){
        intree[v] = true;
        list<aresta>::iterator p;
        
        for(p = adj[v].begin(); p != adj[v].end(); p++){
        	int destino = p->dest;
            int peso = p->peso;
            if (distance[destino] > peso && !intree[destino]) {
                distance[destino] = peso;
                parent[destino] = v;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < n; ++u) {
            if (!intree[u] && dist > distance[u]){
                dist = distance[u];
                v = u;
            }
        }
    }
    
    int custo_total = 0;
    for(int i = 0; i < n; ++i){
        if(parent[i] != -1) {
            custo_total += distance[i];
        }
    }
    cout << "Custo mínimo para conectar as cidades: " << custo_total << endl;
}

int main(){
	int n, m; // numero de vertices (cidades) e arestas (conexões)
	cin >> n >> m;
	
	int u, v, c; // cidade origem, destino e custo da conexão entre elas
	list<aresta> adj[n]; // lista de adjasncencia
	
	// inserindo as cidades no grafo
	for(int i = 0; i < m; i++){
		cin >> u >> v >> c;
		
		cria_aresta(adj, u, v, c, 0);
	}
	
	prim(adj, n, 0);
	
    return 0;
}