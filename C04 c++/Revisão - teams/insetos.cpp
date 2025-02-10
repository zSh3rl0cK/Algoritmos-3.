#include <iostream>
#include <string>

using namespace std;

struct dados{
	float num;
	string especie;
};

void bubble_sort(dados vet[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (vet[j].num > vet[j + 1].num){
                // troca os insetos
                dados temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

int main()
{
	int n;
	
	cin >> n;
	
	dados insetos[100];
	for(int i = 0; i < n; i++){
		cin.ignore();
		getline(cin, insetos[i].especie);
		cin >> insetos[i].num;
	}
	
	bubble_sort(insetos, n);
	
	for (int i = 0; i < n; i++){
        cout << insetos[i].especie << endl;
    }
	
	return 0;
}