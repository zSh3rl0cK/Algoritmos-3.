#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct edge{
    int u;
    int v;
    int t;
};

void shortest_path_dijkastra(list<edge> adj[], int nVertices, int start){
	bool intree[vertices];
    int distance[vertices], parent[vertices];
    
    for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }
        
    distance[start] = 0;
    v = start;
    
    while(intree[v] == false){
        intree[v] = true;
        
        list<edge>::iterator p;
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            int dest = p->v;
            int weight = p->t;
            
            // passivel de correcao if(distance[dest] > distance[v]+weight
             //   distance[dest] = distance[v]+weight;
              //  parent[dest] = v;
            if(distance[dest] > weight && intree[dest] == false){
                distance[dest] = weight
                parent[dest] = v;
            }
        }
        
        v = 0
        int dist = INT_MAX;
        
        int dist = INT_MAX;
        for(int u = 0; u < vertices; u++){
            if(intree[u] == false && dist > distance[u]){
                dist = distance[u];
                v = u;
            }
        }
	}
	
	cout << distance[end] << endl;
	
}

int main(){
    int n, m;
    cin >> n >> m;

    list<edge> adj[n];

    // cidade u e v, tempo entre elas
    int u, v, t;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        
        adj[u-1].push_back({u-1, v-1, t});
        adj[v-1].push_back({v-1, u-1, t});
    }
    
    int inicio, destino;
    cin >> inicio >> destino;

    // função para retornar o tempo mínimo gasto para viajar de inicio a destino
    shortest_path_dijkastra(adj, n, inicio-1, destino-1);

    return 0;
}
