#include <iostream>
#include <string>

using namespace std;

struct botas
{
	int num;
	char lado;
};

int main()
{
	int ind; // botas individuais
	
	while(cin >> ind)
	{
		
	   	botas bota[1000];
		int pares = 0; 
		
		
		for(int i = 0; i < ind; i++)
		{
			cin >> bota[i].num;
			cin.ignore();
			
			cin >> bota[i].lado;
		}
		
		for(int j = 0; j < ind; j++)
		{
			for(int k = 0; k < ind; k++)
			{
				if((bota[j].num > 0 && bota[k].num > 0) && bota[j].num == bota[k].num && bota[j].lado != bota[k].lado)
				{
					pares += 1;
					
					bota[j].num = -1;
					bota[k].num = -1;
				}
			}
		}
		
		cout << pares << endl;
	}
		
	return 0;
}