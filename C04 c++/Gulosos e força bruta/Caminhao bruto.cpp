#include <iostream>
#include <locale.h>
using namespace std;

struct caixas{
    int alt, larg, comp;
    int volume;
    int quantidade;
    int preco;
};

int calcula_valor(caixas caixas[], int qntda, int qntdb, int qntdc){
    return qntda * caixas[0].preco + qntdb * caixas[1].preco + qntdc * caixas[2].preco;
}

int main(){
    setlocale(LC_ALL, ""); // Permitindo acentuação nas saidas do código
    
    caixas caixas[3];
    
    // Definindo as informações de cada tipo de caixa 
    // lembrete "otimizar" essa atribuicao dos valores, muito extenso p/ ser vdd
    caixas[0].alt = 5;
    caixas[0].larg = 2;
    caixas[0].comp = 2;
    caixas[0].volume = caixas[0].alt * caixas[0].larg * caixas[0].comp;
    caixas[0].preco = 200;
    caixas[0].quantidade = 10; // Número de caixas do tipo A

    caixas[1].alt = 1;
    caixas[1].larg = 1;
    caixas[1].comp = 3;
    caixas[1].volume = caixas[1].alt * caixas[1].larg * caixas[1].comp;
    caixas[1].preco = 150;
    caixas[1].quantidade = 20; // Número de caixas do tipo B

    caixas[2].alt = 2;
    caixas[2].larg = 2;
    caixas[2].comp = 1;
    caixas[2].volume = caixas[2].alt * caixas[2].larg * caixas[2].comp;
    caixas[2].preco = 100;
    caixas[2].quantidade = 25; // Número de caixas do tipo C

    int alt, larg, comp;
    cout << "Insira as medidas do caminhão (alt, larg e comp): " << endl;
    cin >> alt >> larg >> comp;

    int volume_caminhao = alt * larg * comp; // Volume do caminhão

    int melhor_valor = -1;
    int melhor_qntda, melhor_qntdb, melhor_qntdc;
	
    // Fazendo os casos para encontrar o melhor valor/combinação p/ maximizar os lucros
    for (int qtdA = 0; qtdA <= caixas[0].quantidade; ++qtdA){
        for (int qtdB = 0; qtdB <= caixas[1].quantidade; ++qtdB){
            for (int qtdC = 0; qtdC <= caixas[2].quantidade; ++qtdC){
                int volume_atual = qtdA * caixas[0].volume + qtdB * caixas[1].volume + qtdC * caixas[2].volume;

                if (volume_atual <= volume_caminhao){
                    int valor_atual = calcula_valor(caixas, qtdA, qtdB, qtdC);
					
                    if (valor_atual > melhor_valor){
                        melhor_valor = valor_atual;
                        melhor_qntda = qtdA;
                        melhor_qntdb = qtdB;
                        melhor_qntdc = qtdC;
                    }
                }
            }
        }
    }

    cout << "Melhor valor: " << melhor_valor << endl;
    cout << "Quantidade de caixas do tipo A: " << melhor_qntda << endl;
    cout << "Quantidade de caixas do tipo B: " << melhor_qntdb << endl;
    cout << "Quantidade de caixas do tipo C: " << melhor_qntdc << endl;

    return 0;
}
