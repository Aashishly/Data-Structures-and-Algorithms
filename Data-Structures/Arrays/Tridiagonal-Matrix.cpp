#include <iostream>
using namespace std;

int main() {

    int mat[10][10] = 
    {
        {50,1,2,3,4},
        {10,11,12,13,14},
        {20,21,22,23,24},
        {30,31,32,33,34},
        {40,41,42,43,44}
    };

    int row = 5;
    int col = 5;

    int i = 0;
    int j = 0;

    /* A tridiagonal matrix has nonzero elements only on the main diagonal, 
    the diagonal upon the main diagonal, and the diagonal below the main diagonal. */


    cout << "Tridiagonal Matrix" << endl;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if( i - j == 1)
            cout << mat[i][j] << " ";
            else if(i == j)
            cout << mat[i][j] << " ";
            else if(i - j == -1)
            cout << mat[i][j] << " ";
            else
            cout << "0" << " ";
        }
        cout << endl;
    }

    return 0;
}