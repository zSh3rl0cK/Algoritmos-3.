#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct aresta{
	int u;
	int v;
	int p;	
};

void shortest_path_dijkastra(list<aresta>adj[], int vertices, int start, int end){
    bool intree[vertices];
    int distance[vertices], parent[vertices];
    
    for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }
    
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
        list<aresta>::iterator p;
        
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            int dest = p->v;
            int weight = p->p;
            
            if(distance[dest] > distance[v]+weight){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
            }
        }
            
        v = 0;
        int dist = INT_MAX;
        for(int u = 0; u < vertices; u++){
            if(intree[u] == false && dist > distance[u]){
                dist = distance[u];
                v = u;
            }
        }
    }
    
    if (distance[end] == INT_MAX)
        cout << "Impossivel chegar ao dragao" << endl;
    else
        cout << distance[end] << endl;
}

int main(){
	int n, m; // numero de salas e corredores
	
	cout << "Insira o numero de salas e corredores" << endl;
	cin >> n >> m;
	
	list<aresta> adj[n];
	int u, v; // sala U origem e V destino
	
	cout << "Insira as salas com corredores entre elas" << endl;
	while(cin >> u >> v && u != -1 && v != -1){
		adj[u].push_back({u, v, 1});
		adj[v].push_back({u, v, 1});
	}
	
	cout << "Insira a sala de entrada e saída" << endl;
	int s, d; // sala de entrada e sala do dragao
	cin >> s >> d;
	
	// usando dijkstra para encontrar o menor caminho
	shortest_path_dijkastra(adj, n, s, d);
	
	return 0;
}