#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct edge{
    int v;
    int v2;
    int peso;
};

void shortest_path_dijkastra(list<edge>adj[], int vertices,int start){
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
            int dest = p->v;
            int weight = p->peso;
            
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
                cout << dist << " ";
            }
        }
    }
}

int main(){
    int vertices, directed, inicio, destino;
	
	cout << "Insira o numero de vertices, a orientacao, o vertice de inicio e destino" << endl;
	cin >> vertices >> directed >> inicio >> destino;
	
	list<edge> adj[vertices];
	
	int v1, v2, w;
	
	cout << "Insira o vertice 1, 2 e o peso entre eles" << endl;
	while(cin >> v1 >> v2 >> w && v1 != -1 && v2 != -1 && w != -1){
		adj[v1].push_back({v2, v1, w});
		
		if(directed == 0){
			adj[v2].push_back({v2, v1, w});
			adj[v1].push_back({v2, v1, w});
		}
		else{
		    adj[v2].push_back({v2, v1, w});
		}
			
	}
	
	shortest_path_dijkastra(adj, vertices, inicio);
    
    return 0;
}