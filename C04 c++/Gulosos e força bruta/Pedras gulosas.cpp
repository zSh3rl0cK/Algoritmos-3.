/*
            1000      400     R$
pedra       volume    peso    preco

diamante     455       263       500
esmeralda    521       127       410
topázio      857       254       320
rubi         65        134       315
jade         12        111       280

1- 1 dima + 1 esmaralda: 910 (guloso)
2- 1 esmaralda + 1 rubi + jade: 1005 (forca bruta)
*/

#include <iostream>
#include <locale.h>
using namespace std;

struct PedraPreciosa{
    string nome;
    int peso, volume, preco, quantidade;
};

int main(){
    setlocale(LC_ALL, ""); // Permitindo acentuação na saída do código

    PedraPreciosa pedras[5];

    // Definindo as informações de cada tipo de pedra
    pedras[0] = {"Diamante", 263, 455, 500, 1};
    pedras[1] = {"Esmeralda", 127, 521, 410, 1};
    pedras[2] = {"Topázio", 254, 857, 320, 1};
    pedras[3] = {"Rubi", 134, 65, 315, 1};
    pedras[4] = {"Jade", 111, 12, 280, 1};

    int peso_maximo = 400;
    int volume_maximo = 1000;

    int lucro_total = 0;

    do{
        int melhor_lucro = -1;
        int melhor_pedra;

        for(int i = 0; i < 5; ++i){
            if(pedras[i].quantidade > 0){
                int lucro_atual = pedras[i].preco;

                if(pedras[i].peso <= peso_maximo && pedras[i].volume <= volume_maximo){
                    if(lucro_atual > melhor_lucro){
                        melhor_lucro = lucro_atual;
                        melhor_pedra = i;
                    }
                }
            }
        }

        if(melhor_lucro == -1){
            break; // Não há mais pedras disponíveis para serem adicionadas no carrinho
        }

        cout << "Incluída pedra: " << pedras[melhor_pedra].nome << " com lucro " << melhor_lucro << endl;

        peso_maximo -= pedras[melhor_pedra].peso;
        volume_maximo -= pedras[melhor_pedra].volume;
        lucro_total += melhor_lucro;

        pedras[melhor_pedra].quantidade--; // Atualizando a quantidade de pedras do tipo inseridas no carrinho

    }while(peso_maximo > 0 && volume_maximo > 0);

    cout << "Lucro total: " << lucro_total << endl;

    return 0;
}
