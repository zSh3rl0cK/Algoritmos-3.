#include <iostream>
#include <list>
#include <locale.h>
using namespace std;

struct Item{
	int codigo;
	string nome;
	int preco;
	int status;
};

int hash_aux(int k,int m){
	int i = k % m;
	if(i < 0)
		i = i + m;
	return i;	
}

int hash_linear(int k,int m, int i){
	return (hash_aux(k,m)+i)%m;	
}

int inserir_item(Item tabela_hash[], Item valor, int m){
	int pos = -1;
	int i = 0;
	
	while(i < m){
		pos = hash_linear(valor.codigo, m, i);
		
		if(tabela_hash[pos].status != 1){
			tabela_hash[pos] = valor;
			tabela_hash[pos].status = 1;
			return pos;
		}
		
		i++;
	}
	return -1;	
}

int buscar_item(Item tabela_hash[], int codigo, int m){
	int pos, i = 0;
	int status = 1;
	
	do{
		pos = hash_linear(codigo, m, i);
		status = tabela_hash[pos].status;
		
		if(tabela_hash[pos].codigo == codigo)
			return pos;
		
		i++;
	}while(tabela_hash[pos].status != 0 && i < m);
	
	return -1;		
}

int main(){
	setlocale(LC_ALL,"");
	
	const int m = 43;
	
	Item tabela_hash[m];
	list<int> vendas;
	list<int> compras; 
	
	Item item;	
	
	int n;
	cin >> n;
	
	while(n < 0 || n > 43){
		cin >> n;
	}
	
	for(int i = 0; i < n; i++){
		cin>>item.codigo;
		cin>>item.nome;
		cin>>item.preco;
		inserir_item(tabela_hash, item, m);
	}
	
	int vi;
	cin >> vi;
	
	while(vi != -1){
		vendas.push_back(vi); //fila
		cin >> vi;
	}
	
	int ci;
	
	cin >> ci;
	
	while(ci != -1){
		compras.push_front(ci); //pilha
		cin >> ci;
	}
	
	int v, c, cod_item, pos_item;
	int l;
	int vt=0, vc=0;
	
	cin >> v >> c;
	
	while(v!=0){
		cod_item = vendas.front(); 
		vendas.pop_front();
		
		pos_item = buscar_item(tabela_hash, cod_item, m);
		item = tabela_hash[pos_item];
		vt += item.preco;
		
		v--;
	}
	while(c!=0){
		cod_item = compras.front();
		
		compras.pop_back();
		pos_item = buscar_item(tabela_hash, cod_item, m);
		item = tabela_hash[pos_item];
		
		vc += item.preco;
		
		c--;
	}
	
	l = vt - vc;
	cout<< l << " moeda(s)." << endl; 
	
	return 0;
}