/*
            1000      400     R$
pedra       volume    peso    preco

diamante     455       263       500
esmeralda    521       127       410
topázio      857       254       320
rubi         65        134       315
jade         12        111       280

1- 1 dima + 1 esmaralda: 910 {guloso)
2- 1 esmaralda + 1 rubi + jade: 1005 (forca bruta)
*/




/* Solucao atraves de uma funcao recursiva (jonas) - so econtra o melhor valor

int matriz_solucao [n][capp][capv]; // deve-ser inicializada com -1 

int solucao(int i, int n, int capp, int capv){ // contador, quantidade de pedras, capacidade peso e capacidade volume
	if(capp <= 0 || i >= n || capv <= 0)
		return 0;
	if(matriz_solucao [i][capp][capv] != -1)
		return matriz_solucao [i][capp][capv];
		
	// segue a logica de uma árvore de decisoes, a sol1 soma 0 pois vc nao escolhe pegar a pedra	
	int sol1 = solucao(i+1, n, capp, capv) + 0;
	
	if(capp >= pedras[i].peso && capv >= pedras[i].volume)
		int sol2 = solucao(i+1, n, capp - pedras[i].peso, capv - pedras[i].volume) + pedra[i].valor;
	
	int a = max(sol1, sol2)
	matriz_solucao[i][capp][capv] = a;
	
	return a;
}
*/

#include <iostream>
#include <locale.h>
using namespace std;

struct dados{
    int peso, volume, preco;
};

int calcula_lucro(dados pedras[], int qntdDiamante, int qntdEsmeralda, int qntdTopazio, int qntdRubi, int qntdJade){
    return qntdDiamante * pedras[0].preco + qntdEsmeralda * pedras[1].preco + qntdTopazio * pedras[2].preco +
           qntdRubi * pedras[3].preco + qntdJade * pedras[4].preco;
}

int main(){
    setlocale(LC_ALL, ""); // Permitindo acentuação nas saídas do código

    dados pedras[5];

    // Definindo as informações de cada tipo de pedra
    pedras[0].peso = 263;
    pedras[0].volume = 455;
    pedras[0].preco = 500;

    pedras[1].peso = 127;
    pedras[1].volume = 521;
    pedras[1].preco = 410;

    pedras[2].peso = 254;
    pedras[2].volume = 857;
    pedras[2].preco = 320;

    pedras[3].peso = 134;
    pedras[3].volume = 65;
    pedras[3].preco = 315;

    pedras[4].peso = 111;
    pedras[4].volume = 12;
    pedras[4].preco = 280;

    int peso_maximo = 400;
    int volume_maximo = 1000;

    int melhor_lucro = -1;
    int melhor_qntdDiamante, melhor_qntdEsmeralda, melhor_qntdTopazio, melhor_qntdRubi, melhor_qntdJade;

    // Fazendo os casos para encontrar a melhor combinação para maximizar os lucros
    for(int qtdDiamante = 0; qtdDiamante <= 1; ++qtdDiamante){
        for(int qtdEsmeralda = 0; qtdEsmeralda <= 1; ++qtdEsmeralda){
            for(int qtdTopazio = 0; qtdTopazio <= 1; ++qtdTopazio){
                for(int qtdRubi = 0; qtdRubi <= 1; ++qtdRubi){
                    for(int qtdJade = 0; qtdJade <= 1; ++qtdJade){
                        int peso_atual = qtdDiamante * pedras[0].peso + qtdEsmeralda * pedras[1].peso +
                                         qtdTopazio * pedras[2].peso + qtdRubi * pedras[3].peso + qtdJade * pedras[4].peso;

                        int volume_atual = qtdDiamante * pedras[0].volume + qtdEsmeralda * pedras[1].volume +
                                           qtdTopazio * pedras[2].volume + qtdRubi * pedras[3].volume + qtdJade * pedras[4].volume;

                        if(peso_atual <= peso_maximo && volume_atual <= volume_maximo){
                            int lucro_atual = calcula_lucro(pedras, qtdDiamante, qtdEsmeralda, qtdTopazio, qtdRubi, qtdJade);

                            if (lucro_atual > melhor_lucro){
                                melhor_lucro = lucro_atual;
                                melhor_qntdDiamante = qtdDiamante;
                                melhor_qntdEsmeralda = qtdEsmeralda;
                                melhor_qntdTopazio = qtdTopazio;
                                melhor_qntdRubi = qtdRubi;
                                melhor_qntdJade = qtdJade;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "Melhor lucro: " << melhor_lucro << endl;
    cout << "Quantidade de diamantes: " << melhor_qntdDiamante << endl;
    cout << "Quantidade de esmeraldas: " << melhor_qntdEsmeralda << endl;
    cout << "Quantidade de topázios: " << melhor_qntdTopazio << endl;
    cout << "Quantidade de rubis: " << melhor_qntdRubi << endl;
    cout << "Quantidade de jades: " << melhor_qntdJade << endl;

    return 0;
}
