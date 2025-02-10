#include <iostream>
 
using namespace std;
 
int main() {
    
    int inicio, fim;
    int duracao = 0;
    
    cin >> inicio >> fim;
    
    int i = inicio;
    
    if(inicio > fim)
	{
		while(i != fim)
		{
			duracao += 1;
			i += 1;
			
			if(i == 24)
			{
				i = 0;
			}
		}
		
		cout << "O JOGO DUROU " << duracao << " HORA(S)" << endl;
	}
    
    else if(inicio < fim)
	{
		while(i != fim)
		{
			duracao += 1;
			i = i+1;
		}
		cout << "O JOGO DUROU " << duracao << " HORA(S)" << endl;
	}
	
	else
		cout << "O JOGO DUROU 24 HORA(S)" << endl;
	
    
    return 0;
}