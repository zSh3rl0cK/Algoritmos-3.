#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

// Função para encontrar de forma binária a ilha da variável buscado
int busca_bin(string ilhas[], string buscado, int inicio, int fim){
    int metade; // Metade do vetor
    
    while(inicio <= fim) {
        metade = (inicio + fim) / 2; // Calculando a metade do vetor
        
        if (ilhas[metade] == buscado)
            return metade; // Retorna a posição do vetor onde o número foi encontrado
        
        else if (ilhas[metade] < buscado)
            inicio = metade + 1; // Buscado na segunda metade do vetor
        
        else
            fim = metade - 1; // Buscado na primeira metade do vetor
    }
    return -1; // Retorna -1 se o número não for encontrado
}

int main(){
    setlocale(LC_ALL, "");
    
    string ilhas[7]; // Vetor para as ilhas
    int tamanho = 7; // Tamanho fixo do vetor de ilhas
    int posicao; // Posição em que a ilha inserida na aux foi encontrada

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
    
    // Imprimindo a posição em que a ilha foi encontrada
    if(posicao != -1)
        cout << "Índice da ilha encontrada: " << posicao << endl;
    else
        cout << "Ilha não encontrada." << endl;
    
    return 0;
}
