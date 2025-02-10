#include <iostream>
#include <locale.h>
using namespace std;

struct caixas{
    int alt, larg, comp;
    int volume;
    int quantidade;
};

int main(){
	
	setlocale(LC_ALL, ""); // Permitindo acentuacao na saida do codigo
	
    caixas caixas[3];
    
	/* OBS: a altura, largura e comprimento foram inseridas separadamente para
 	caso seja necessário dar cin neles, caso os valores possam ser variados*/
    
    /*obs 2: a caixa[0,1,2] sao as caixas A, B e C em sequencia (imprimidas como
	caixas to tipo 1, 2 e 3*/
	
	// lembrete "otimizar" essa atribuicao dos valores, muito extenso p/ ser vdd
    caixas[0].alt = 5;
    caixas[0].larg = 2;
    caixas[0].comp = 2;
    caixas[0].volume = caixas[0].alt * caixas[0].larg * caixas[0].comp;
    caixas[0].quantidade = 10; // Número de caixas do tipo A (1)

    caixas[1].alt = 1;
    caixas[1].larg = 1;
    caixas[1].comp = 3;
    caixas[1].volume = caixas[1].alt * caixas[1].larg * caixas[1].comp;
    caixas[1].quantidade = 20; // Número de caixas do tipo B (2)

    caixas[2].alt = 2;
    caixas[2].larg = 2;
    caixas[2].comp = 1;
    caixas[2].volume = caixas[2].alt * caixas[2].larg * caixas[2].comp;
    caixas[2].quantidade = 25; // Número de caixas do tipo C (3)

    int alt, larg, comp;
    cout << "Insira as medidas do caminhao (alt, larg e comp): " << endl;
    cin >> alt >> larg >> comp;

    int volume = alt * larg * comp; // volume do caminhao

    int vol_min; // volume minimo encontrado (estrategia gulosa)
    int pos; // posicao
    int vol_total = 0; // volume total

    do{
        vol_min = 1000; // Reiniciando o valor para o loop

        for (int i = 0; i < 3; i++){
            if (caixas[i].volume < vol_min && caixas[i].quantidade > 0) {
                vol_min = caixas[i].volume;
                pos = i;
            }
        }

        if (vol_min == 1000){
            break; // Não há mais caixas disponíveis para serem adicionadas no caminhao
        }

  	    int max_caixas = (volume - vol_total) / caixas[pos].volume; // limita o maximo de caixas que cabem no caminhao
        max_caixas = min(max_caixas, caixas[pos].quantidade); // limita ao número disponível de caixas do tipo pos

        // Inclui o máximo possível de caixas do tipo pos no caminhao
        vol_total += max_caixas * caixas[pos].volume;
        cout << "Incluídas " << max_caixas << " caixas do tipo " << pos + 1 << endl;

        caixas[pos].quantidade -= max_caixas; // atualizando a quantidade de caixas do tipo inseridas no caminhao

    }while(vol_total < volume);

    return 0;
}
