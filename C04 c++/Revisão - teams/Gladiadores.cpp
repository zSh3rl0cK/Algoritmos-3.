#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct dados {
    string nome;
    int forca;
    int habilidade;
    int idade;
    int vida;
};

bool luta(dados g1, dados g2) {
    g1.vida = 100; // 1
    g2.vida = 100; // 1

    while (g1.vida > 0 && g2.vida > 0){ // 5
        g2.vida = g2.vida - (g1.forca + pow(2, g1.habilidade)); // 7?
        g1.vida = g1.vida - (g2.forca + pow(2, g2.habilidade)); // 7
    }

    if (g1.vida <= 0) // 2
        return false; // g2 wins
    else
        return true; // g1 wins
}

int main(){
    dados gladiadores[100];

    for (int i = 0; i < 5; i++){ // 13
        getline(cin, gladiadores[i].nome); // 2
        cin >> gladiadores[i].forca; // 2
        cin >> gladiadores[i].habilidade; // 2
        cin >> gladiadores[i].idade; // 2
        cin.ignore();
    }

    int g1, g2;

    do{
        cin >> g1 >> g2; // 2 n

        if (g1 == -1 ||  g2 == -1) // 4 n
            break;

        bool vencedor = luta(gladiadores[g1], gladiadores[g2]); // 5 n

        if (!vencedor) // n
            cout << gladiadores[g1].nome << " venceu a luta contra " << gladiadores[g2].nome << endl; // 5 n
        else
            cout << gladiadores[g2].nome << " venceu a luta contra " << gladiadores[g1].nome << endl; // 5 n

    }while (g1 != -1 && g2 != -1); // 5 n

	// complexidade: O(n)
    return 0;
}
