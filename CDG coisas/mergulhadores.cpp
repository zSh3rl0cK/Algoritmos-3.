#include <iostream>

using namespace std;

int main() {
    int N; // numero de mergulhadores
    int R; // Mergulhadores que voltaram
    
    while (cin >> N >> R) {
        int volunt[N]; // vetor dos voluntarios
        int encontrado = 0; // encontrou o mergulhador
        int algum = 0; // algum mergulhador não voltar
        
        // inserindo os voluntarios
        for (int i = 0; i < R; i++) {
            cin >> volunt[i];
        }
        
        // buscando os mergulhadores (de 1 a N)
        for (int j = 1; j <= N; j++) {
            encontrado = 0;
            for (int k = 0; k < R; k++) {
                if (j == volunt[k]) {
                    encontrado = 1; // significa que ele voltou
                    break; // saia do loop interno assim que encontrar o mergulhador
                }
            }
            
            // se encontrado = 0, o mergulhador j não voltou
            if (encontrado == 0) {
                cout << j << " ";
                algum = 1; // significa que alguém não voltou
            }
        }
        
        // se ninguém não voltou
        if (algum == 0) {
            cout << "*";
        }
        
        cout << endl;
    }
    
    return 0;
}
