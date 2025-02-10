#include <iostream>
#include <string>

using namespace std;

struct dados {
    string nome;
    int quantidade;
};

int buscaBinaria(dados produtos[], int n, string search) {
    int inicio = 0, final = n - 1;

    while (inicio <= final) {
        int meio = inicio + (final - inicio) / 2;

        if (produtos[meio].nome == search) {
            return meio; // Retorna o índice se o produto for encontrado
        } else if (produtos[meio].nome < search) {
            inicio = meio + 1;
        } else {
            final = meio - 1;
        }
    }

    return -1; // Retorna -1 se o produto não for encontrado
}

int main() {
    dados produtos[100];

    int n;

    cin >> n;
	cin.ignore();
	
    for (int i = 0; i < n; i++) {
        cin >> produtos[i].nome;
        cin >> produtos[i].quantidade;
        cin.ignore();
    }

    string search;

    getline(cin, search);

	int ind = buscaBinaria(produtos, n, search);
	
	if(ind != -1){
	   	cout << search << " em estoque!" << endl;
	}
    else if(ind == -1)
        cout << "Nao existe " << search << " em estoque" << endl;

    return 0;
}
