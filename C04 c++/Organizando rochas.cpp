#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

struct dados{
    string nome;
    string tipo;
};

struct treenode{
    dados info;
    treenode *esq;
    treenode *dir;
};

typedef treenode *treenodeptr;

void TInsert(treenodeptr &p, string nome, string tipo){
    if(p == NULL){
        p = new treenode;
        p->info.nome = nome;
        p->info.tipo = tipo;
        
        p->esq = NULL;
        p->dir = NULL;
    }
    
    else{
        if(nome < p->info.nome){
            TInsert(p->esq, nome, tipo);
        }
        else
            TInsert(p->dir, nome, tipo);
    }
}

void tSearch(treenodeptr p, string x){
    if(p == NULL) // elemento não encontrado
        cout << "Rocha nao encontrada" << endl;
        
    else
        if(x == p->info.nome){ // elemento encontrado na raiz
                cout << "Nome: " << x << endl;
                cout << "tipo: " << p->info.tipo << endl;
        }
            
    else
        if(x < p->info.nome) // procura na subárvore esquerda
            tSearch(p->esq,x);
            
    else // procura na subárvore direita
        tSearch(p->dir,x);
}

treenodeptr tMenor(treenodeptr &raiz){
    treenodeptr t;
    
    t = raiz;
    
    if(t->esq == NULL){
        raiz = raiz->dir;
        return t;
    }
    else
        return tMenor(raiz->esq);
    
}

void tRemove(treenodeptr &raiz, dados x){
    treenodeptr p;
    if(raiz == NULL){
        cout << "Rocha nao encontrada para remocao" << endl;
    }
    
    if(x.nome == raiz->info.nome && x.tipo == raiz->info.tipo){
        p = raiz;
        
        if(raiz->esq == NULL)
            raiz = raiz->dir;
        
        else{
            if(raiz->dir == NULL)
                raiz = raiz->esq;
            
            else{
                p = tMenor(raiz->dir);
                raiz->info = p->info;
            }
        }
        
        delete p;
        cout << "Rocha removida com sucesso" << endl;
    }
    
    else{
        if(x.nome < raiz->info.nome)
            return tRemove(raiz->esq, x);
        else
            return tRemove(raiz->dir, x);
    }
}

int main(){
    setlocale(LC_ALL, "");
    
    treenodeptr arvore = NULL;
    
    int op; // opcao escolhida
    string nome, tipo; // nome e tipo da rocha
    
    
    while(cin >> op && op != 0){
        if(op == 1){
            // insrind o nome e o tipo da rocha
            cin >> nome;
            cin >> tipo;
            
            TInsert(arvore, nome, tipo);
        }
        
        else if(op == 2){
            // fazendo a busca pelo nome pesquisado
            string pesq;
            cin >> pesq;
            
            tSearch(arvore, pesq);
        }
        else if(op == 3){
            // inserindo o nome e o tipo da rocha para a remocao
            dados remocao;
            cin >> remocao.nome;
            cin >> remocao.tipo;
            
            tRemove(arvore, remocao);
        }
    }
    
    return 0;
}