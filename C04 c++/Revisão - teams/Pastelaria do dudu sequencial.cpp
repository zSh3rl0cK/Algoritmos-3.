#include <iostream>
#include <string>

using namespace std;

struct dados{
	string nome;
	int quantidade;
};

int main()
{
	dados produtos[100];
	
	int n;
	
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
        cin >> produtos[i].nome;
        cin >> produtos[i].quantidade;
        cin.ignore();
    }
	
	string search;
	
	getline(cin, search);
	
	int enc = 0;
	for(int i = 0; i < n; i++){
		if(search == produtos[i].nome){
			cout << search << " em estoque!" << endl;
			enc = 1;
			break;
		}
	}
	
	if(enc == 0)
		cout << "Nao existe " << search << " em estoque" << endl;
	
	return 0;
}