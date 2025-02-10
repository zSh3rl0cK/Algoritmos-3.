#include <iostream>
#include <list>
#include <string>
using namespace std;

struct no{
    int inicio; // vertice
    int peso; // peso da sua aresta
};

// Função para criar uma aresta entre dois vértices
// u = origem v = destino
void cria_aresta(list<no> adj[], int u, int v, int peso, int orientado){
    no aux; // auxiliar para incluir na lista

    aux.inicio = v;
    aux.peso = peso;
    adj[u].push_back(aux); // vertice de origem (u) tem caminho para destino (v)
    
    // se nao for orientado, caminho bidirecional
    if(orientado == 0){
        aux.inicio = u;  
        adj[v].push_back(aux);
    }
}

// Função auxiliar para realizar a busca em profundidade (a partir de um vértice)
void dfs_visit(int u, list<no> adj[], int nVertices, char color[], int pai[], int d[], int f[], int& tempo){
    list<no>::iterator v;

    color[u] = 'G'; // G = visitado
    tempo++;
    d[u] = tempo; // tempo do vertice

    // percorrendo os vértices adjascente ao atual
    for(v = adj[u].begin(); v != adj[u].end(); v++){
        if(color[v->inicio] == 'W'){ // w = nao visitado
            pai[v->inicio] = u; // definindo o pai do vertice adjscnt
            dfs_visit(v->inicio, adj, nVertices, color, pai, d, f, tempo);
        }
    }

    color[u] = 'B'; // b = black (vertice ja foi todo visitado)
    tempo++;
    f[u] = tempo; // tempo final do vertice
}

void ordenacao_topologica(int f[], int nVertices) {
    int aux[nVertices];

    // inicializando o vetor auxiliar com o indice do vertice na posicao
    for(int i = 0; i < nVertices; i++){
        aux[i] = i;
    }

    // ordenando conforme o tempo de cada vértice (decrescente)
    for(int a = 0; a < nVertices; a++){
        for(int i = a + 1; i < nVertices; i++){
            if(f[aux[a]] < f[aux[i]]){ // para ordenar crescente (f[aux[a]] > f[aux[i]])
                int b = aux[a];
                aux[a] = aux[i];
                aux[i] = b;
            }
        }
    }

    // imprimindo a ordenação
    for(int i = 0; i < nVertices; i++){
        cout << aux[i] << " ";
    }
}

// Função de busca em profundidade
void dfs(list<no> adj[], int nVertices){
    int tempo;
    char color[nVertices];
    int pai[nVertices], d[nVertices], f[nVertices];

    for(int u = 0; u < nVertices; u++){
        color[u] = 'W'; // w = branco (significa não visitado)
        pai[u] = -1; // pai do vertice = -1
    }

    tempo = 0;

    // percorrendo os vertices e chamando dfs_visit para caso o vertice nao tenha sido visitado
    for(int u = 0; u < nVertices; u++){
        if (color[u] == 'W'){
            dfs_visit(u, adj, nVertices, color, pai, d, f, tempo);
        }
    }
    
    ordenacao_topologica(f, nVertices);
}

int main(){
    int nVertices, orientado; // Número de vértices e se é orientado (1) ou não (0)
    cout << "Insira se o numero de vertices e a orientacao" << endl;
    cin >> nVertices >> orientado;
    
    // Lista de adjacência
    list<no> adj[nVertices];
    
    // Entrada das arestas
    int origem, destino;
    
    cout << "Insira as arestas" << endl;
    cin >> origem >> destino;
    
    while(origem != -1 && destino != -1){
        // peso igual a 1 por nao ser espeficicado (todas as arestas terao o mesmo tempo)
        cria_aresta(adj, origem, destino, 1, orientado);
        
        cin >> origem >> destino;
    }
    
    // Chamando a função DFS para fazer a ordenação topológica
    dfs(adj, nVertices);
    
    return 0;
}