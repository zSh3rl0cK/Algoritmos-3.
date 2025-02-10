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

struct Habilidade{
	string nome;
	int codigo;
	float poder; 
	list<Upgrade> upgrades;
};

void bfs_poder_acumulado(Habilidade adj[], int vertices, int start, float poder_acumulado[]){
	
	bool visited[vertices];
	list<int> to_visit_queue;
	
	for(int i=0;i<vertices;i++){
		visited[i] = false;
	}
	
	visited[start] = true;
	to_visit_queue.push_back(start);
	
	while(!to_visit_queue.empty()){
		int curr = to_visit_queue.front(); // atual
		
		to_visit_queue.pop_front(); // apagando o primeiro da lista
		
		list<Upgrade>::iterator p;
		
		for(p = adj[curr].upgrades.begin(); p != adj[curr].upgrades.end(); p++){
			int dest = p->dest;
			
			if(!visited[dest]){
				visited[dest] = true;
				to_visit_queue.push_back(dest);
				poder_acumulado[dest] += poder_acumulado[curr];
			}				
		}
			
	}
}


int shortest_path_dijkstra(Habilidade adj[], float poder_acumulado[], int vertices, int start){
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
		list<Upgrade>::iterator p;
    	for(p = adj[v].upgrades.begin(); p != adj[v].upgrades.end(); p++){
            int dest = p->dest;
            int weight = p->custo;
            if(distance[dest] > distance[v]+weight){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX, poder = 0;
        for(int u = 0; u < vertices; u++){
            if(intree[u]==false && distance[u]<dist){
                dist = distance[u];
                v = u;
			}
		}
	}
	int dist = INT_MAX;
	for(int u = 0; u < vertices; u++){
        if(intree[u]==true && distance[u] < dist){
            dist = distance[u];
		}
	}
	return dist;
}

int main(){
	
	int num_habilidades;
	cin >> num_habilidades; // iniciando o numero de habilidades
	
	Habilidade habilidades[num_habilidades];
	float poder_acumulado[num_habilidades];
	
	// inserindo as informações das habilidades
	for(int i=0; i< num_habilidades; i++){
		habilidades[i].codigo = i; // codigo da habilidade i 
		cin >> habilidades[i].nome; // nome da habilidade
		cin >> habilidades[i].poder; // poder da habilidade
		poder_acumulado[i] = habilidades[i].poder; // poder de i
	}
	
	// num de upgrades, codigo da habilidade origem, destino e ocusto entre elas
	int num_upgrades, origem, destino, custo;
	cin >> num_upgrades;
	
	// inserindo os dados 
	for(int j=0; j < num_upgrades; j++){
		cin >> origem;
		cin >> destino;
		cin >> custo;
		habilidades[origem].upgrades.push_back({origem, destino, custo});
	}
	
	// chamando a função bfs para
	bfs_poder_acumulado(habilidades, num_habilidades, 0, poder_acumulado);
	
	float poder_desejado;
	cin >> poder_desejado;
	
	// encontrando o menor custo com o poder desejado
	cout << shortest_path_dijkstra(habilidades, poder_acumulado, num_habilidades, 0, poder_desejado) << endl;
	
	return 0;
}
/*
10
0 0
1 1
2 3
3 3
4 4
5 5
6 7
7 2
8 4
9 5
9
0 1 1
1 2 2
1 3 2
3 4 3
3 5 3
3 6 4
0 7 2
7 8 3
7 9 3
7
*/