#include<iostream>
#include<string>
#include<list>
using namespace std;
list<int> escolhida;
int solve(int peso[], int volume[], int valor[], int i, int cp, int cv, int n){
	int cont = 0;
	
	if(i >= n || cp <= 0 || cv <= 0)
		return 0;
	
	int s1 = solve(peso,volume,valor,i+1,cp,cv,n);
	int s2=0;
	if(cp >= peso[i] && cv >= volume[i]){
		s2 = solve(peso,volume,valor,i+1,cp-peso[i],cv-volume[i],n)+valor[i];
		cont++;
	}
	return max(s1,s2);
}

int main(){
	int peso[5] = {263,127,254,134,111};
	int volume[5] = {455,521,857,65,12};
	int valor[5] = {500,410,320,315,280};
	
	cout<< solve(peso,volume,valor,0,400,1000,5) << endl;
		
}