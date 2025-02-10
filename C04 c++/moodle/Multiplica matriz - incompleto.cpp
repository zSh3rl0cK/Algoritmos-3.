#include <iostream>
using namespace std;

void multiplica_matriz(int A[60][60], int B[60][60], int a, int b, int ac, int bc){
	int C[50][50]; // matriz resultante
	
	int conta_linha = 0;
	
    if(ac != b){
        cout << "incompatible dimensions" << endl;
	}
    else{
        for(int i = 1; i < a; i++){
            for(int j = 1; j < bc; j++){
                C[i][j] = 0;
                for(int k = 1; k < ac; k++){
                	conta_linha++;
                    C[i][j] = C[i][j] + A[i][k]*B[k][j];
				}
			}
		}
	}
	
	cout << conta_linha << endl;
}

int main()
{
	int a, b, ac, bc; // numero de linhas e colunas da matriz a e b
	int c, cc, d, dc;
	
	a = 20, ac = 35;
	b = 35, bc = 15;
	c = 15, cc = 10;
	d = 10, dc = 55;
	
	
	int A[60][60], B[60][60], C[60][60], D[60][60];
	
	for(int i = 0; i < a; i++){
		for(int j = 0; j < ac; j++){
			A[i][j] = 1;
		}
	}
	
	for(int i = 0; i < b; i++){
		for(int j = 0; j < bc; j++){
			B[i][j] = 1;
		}
	}
	
	multiplica_matriz(A, B, a, b, ac, bc);
	
	return 0;
}