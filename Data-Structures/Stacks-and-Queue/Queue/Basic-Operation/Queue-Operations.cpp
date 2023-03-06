#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue <int> ques;

    ques.push(10);
    ques.push(20);
    ques.push(30);
    ques.push(40);
    ques.push(50);
    
    cout << ques.front() << endl;
    cout << ques.back() << endl;


    while(!ques.empty()){
        cout << ques.front() << " ";
        ques.pop();
    }
    cout << endl;


    cout << ques.empty() << endl;

    return 0;
}