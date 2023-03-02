#include <iostream>
using namespace std;

int  main(){


    int mat[10][10] = 
    {
        {12,34,55},
        {22,90,28},
        {67,44,8}
    };

    int row = 3;
    int col = 3;


    /* Lower triangular matrix is a matrix which contains elements below 
    principal diagonal including principal diagonal elements and rest of the elements are 0. */

    cout << "Lower Triangular Matrix" << endl;
    // Lower triangular matrix
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i < j)
            cout << "0" << " ";
            else
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;



    /*Upper triangular matrix is a matrix which contains elements above 
    principal diagonal including principal diagonal elements and rest of the elements are 0.*/


    cout << "Upper Triangular Matrix" << endl;
    // Upper triangular matrix
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i > j)
            cout << "0" << " ";
            else
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}