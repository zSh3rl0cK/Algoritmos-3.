// Tema: pokedex 
// Integrantes: Pedro Henrique Ribeiro Dias, Felipe Silva Loschi
// Felipe Tagawa Reis, Jo�o Gabriel

#include <iostream>
#include <list>
#include <climits>
#include <locale.h>

using namespace std;

struct cidades {
    int origem, destino, peso;
    int codigo;     // codigo da cidade
    bool centro; // possui um centro poke ou nao
    string nome; // nome da cidade
};

// Fun��o para mostrar as cidades:
void print_cidades(cidades cidade[], int numVertices) {
    cout << "Lista das cidades cadastradas: " << endl;
    cout << endl;

    for (int i = 0; i < numVertices; i++) {                                                                 
        cout << cidade[i].nome << " " << cidade[i].codigo << " "; 

        if (!cidade[i].centro)
            cout << "e n�o possui centro" << endl;
        else
            cout << "e possui centro" << endl;
        
        cout << endl;
    }
}

int main() {
    // permitindo acentua��o no c�digo
    setlocale(LC_ALL, "");

    // Declarando variaveis
    int num_vertices, arestas;          
    int origem, destino, peso, menu = 1; 
    bool orientado;                      
    cidades cidade[50];

    // Introducao
    cout << "Ol�, treinador. Bem vindo ao sistema de localiza��o de pok�mons!" << endl;
    cout << endl;

    // entrada dos dados do grafo a ser contruido:
    cout << "Escreva o n�mero de cidades e o n�mero de caminhos:" << endl;
    cin >> num_vertices >> arestas;

    // Definindo se o grafo sera orientado ou nao
    cout << "Digite '0' para dizer se o caminho ser� n�o � orientado ou '1' para orientado." << endl;
    
    do {
        cin >> orientado;
        if (orientado == 0 || orientado == 1) {
            break;
        }

        cout << "Digite '0' para dizer se o caminho ser� n�o � orientado ou '1' para orientado." << endl;
    } while (orientado != 0 || orientado != 1);

    // lista de adjacencia das cidades
    list<cidades> adj[num_vertices];

    // Codigo de menu simples, usando a variavel menu no loop
    while (menu != 0) { 
        // Introducao do menu e entrada da variavel
        cout << endl;
        cout << "MENU" << endl
             << "1-Entrada de dados das cidades"
             << endl
             << "2-Impimir as cidades cadastradas"
             << endl
             << "Pressione qualquer outro n�mero pra sair" << endl
             << endl;
        cin >> menu;
		cout << endl;
				
        // Usando switch case para o menu
        switch (menu) {
            // Caso 1: Entrada do grafo
            case 1:
                // fazendo a inicializa��o dos dados das cidades (codigo, centro poke e nome)
                for (int i = 0; i < num_vertices; i++) {
                    cout << "Agora preciso que informe o nome da cidade: " << endl;
                    getline(cin >> ws, cidade[i].nome);
                    cout << "Agora preciso que informe o c�digo da cidade: " << endl;
                    cin >> cidade[i].codigo;
                    cout << "Para verifica��oo de centros pok�mon na cidade, digite '0' para 'n�o' e '1' para 'sim' : " << endl;
                    cin >> cidade[i].centro;
                    cout << endl;
                }

                cout << endl;

                // inserindo os dados do grafo

                for (int i = 0; i < arestas; i++) {
                    cin >> origem >> destino >> peso;

                    adj[origem].push_back({origem, destino, peso});

                    if (orientado == 0) {
                        adj[destino].push_back({destino, origem, peso});
                    }
                }
                break;
            // Caso 2: Imprime as cidades salvas
            case 2:
                print_cidades(cidade, num_vertices); 
                break;
            /*
                Pra finalizar precisa fazer com que o treinador tenha a opcao de entrar
                com um numero que solta a lista dos codigos das cidades
                (assumindo que ele nao conheca todos ent ele pode nao conhecer o da sua cdd)
        
                int cod_atual;
        
                loop inicia aqui:
        
                cout << "Escreva o código da cidade em que você está!" << endl;
                cin >> cod_atual;
        
                cidade_mais_proxima(cidade, );
        
                fim do loop.
            */
            // Caso receba outro valor: sai do loop
            default:
                menu = 0;
        }
    }
    return 0;
}
