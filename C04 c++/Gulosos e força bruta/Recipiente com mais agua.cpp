#include <iostream>
using namespace std;

int main()
{
    int matriz[9][8]; 
    int h[9]; // altura de cada coluna
	
	// incializando a matriz inteira como 0
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = 0;
        }
    }

	// obs: caso seja necessario uma representação visual 
    for (int i = 0; i < 9; i++) {
        cin >> h[i];
        for (int j = 0; j < h[i]; j++) {
            matriz[i][j] = 1;
        }
    }
    
    int maior_volume = 0;
    int volume_atual;
    for(int i = 0; i < 9; i++){
    	for(int j = i+1; j < 9; j++){
			if(h[i] >= h[j])
				volume_atual = (j - i) * h[j];
			
			else if(h[j] > h[i])
				volume_atual = (j - i) * h[i];
			
			if(volume_atual > maior_volume)
				maior_volume = volume_atual;
		}
		
	}
    
    cout << maior_volume << endl;
    
    return 0;
}
