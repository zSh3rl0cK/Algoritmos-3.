#include <iostream>
 
using namespace std;
 
int main() {
 
    int x;
    int y;
    int soma = 0;
    
    cin >> x;
    cin >> y;
    
    if(x < y)
	{
        for(int i = x+1; i < y; i++)
		{
			if(i%2 != 0)
			{
				soma = soma + i;
			}
		}
	}
	else if(x > y)
	{
        for(int i = y+1; i < x; i++)
		{
			if(i%2 != 0)
			{
				soma = soma + i;
			}
		}
	}
	
    cout << soma << endl;
    
    return 0;
}