#include <iostream>
#include <list>
using namespace std;

#define VERTICES 4 // define o valor de VERTICES para 10 quando for usado

// funcao para a busca por largura
bool conexo_bfs(bool adj[VERTICES][VERTICES], int vertices, int origem){
	list<int> fila_espera; // fila de espera
	fila_espera.push_back(origem);
	
	bool visitados[vertices]; // bool para verificar se o vertice ja foi visitado
	for(int i = 0; i < vertices; i++){
		visitados[i] = false;
	}
	
	int atual; // valor atual da lista de espera
	
	// fazendo a varredura de cada no	
	while(!fila_espera.empty()){
		atual = fila_espera.front();
		visitados[atual] = true;
		
		for(int i = 0; i < vertices; i++){
			if(adj[atual][i] == true && visitados[i] == false){
				fila_espera.push_back(i);
			}
		}
		fila_espera.pop_front();
		
		cout << atual << endl;
	}
	
	for(int i = 0; i < vertices; i++){
		if(visitados[i] == false)
			return false;
	}
	
	return true;
}

int main(){
	bool matriz[VERTICES][VERTICES]; // matriz grafo
	
	// inicializando todas as posicoes como desconexas
	for(int i = 0; i < VERTICES; i++){
		for(int j = 0; j < VERTICES; j++){
			matriz[i][j] = false;
		}
	}
	
	/* inicializacao em caso de varios
	int i = 0, j = 0;
	whie(i != -1 && j != -1){
		cin >> i >> j;
		matriz[i][j] = true;
		matriz[j][i] = true;
	}
	*/
	
	// definindo os valores para o exemplo
	matriz[1][0] = true;
	matriz[0][1] = true;
	matriz[2][3] = true;
	matriz[3][2] = true;
	matriz[2][1] = true;
	matriz[1][2] = true;
	
	if(conexo_bfs(matriz, 4, 1))
		cout << "Conexo" << endl;
	else
		cout << "disconexo" << endl;
	
	return 0;
}