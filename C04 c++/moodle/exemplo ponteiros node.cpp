#include <iostream>
using namespace std;

struct node{
	   int dado;
	   node* proximo;	
};

int main(){
	
	int a; 
	int *p;
	char b;
	p = &a;
	char *c; 
	c = &b; 
	a = 10;
	*p = 12; 
	int x[5]; 
	x[3] = 18;
	*(x + 1) = 12; 
	p = a; 
	p = x;
	cout << x[3] << endl;  
	cout << x << endl; 
	
	return 0;
}