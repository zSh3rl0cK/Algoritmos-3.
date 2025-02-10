// Grupo: Pedro Henrique Ribeiro Dias - Felipe Tagawa Reis
// Felipe Silva Loschi, Jo�o Gabriel Rezende e Beatriz Vaz Pedroso
// Tema: Pokedex


#include <iostream>
#include <iomanip>
#include <list>
#include <climits>
#include <locale.h>

using namespace std;

struct Estrada{
	int origem, destino, peso;
};

struct cidades {
    list<Estrada>vizinhos;
    int codigo;     // codigo da cidade
    bool centro; // possui um centro poke ou nao
    string nome; // nome da cidade
};

// Fun��o para mostrar as cidades e seus vizinhos.
void print_cidades(cidades cidade[], int numVertices) {
    list<Estrada>::iterator p;
    cout << "Lista das cidades cadastradas: " << endl;
    cout << endl;
    cout << "| " << setw(2) << "Nome(s) " << setw(15) << " | " << setw(6) << right << setw(10) << "C�digo" << setw(7) << " | " << setw(15) << " Centro Pok�mon" << right << setw(43) <<  " | Vizinhos - Origem, destino e dist�ncia" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "| ";
        cout << setw(19) << left << setw(20) << left << cidade[i].nome << left << " | ";
        cout << left << setw(8) << right << cidade[i].codigo << right << setw(9) << " | ";
        if (!cidade[i].centro)
            cout << "N�o possui centro |";
        else
            cout << right << setw(15) << "Possui centro" << right << setw(4) << " |";
        
        // Verifica se h� vizinhos para esta cidade
        if (!cidade[i].vizinhos.empty()) {
            cout << " ";
            for (p = cidade[i].vizinhos.begin(); p != cidade[i].vizinhos.end(); p++) {
                cout << p->origem << " -> " << p->destino << "(" << p->peso << ")" << " ";
            }
        }
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

    // Introducao
    cout << "Ol�, treinador. Bem vindo ao sistema de localiza��o de pok�mons!" << endl;
    cout << endl;

    // entrada dos dados do grafo a ser contruido:
    cout << "Escreva o n�mero de cidades e o n�mero de caminhos:" << endl;
    cin >> num_vertices >> arestas;
    cidades cidade[num_vertices];

    // Definindo se o grafo sera orientado ou nao
    cout << "Digite '0' para dizer se o caminho ser� n�o � orientado ou '1' para orientado." << endl;
    
    do {
        cin >> orientado;
        if (orientado == 0 || orientado == 1) {
            break;
        }

        cout << "Digite '0' para dizer se o caminho ser� n�o � orientado ou '1' para orientado." << endl;
    } while (orientado != 0 || orientado != 1);


    // Codigo de menu simples, usando a variavel menu no loop
    while (menu != 0) { 
        // Introducao do menu e entrada da variavel
        cout << endl;
        cout << "MENU" << endl
             << "1-Entrada de dados das cidades"
             << endl
             << "2-Imprimir as cidades cadastradas"
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
                    cout << "Para verifica��o de centros pok�mon na cidade, digite '0' para 'n�o' e '1' para 'sim' : " << endl;
                    cin >> cidade[i].centro;
                    cout << endl;
                }

                cout << endl;

                // inserindo os dados do grafo
                
                // Instru��o para entrada dos caminhos do grafo
                cout << "Agora vamos inserir os caminhos entre as cidades." << endl;
                cout << "Para cada caminho, escreva o ponto de origem, o ponto de chegada e a dist�ncia entre as cidades." << endl;
                cout << "Exemplo de entrada: '0 1 10' indica um caminho da cidade 0 para a cidade 1 com dist�ncia 10." << endl;
                cout << endl;

                for (int i = 0; i < arestas; i++) {
                    cin >> origem >> destino >> peso;

                    cidade[origem].vizinhos.push_back({origem, destino, peso});

                    if (orientado == 0) {
                        cidade[destino].vizinhos.push_back({destino, origem, peso});
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