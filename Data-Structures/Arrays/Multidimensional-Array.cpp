#include <iostream>
using namespace std;

int main(){

    //declaration and initialization  
    int Array[3][3] = 
    {
        {2, 5, 5},  
        {4, 0, 3},  
        {9, 1, 8} 
    };

    //traversal
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}