#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int N;
    string cifra;
    int posicoes;
    string decod;
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
	{
   	    getline(cin, cifra);
   	    cin.ignore();
   	    cin >> posicoes;
   	    cin.ignore();

   	    decod = cifra;
   	    
	    for (int j = 0; j < cifra.length(); j++) 
		{
            if (cifra[j] >= 'A' && cifra[j] <= 'Z') 
			{
                decod[j] = 'A' + ((cifra[j] - 'A' - posicoes + 26) % 26);
            }
        }
        
		cout << decod << endl;
	}

    return 0;
}


#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignorar a quebra de linha após o valor de N

    for (int i = 0; i < N; i++) {
        string mensagem;
        getline(cin, mensagem); // Lê a mensagem codificada
        int deslocamento;
        cin >> deslocamento;
        cin.ignore(); // Ignorar a quebra de linha após o valor de deslocamento

        string mensagemDecodificada = mensagem;

        for (int j = 0; j < mensagem.length(); j++) {
            if (mensagem[j] >= 'A' && mensagem[j] <= 'Z') {
                // Decodifica a letra usando o mapeamento direto
                mensagemDecodificada[j] = 'A' + ((mensagem[j] - 'A' - deslocamento + 26) % 26);
            }
        }

        cout << mensagemDecodificada << endl;
    }

    return 0;
}
