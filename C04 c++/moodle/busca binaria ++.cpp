#include <iostream>
using namespace std;

int busca_bin(int vetor[], int valor, int inicio, int fim){
   int metade;
   
   while(inicio <= fim){
	   metade = (inicio + fim) / 2; // calculando a metade do vetor
	   
	   if (vetor[metade] == valor)
	   		return metade; // Retorna a posição do vetor onde o numero foi encontrado
	   
	   else if (vetor[metade] < valor)
	   		return busca_bin(vetor, valor, metade+1, fim);
	   
	   else if(vetor[metade] > valor)
	    	return busca_bin(vetor, valor, inicio, metade - 1);
   }
	return -1; // Retorna -1 se o numero não for encontrado
}

int main(){
	int n;
	cin >> n;
	int vetor[n];
	
	for(int i = 0; i < n; i++){
		cin >> vetor[i];
	}
	
	int buscado;
	cin >> buscado;
	
	int resultado = busca_bin(vetor, buscado, 0, n);
	cout << resultado << endl;
	
	return 0;
}