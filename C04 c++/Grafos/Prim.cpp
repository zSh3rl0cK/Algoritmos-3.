#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct Aresta{
	int origem;
	int destino;
	int peso;	
};

int menor_peso_nao_visitado(list<Aresta> *adj, bool *visitado, int n){
	int peso_min = INT_MIN; // lembrar de ver dps se o comando ta certo
	int indice_min = -1;
	
	for(int i = 0; i < n; i++){
		if(!visitado[i]){
			list<Aresta>::iterator it;
			
			for(it = adj[i].begin(); it != adj[i].end(); it++){
				Aresta aresta = *(it);
				
				if(visitado[aresta.destino] && aresta.peso < peso_min){
					peso_min = aresta.peso;
					indice_min = i;
				}
			}
		}
	}
	
	return indice_min;
}

void prim(list<Aresta> *adj, int n){
	// vertices visitados
	bool visitados[n];
	
	// inicilizando todos os vertices como nao visitados
	for(int i = 0; i < n; i++){
		visitados[i] = false;
	}
	// comecando por um vertice arbitrario (0) primeiro escolhido
	// loop para construir a AGM
	for(int i = 0; i < n; i++){
		// encontrando o vertice com menor peso nao visitado
		int u = menor_peso_nao_visitado(adj, visitados, n);
		
		// adicionar a aresta de menor peso à AGM
		list<Aresta>::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++){
			Aresta aresta = *(it);
			if(!visitados[aresta.destino]){
				cout << u << " - " << aresta.destino << " (" << aresta.peso << ")"<< endl;
				break;
			}
		}
		// vertice marcado como visitado
		visitados[u] = true;
	}
}

int main(){
	// numero de vertices 
	int n, a, origem, destino;
	cin >> n >> a;
	
	// lista de adjacencia p/ grafo
	list<Aresta> adj[n];
	
	// leitura dos dados das arestas
	for(int i = 0; i < a; i++){
		int peso;
		cin >> origem >> destino >> peso;
		
		if(peso != 0){
			adj[origem].push_back({origem, destino, peso});
			adj[destino].push_back({origem, destino, peso});
		}
	}
	
	// chamando o algoritmo de prim
	prim(adj, n);
	
	return 0;
}