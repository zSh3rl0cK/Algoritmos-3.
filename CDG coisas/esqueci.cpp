#include <iostream>
 
using namespace std;
 
int main() {
 
   int N;
   int P;
   int menor = 1000;
   
   cin >> N;
   
   int vetor[N];
   
   for(int i = 0; i < N; i++)
   {
       cin >> vetor[i];
       
       if(vetor[i] < menor)
       {
            menor = vetor[i];
            P = i;
       }
   }
 
    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << P << endl;
    
    return 0;
}