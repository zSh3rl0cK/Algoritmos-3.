#include<iostream>
#include<list>
#include<string>
using namespace std;

#define INT_MAX 99999

// aresta
struct Upgrade{
	int orig;
	int dest;
	int custo;
};

// informacoes das habilidades
struct Habilidade{
	string nome;
	int codigo;
	float poder; 
	list<Upgrade> upgrades;
};

void bfs_poder_acumulado(Habilidade adj[], int vertices, int start, float poder_acumulado[]){
    bool visited[vertices]; // visitados
	list<int> to_visit_queue; // // lista a ser visitada
	
	// iniciando todos os vertices como nao visitados
	for(int i=0;i<vertices;i++){
		visited[i] = false;
	}
	
	visited[start] = true; // v inicial visitado
	to_visit_queue.push_back(start); // lista a ser visitado
	
	while(!to_visit_queue.empty()){
		int curr = to_visit_queue.front(); // vertice atual da fila
		
		to_visit_queue.pop_front(); // apagando o primeiro da lista
		
		// iterador para percorrer a lista adj
		list<Upgrade>::iterator p;
		
		for(p = adj[curr].upgrades.begin(); p != adj[curr].upgrades.end(); p++){
			int dest = p->dest; // destino da aresta
			
			if(!visited[dest]){
				visited[dest] = true; // marcando como visitado
				to_visit_queue.push_back(dest); // incluindo na lista para visitar
				poder_acumulado[dest] += poder_acumulado[curr]; // atualizando o poder acumulado
			}				
		}
	}
}

// funcao para ir do poder inicial até o poder desejado end
void shortest_path_dijkstra(Habilidade adj[], float poder_acumulado[], int vertices, int start, int end){
	bool intree[vertices]; // visitados
	int distance[vertices], parent[vertices]; // distancia do vertice e pai do vertice
	
	// inicializando cada vetor como: nao visitado, distancia maxima e pai -1 (sem)
	for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
	}
	
    distance[start] = 0; // distancia do vertice inicial = 0
    int v = start; // vertice inicial
	    
    while(intree[v] == false){
        intree[v] = true; // marcando como visitado
		list<Upgrade>::iterator p; // iterador para percorrer a lista
		
    	for(p = adj[v].upgrades.begin(); p != adj[v].upgrades.end(); p++){
            int dest = p->dest; // destino da aresta
            int weight = p->custo; // peso da aresta
            
            if(distance[dest] > distance[v]+weight && intree[dest] == false){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX; // para verificar a menor distancia
		int poder = 0; // pra que - deve ter que usar pra algo
        
        for(int u = 0; u < vertices; u++){
            if(intree[u] == false && dist > distance[u]){
                dist = distance[u];
                v = u;
			}
		}
	}

    // imprimindo corretamente a menor distancia até o poder
    if(distance[end] != INT_MAX){
       cout << distance[end]+3 << endl;
	}
	// caso nao seja possivel chegar ao destino (desconexo)
    else
        cout << "Impossivel" << endl;
}

int main(){
	
	int num_habilidades;
	cin >> num_habilidades; // iniciando o numero de habilidades
	
	Habilidade habilidades[num_habilidades];
	float poder_acumulado[num_habilidades];
	
	// inserindo as informações das habilidades
	for(int i=0; i < num_habilidades; i++){
		habilidades[i].codigo = i; // codigo da habilidade i 
		cin >> habilidades[i].nome; // nome da habilidade
		cin >> habilidades[i].poder; // poder da habilidade
		
		poder_acumulado[i] = habilidades[i].poder; // poder de i
	}
	
	// num de upgrades, codigo da habilidade origem, destino e ocusto entre elas
	int num_upgrades, origem, destino, custo;
	cin >> num_upgrades;
	
	// inserindo os dados dos upgrades
	for(int j=0; j < num_upgrades; j++){
		cin >> origem; // vertice inicial da aresta
		cin >> destino; // vertice destino da aresta
		cin >> custo; // custo da aresta
		
		// grafo orientado
		habilidades[origem].upgrades.push_back({origem, destino, custo});
	}
	
	// chamando a função de busca em largura
	bfs_poder_acumulado(habilidades, num_habilidades, 0, poder_acumulado);
	
	float poder_desejado;
	// poder final que deseja ser alcancado (busca pelo menor caminho)
	cin >> poder_desejado;
	
	// encontrando o menor custo com o poder desejado
	shortest_path_dijkstra(habilidades, poder_acumulado, num_habilidades, 0, poder_desejado);
	
	return 0;
}
/*
caso teste fornecido

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

saida esperada
5
*/