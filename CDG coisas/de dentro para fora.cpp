#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    cin.ignore(); 

    for (int i = 0; i < N; i++) {
        string frase;
        getline(cin, frase);

        int tamanho = frase.length(); // tamanho total da frase
        string decifrada(tamanho, ' '); // string a ser desinvertida

        for (int j = 0; j < tamanho / 2; j++) { // tamanho /2 = metade
            // invertendo
        
		    decifrada[j] = frase[tamanho / 2 + j];
            decifrada[tamanho / 2 + j] = frase[j];
        }
        
        // a frase está correta, porem invertida
        string invertida;
        
        // invertendo do fim para o comeco a frase
        for (int j = decifrada.length() - 1; j >= 0; --j) {
            invertida += decifrada[j];
        }
        
        // imprimindo a frase correta
        cout << invertida << endl;
    }
    
    return 0;
}