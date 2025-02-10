#include <iostream>
using namespace std;

int main()
{
    int c; // coluna escolhida da matriz
    char letra; // letra para média ou soma
    float soma = 0;
    float media;

    float mat[11][11]; // matriz 

    cin >> c;
    cin.ignore();

    cin >> letra;

	// Inserindo os valores da matriz
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cin >> mat[i][j];
        }
    }
	
    // Verifica se a coluna escolhida está dentro dos limites válidos.
    // Calculando a soma da coluna escolhida
    for (int i = 0; i < 11; i++)
    {
        soma += mat[i][c];
    }
    media = soma / 11;

    // Imprimindo a soma ou a média
    if (letra == 'm' || letra == 'M')
        cout << media << endl;
    else if (letra == 's' || letra == 'S')
        cout << soma << endl;
    
    return 0;
}
