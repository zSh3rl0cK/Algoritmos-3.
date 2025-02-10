#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

struct dados{
    string nome;
    string fabricante;
    int tier;
    float taxa_psicose;
};

int main(){
	setlocale(LC_ALL, "");	

    int n; // numero de implantes
    
    cin >> n;
    
    dados *p = new dados[n];
    
    float *taxaF_psicose; // ponteiro taxa final de psicose condicao
    *(taxaF_psicose) = 0;
    
    for(int i = 0; i < n; i++){
        getline(cin >> ws, p[i].nome);
        getline(cin >> ws, p[i].fabricante);
        cin >> p[i].tier;
        cin >> p[i].taxa_psicose;
        
        *(taxaF_psicose) += p[i].taxa_psicose;
    }
    
    delete []p; // deletando o ponteiro
    
    if(*(taxaF_psicose) > 60){
        cout << "Alerta! Uma recompensa de 50.000 edinhos foi colocada pela sua cabeça. Você se tornou um Ciberpsicopata." << endl;
    }
    
    else if(*(taxaF_psicose) <= 60){
        cout << "Vamos tchum! Temos uma cidade pra conquistar!" << endl;
    }
    
    return 0;
}