#include<iostream>
#include<list>
using namespace std;

#define VERTICES 10 // Número máximo de vértices

bool eh_conexo(bool adj[VERTICES][VERTICES], int vertices){
	list<int> fila_espera;
	bool visitado[vertices];
	for(int i = 0; i<vertices; i++){
		visitado[i] = false;
	}
	fila_espera.push_back(0);
	int atual;
	while(!fila_espera.empty()){
		atual = fila_espera.front();
		visitado[atual] = true;
		for(int i = 0; i<vertices; i++){
			if(adj[atual][i] == true && visitado[i] == false){
				fila_espera.push_back(i);
			}
		}
		fila_espera.pop_front();
	}
	for(int i = 0; i<vertices; i++){
		if(visitado[i] == false){
			return false;
		}
	}
	return true;
	
	
}

void bfs(bool adj[VERTICES][VERTICES], int vertices, int origem){
	list<int> fila_espera;
	bool visitado[vertices];
	for(int i = 0; i<vertices; i++){
		visitado[i] = false;
	}
	fila_espera.push_back(origem);
	int atual;
	while(!fila_espera.empty()){
		atual = fila_espera.front();
		visitado[atual] = true;
		for(int i = 0; i<vertices; i++){
			if(adj[atual][i] == true && visitado[i] == false){
				fila_espera.push_back(i);
			}
		}
		fila_espera.pop_front();
		cout<<atual<<endl;
	}	
}

int main(){
	
	bool matriz_adj[VERTICES][VERTICES];
	for(int i=0; i<VERTICES; i++){
		for(int j=0; j<VERTICES; j++){
			matriz_adj[i][j] = false;
		}
	}
	// int i=0, j=0, vertices = 0;
	// cin >> vertices; 
	// while(i != -1 && j != -1){
	// 	cin >> i >> j;
	// 	matriz_adj[i][j] = true;
	// 	matriz_adj[j][i] = true;
	// }
	int vertices = 4;
	matriz_adj[0][1] = true;
	matriz_adj[1][0] = true;
	matriz_adj[2][3] = true;
	matriz_adj[3][2] = true;
	matriz_adj[1][2] = true;
	matriz_adj[2][1] = true;
	
	// bfs(matriz_adj,vertices,3);
	if(eh_conexo(matriz_adj, vertices)) {
		cout<<"Conexo"<<endl;
	} else {
		cout<<"Desconexo"<<endl;
	}
	
	return 0;
}