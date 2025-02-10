#include <iostream>
#include <string>
#include <list>

using namespace std;

struct dado {
    int code;
    string nome;
    int preco;
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

int hash_linear(int k, int m, int i){
    return ((h1(k, m) + i) % m);
}

int hash_insert(dado T[], int m, int k, string nome, int idade, float peso, float alt) {
    int i = 0;
    int j; // posicao

    while (i < m) {
        j = hash_linear(k, m, i);

        if (T[j].status == 0 || T[j].status == 2) {
            T[j].code = k;
            T[j].nome = nome;
            T[j].preco = idade;
            T[j].status = 1;
            break;
        }

        i++;
    }

    return j;
}

int hash_search(dado T[], int m, int k) {
    int i = 0;
    int j;

    do {
        j = hash_linear(k, m, i);

        if (T[j].code == k && T[j].status == 1) {
            return j;
        }

        i++;
    } while (T[j].status != 0 && i < m);

    return -1;
}

int hash_remove(dado T[], int m, int k) {
    int j = hash_search(T, m, k);

    if (j != -1) {
        T[j].status = 2;
        return 0; // consegui remover
    } else
        return -1; // k nao esta na tabela
}

void coloca_venda(int vi, list<string> fila, dado T[], int m) {
    int procura = hash_search(T, m, vi);

    if (procura != -1)
        fila.push_back(T[procura].nome);
}

void comprado(int vc, list<string> pilha, dado T[], int m) {
    int procura = hash_search(T, m, vc);

    if (procura != -1)
        pilha.push_back(T[procura].nome);
}

int main() {
    int m = 43;
    int n;
    list<string> fila;
    list<string> pilha;

    int v, c;

    cin >> n;

    dado itens[n];

    for (int i = 0; i < n; i++) {
        cin >> itens[i].code;
        getline(cin, itens[i].nome);
        cin >> itens[i].preco;
    }

    int vi = 0;

    while (vi != -1) {
        cin >> vi;
        if (vi != -1)
            coloca_venda(vi, fila);
    }

    int vc = 0;

    while (vc != -1) {
        cin >> vc;
        if (vc != -1)
            comprado(vc, pilha);
    }

    cin >> v >> c;

    int vt = 0, vc_total = 0;

    while (v > 0 && !fila.empty()) {
        int item_code = fila.front();
        fila.pop_front();
        int index = hash_search(itens, n, item_code);

        if (index != -1) {
            vt += itens[index].preco;
            v--;
        }
    }

    while (c > 0 && !pilha.empty()) {
        int item_code = pilha.back();
        pilha.pop_back();
        int index = hash_search(itens, n, item_code);

        if (index != -1) {
            vc_total += itens[index].preco;
            c--;
        }
    }

    int lucro = vt - vc_total;

    cout << lucro << " moeda(s)." << endl;

    return 0;
}
