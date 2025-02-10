#include <iostream>
#include <list>
using namespace std;

struct dado {
    int k;      // chave
    int status; // 0:vazio, 1:ocupado, 2:removido
};

int h1(int k, int m) {
    int result = k % m;

    if (result < 0)
        result = result + m;

    return result;
}

int h2(int k, int m) {
    int result = 1 + (k % (m - 1));

    if (result < 0)
        result = result + m;

    return result;
}

int dhash_insert(dado T[], int m, int k) {
    int i = 0;
    int j; // posição

    while (i < m) {
        j = (h1(k, m) + i * h2(k, m)) % m;

        if (T[j].status != 1) {
            T[j].k = k;
            T[j].status = 1;
            break;
        }

        i++;
    }

    return j;
}

int main() {
    int m, n;
	list<int> pilha;
	
    cin >> m >> n;

    dado T[m];

    for (int i = 0; i < m; i++){
        T[i].k = -1;
        T[i].status = 0;
    }

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pilha.push_front(x);
    }
    
    
    for(int i = 0; i < n; i++){
		x = pilha.front();
		pilha.pop_front();
		
		dhash_insert(T, m, x);
	}

    for (int i = 0; i < m; i++){
		cout << T[i].k << " ";
    }

    return 0;
}