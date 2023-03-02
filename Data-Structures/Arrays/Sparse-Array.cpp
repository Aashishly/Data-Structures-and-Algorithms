#include <iostream>
using namespace std;

int main(){

    // A sparse matrix is a matrix in which majority of the elements are 0.

    int arr[10][10] = 
    {
        {0, 0, 9},
        {5, 0, 8},
        {7, 0, 0}
    };

    int row = 3;
    int col = 3;
    int ctr = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == 0)
            ctr++;
        }
    }

    cout<<"The number of zeros in the matrix are "<< ctr <<endl;

    // Checking for Sparse Array
    if(ctr > ((row * col) / 2))
    cout<<"This is a sparse matrix"<<endl;
    else
    cout<<"This is not a sparse matrix"<<endl;


    // Printing Sparse Array
     for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}