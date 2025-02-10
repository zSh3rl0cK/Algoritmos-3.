// Alocação Dinâmica
#include <iostream>
using namespace std;

int main(){
	/* 
	node *p = new node;
	*(p) dado = 13;
	(p).proximo = new node;
	delete(p);
	*/
	
	int *p = new int[5]; // Retorno do new sempre um endereço de memória(ponteiro).
	*(p + 2) = 13; // p[2] = 13;
	delete (p); // Desalocar o que foi alocado anteriormente.
	
	return 0;
}