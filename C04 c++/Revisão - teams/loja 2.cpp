#include <iostream>
#include <list>
#include <string>
#include <locale.h>

using namespace std;

struct item{
    int codigo;
    string nome;
    int preco;
    int status;
};

int h1(int k, int m){
	int result = k % m;
	
	if(result < 0)
		result += m;
	
    return result;
}

int hash_linear(int k, int m, int i){
	int result = (h1(k, m) + i) % m;

	
    return result;
}

int hash_insert(item tabela_hash[], item valor[], int m){
    int pos = -1;
    int i = 0;

    while (i < m){
        pos = hash_linear(valor[i].codigo, m, i);

        if (tabela_hash[pos].status != 1) {
            tabela_hash[pos] = valor[i];
            tabela_hash[pos].status = 1;

            return pos;
        }

        i++;
    }

    return -1;
}

int hash_search(item tabela_hash[], int codigo, int m){
    int pos, i = 0;
    int status;

    while (i < m) {
        pos = hash_linear(codigo, m, i);
        status = tabela_hash[pos].status;

        if (status == 1 && tabela_hash[pos].codigo == codigo)
            return pos;

        i++;
    }

    return -1;
}

int main(){
    setlocale(LC_ALL, "");

    int m = 43;

    item tabela_hash[m];

    list<int> vendas;
    list<int> compras;

    item itens[m];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> itens[i].codigo;
        cin >> itens[i].nome;
        cin >> itens[i].preco;

        hash_insert(tabela_hash, itens, m);
    }

    int vi;
    cin >> vi;

    while (vi != -1){
        vendas.push_back(vi);
        cin >> vi;
    }

    int ci;
    cin >> ci;

    while (ci != -1){
        compras.push_front(ci);
        cin >> ci;
    }

    int v, c;
    int cod_item, pos_item;
    int l = 0;
    int vt = 0, vc = 0;

    cin >> v >> c;

    while (v != 0 && !vendas.empty()){
        cod_item = vendas.front();
        vendas.pop_front();

        pos_item = hash_search(tabela_hash, cod_item, m);

        if (pos_item != -1){
            vt += tabela_hash[pos_item].preco;

            v--;
        }
    }

    while (c != 0 && !compras.empty()){
        cod_item = compras.front();
        compras.pop_back();

        pos_item = hash_search(tabela_hash, cod_item, m);

        if (pos_item != -1){
            vc += tabela_hash[pos_item].preco;

            c--;
        }
    }

    l = vt - vc; // cálculo lucro
    cout << l << " moeda(s)." << endl;

    return 0;
}
