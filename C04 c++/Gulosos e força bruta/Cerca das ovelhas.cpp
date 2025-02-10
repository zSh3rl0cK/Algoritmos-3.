#include <iostream>
using namespace std;

int main()
{
	int m;
	cin >> m;
	
	int dim1 = 2, dim2 = m - dim1, dim_1c, dim_2c, area, area_max = 0;
	
	for(int i = 0; i < m; i++){
		area = dim1 * dim2/2;
		
		if(area > area_max){
			area_max = area;
			dim_1c = dim1/2; // lado maior
			dim_2c = dim2; // divide por 2 pois sao 2 lados menores
		}
		dim1+=2;
		dim2 = m - dim1;
	}
	
	cout << dim_1c << " x " << dim_2c << endl;
	
	return 0;
}