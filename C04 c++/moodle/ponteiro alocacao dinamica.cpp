// Aloca��o Din�mica
#include <iostream>
using namespace std;

int main(){
	/* 
	node *p = new node;
	*(p) dado = 13;
	(p).proximo = new node;
	delete(p);
	*/
	
	int *p = new int[5]; // Retorno do new sempre um endere�o de mem�ria(ponteiro).
	*(p + 2) = 13; // p[2] = 13;
	delete (p); // Desalocar o que foi alocado anteriormente.
	
	return 0;
}