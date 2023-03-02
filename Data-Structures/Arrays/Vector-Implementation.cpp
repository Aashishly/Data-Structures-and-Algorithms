#include <iostream>
#include <vector>
using namespace std;

int main(){

    // initializing Vector
    vector <int> arr;

    // Inserting in the Vector
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(9);

    // Printing the Vector
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Poping from the Vector
    arr.pop_back();
    arr.pop_back();

    // Printing the Vector after poping
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Inserting the value at any position
    arr.insert(arr.begin() + 1, 12);
    arr.insert(arr.begin() + 2, 84);

     // Printing the Vector after inserting
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // erase() function is used to remove elements from a container from the specified position.
    arr.erase(arr.begin()+4);
    arr.erase(arr.end()-3);

     // Printing the Vector after erasing
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // clear() function is used to remove all the elements of the vector.
    arr.clear();



    return 0;
}