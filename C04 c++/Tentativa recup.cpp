#include<iostream>
#include<list>

#define INT_MAX 9999

using namespace std;

struct edge {
	int orig, dest, custo;
};

struct personagem {
	int velocidade, resistencia;
	int fadiga; // adicionando a caracterista fadiga dos personagens
};

struct resposta {
	int dist, saltos, fadiga;
};


/* preciso alterar a funcao para ela levar em consideração os turnos que o personagem completa o percurso
pois se a fadiga dele nao permitir ele avançar mais casas ele precisa descansar o turno e recuperar o ponto, a fadiga dele
é o peso da aresta que ele percorre

pode se usar a resistencia como fadiga - a cada turno o peso das arestas do grafo são subtraidos da resistencia do personagem
o que vai indicar quantas casas ele pode andar no proximo turno - assim no final, precisa comparar os turnos do p1 e p2A

lembrar de fazer toda a comparacao da fadiga dentro do loop e remover o return fadiga, e troca-lo por uma variavel turnos
que vai contar os turnos que cada personagem leva pra chegar ao destino
*/
resposta shortest_path_dijkstra(list<edge> adj[], int vertices, int start, int end, int velocidade, int resistencia) {
    bool intree[vertices];
    int distance[vertices], parent[vertices], saltos[vertices], fadiga[vertices];
    
    for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
        saltos[u] = INT_MAX;
        fadiga[u] = 0; // Inicializando a fadiga dos personagens como 0
    }
    distance[start] = 0;
    saltos[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
        list<edge>::iterator p;
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            int dest = p->dest;
            int weight = p->custo;
            int fadiga_atual = fadiga[v] + weight;
            int saltos_atual = saltos[v] + 1;
            int dist_atual = distance[v] + weight;
            if(dist_atual < distance[dest] && fadiga_atual <= resistencia){ // Verifica se o personagem pode percorrer esta aresta sem exceder a fadiga
                distance[dest] = dist_atual;
                parent[dest] = v;
                saltos[dest] = saltos_atual;
                fadiga[dest] = fadiga_atual;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for(int u = 0; u < vertices; u++){
            if(intree[u]==false && distance[u]<dist){
                dist = distance[u];
                v = u;
            }
        }
    }
    return {distance[end], saltos[end], fadiga[end]};
}


int main(){
	personagem p1, p2;
	
	int c, x, origem, destino, fadiga, objetivo;
	
	cin >> p1.velocidade >> p1.resistencia;
	cin >> p2.velocidade >> p2.resistencia;
	
	cin >> c >> x;
	
	list<edge> adj[c];

	for(int i = 0; i < x; i++){
		cin >> origem >> destino >> fadiga;
		adj[origem].push_back({origem, destino, fadiga});
		adj[destino].push_back({destino, origem, fadiga});
	}
	
	cin >> objetivo;
	
	resposta r1 = shortest_path_dijkstra(adj, c, 0, objetivo, p1.velocidade, p1.resistencia);

	resposta r2 = shortest_path_dijkstra(adj, c, 0, objetivo, p2.velocidade, p2.resistencia);
	
	// lembrar de mudar o if para ficar de acordo com as observacoes comentadas la em cima
	if(r1.saltos <= r2.saltos && r1.dist <= r2.dist && p1.resistencia >= r1.fadiga) {
		cout << "Personagem 1" << endl;
	} 
	else {
		cout << "Personagem 2" << endl;
	}
		
	return 0;
}