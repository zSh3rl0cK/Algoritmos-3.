#include <iostream>

using namespace std;

int main()
{
	int N; // numero de alunos na chamada
	
	cin >> N; 
	
	int lista[N]; // chamada com os numeros dos alunos
	
	// inserindo lista de chamada
	for(int i = 0; i < N; i++)
		cin >> lista[i];
	
	// numero de alunos presentes ao todo (incluindo os repetidos)
	int num_presentes = N;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// subtraindo o numero de alunos repetidos
			if(lista[i] == lista[j] && i != j && lista[i] >=0)
			{
				lista[j] = -1;
				num_presentes -= 1;
			}
		}
	}

	cout << num_presentes << endl;

	return 0;
}

