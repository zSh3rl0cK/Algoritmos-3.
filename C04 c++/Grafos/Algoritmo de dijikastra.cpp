#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct edge{
	int dest;
	int v1;
	int weight;
};

int shortest_path_dijkastra(list<edge>adj[], int vertices, int start, int end){
	// calculando a distancia do start para todos os vertices
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
		list<edge>::iterator p;
		
		for(p = adj[v].begin(); p != adj[v].end(); p++){
			int dest = p->dest;
			int weight = p->weight;
			
			if(distance[dest] > distance[v]+weight){
				distance[dest] = distance[v]+weight;
				parent[dest] = v;
			}
		}
		
		// procurando a prox menor distancia nao visitada para recomecar o loop
		v = 0;
		int dist = INT_MAX;
		for(int u = 0; u < vertices; u++){
			if(intree[u] == false && dist > distance[u]){
				dist = distance[u];
				v = u;
			}
		}
	} 
	
	return distance[end];
}

int main()
{
	int vertices, directed;
	
	cin >> vertices >> directed;
	
	list<edge> adj[vertices];
	
	int v1, v2, w;
	
	while(cin >> v1 >> v2 >> w && v1 != -1 && v2 != -1 && w != -1){
		adj[v1].push_back({v2, v1, w});
		
		if(directed == 0)
			adj[v2].push_back({v2, v1, w});
	}
	
	cout << shortest_path_dijkastra(adj, vertices, 0, 4) << endl;
	
	return 0;
}