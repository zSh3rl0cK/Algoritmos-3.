#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

// Fun��o para encontrar de forma bin�ria a ilha da vari�vel buscado
int busca_bin(string ilhas[], string buscado, int inicio, int fim){
    int metade; // Metade do vetor
    
    while(inicio <= fim) {
        metade = (inicio + fim) / 2; // Calculando a metade do vetor
        
        if (ilhas[metade] == buscado)
            return metade; // Retorna a posi��o do vetor onde o n�mero foi encontrado
        
        else if (ilhas[metade] < buscado)
            inicio = metade + 1; // Buscado na segunda metade do vetor
        
        else
            fim = metade - 1; // Buscado na primeira metade do vetor
    }
    return -1; // Retorna -1 se o n�mero n�o for encontrado
}

int main(){
    setlocale(LC_ALL, "");
    
    string ilhas[7]; // Vetor para as ilhas
    int tamanho = 7; // Tamanho fixo do vetor de ilhas
    int posicao; // Posi��o em que a ilha inserida na aux foi encontrada

    // Inserindo as ilhas no vetor
    cout << "Insira os nomes das 7 ilhas:" << endl;
    for(int i = 0; i < tamanho; ++i){
        cout << "Ilha " << i + 1 << ": ";
        getline(cin >> ws, ilhas[i]);
    }
    
    // Procurando pela ilha
    string buscado;
    cout << "Digite o nome da ilha que deseja encontrar: ";
    cin >> buscado;
    posicao = busca_bin(ilhas, buscado, 0, tamanho - 1);
    
    // Imprimindo a posi��o em que a ilha foi encontrada
    if(posicao != -1)
        cout << "�ndice da ilha encontrada: " << posicao << endl;
    else
        cout << "Ilha n�o encontrada." << endl;
    
    return 0;
}
