#include <iostream>
using namespace std;

struct ponto{
	int x, y;
};

float area_triangulo(ponto a, ponto b, ponto c){
	float area = a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x;
	
	area = area/2;
	return area;
}

int posicao_relativa(ponto a, ponto b, ponto p){
	float area = area_triangulo(a,b,p);
	
	if(area > 0){
		return 1; // ponto p está à esquerda do segmento ab (sentido anti horario)
	}
	
	else if(area < 0){
		return -1; // ponto p está à esquerda do segmento ab (sentido horario)
	}
	
	else{
		return 0; // pontos colineares
	}
	
	return new;
}

int main()
{
	ponto p = {3,2}, p1 = {1,2}, p2 = {4,4}, p3 = {4,1};
	ponto p4 = {4,4}, p5 = {5,5}, p6 = {6,6};
	
	// area do triangulo formado pelos pontos
	float area = area_triangulo(p1,p2,p3);
	
	// coordenadas baricentricas
	float L1 = area_triangulo(p,p2,p3)/area;
	float L2 = area_triangulo(p1,p,p3)/area;
	float L3 = area_triangulo(p1,p2,p)/area;

	cout << L1 << " " << L2 << " " << L3;	
	
	int pos = posicao_relativa(p4,p5,p6);
	if(pos == 1){
		cout << "À esquerda" << endl;
	}
	else if(pos == -1){
		cout << "À direita" << endl;
	}
	else{
		cout << "colineares" << endl;
	}
	
	return 0;
}