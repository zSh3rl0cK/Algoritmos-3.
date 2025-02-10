#include <iostream>
#include <climits>
using namespace std;

const int MAX_PAISES = 8;

void calculo_guloso(int origem, bool visitados[MAX_PAISES], int distancias[MAX_PAISES][MAX_PAISES], int n, int &dist_total, bool origem_saida = true){
    visitados[origem] = true;
    
    if (origem_saida){
        cout << origem << endl;
    }

    int proximo = -1;
    int dist_min = INT_MAX;

    // encontrando o prox pais
    for(int i = 0; i < n; ++i){
        if (!visitados[i] && distancias[origem][i] < dist_min) {
            proximo = i;
            dist_min = distancias[origem][i];
        }
    }
    if(proximo != -1){
        dist_total += dist_min;
        calculo_guloso(proximo, visitados, distancias, n, dist_total, true);
    }
}

int main(){
    int n;
    cin >> n;

    int distancias[MAX_PAISES][MAX_PAISES];
    bool visitados[MAX_PAISES] = {false};
    int dist_total = 0;

    // lendo as distancias
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            cin >> distancias[i][j];
            distancias[j][i] = distancias[i][j];
        }
    }

    calculo_guloso(0, visitados, distancias, n, dist_total, false);

    // menor custo das distancias ate o egito
    cout << "Menor curso: " << dist_total << endl;

    return 0;
}
