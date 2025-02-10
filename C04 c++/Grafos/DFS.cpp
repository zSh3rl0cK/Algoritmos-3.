#include <ostream>
using namespace std;

void(int adj[100][100], int vertices, int atual, bool visitados[]){
	visitados[atual] = true;
	
	for(int i = 0; i < vertices; i++){
		if(adj[atual][i] != -1 && visitados[i] == false){
			dfs(adj, vertices, i, visitados)
		}
	}
}

int main(){
	int vertices, direcionado; // num de vertices e direcionado ou nao
	cin >> vertices >> direcionado;
	
	bool visitados[vertices];
	int adj[vertices][vertices]; // grafo
	
	// inicializando a matriz com -1 nas posicoes
	for(int i = 0; i < vertices; i++){
		visitado[i] = false;
		for(int j = 0; j < vertices; j++){
			adj[i][j] = -1;
		}
	}
	
	int o, d, p; // origem destino e peso
	// inserindo os pesos entre cada origem destino
	while(cin >> o >> d >> p && o != -1 && d != -1 && p != -1){
		adj[o][d] = p;
		if(direcionado == 0){
			adj[d][o] = p;
		}
	}
	
	dfs(adj, vertices, 0, visitados);
	return 0;
}