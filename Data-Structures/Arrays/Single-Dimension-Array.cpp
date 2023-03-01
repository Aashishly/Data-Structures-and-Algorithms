#include <iostream>
using namespace std;

int main(){

    // Declaring and Initializing Array
    int Arr[5] = {10,12,30,65,0};

    // Traversing Array
    for(int i:Arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}