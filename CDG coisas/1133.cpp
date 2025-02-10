#include <iostream>
 
using namespace std;
 
int main() {
    
    int x, y;
    
    if(x > y)
    {
        for(int i=y+1; i < x; i++)
        {
            if(i%5 == 2 || i%5 == 3)
                cout << i << endl;
        }
    }
    
    else if(x < y)
    {
        for(int j=x+1; j < y; j++)
        {
            if(j%5 == 2 || j%5 == 3)
                cout << j << endl;
        }
    }
    
    return 0;
}