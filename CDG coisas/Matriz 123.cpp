#include <iostream>

using namespace std;

int main() 
{
    int N;

    while (cin >> N) 
	{
        int matriz[N][N];

		// inserindo os valores da matriz
        for (int i = 0; i < N; i++) 
		{
            for (int j = 0; j < N; j++) 
			{
				// fazendo a linha ser 1, 2 ou 3 para cada caso
                if (i == j) 
				{
                    matriz[i][j] = 1;
                }
				
				else if (i + j == N - 1) 
				{
                    matriz[i][j] = 2;
                } 
				
				else 
				{
                    matriz[i][j] = 3;
                }
            }
        }

		// imprimindo a matriz
        for (int i = 0; i < N; i++) 
		{
            for (int j = 0; j < N; j++) 
			{
                cout << matriz[i][j];
            }
            
            cout << endl;
        }
    }

    return 0;
}
