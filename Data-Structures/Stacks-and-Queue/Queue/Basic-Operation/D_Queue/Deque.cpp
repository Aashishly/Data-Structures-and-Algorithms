#include <bits/stdc++.h>
using namespace std;

int main(){

    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(100);
    dq.push_front(900);
    dq.push_front(300);

    dq.pop_back();
    dq.pop_front();

    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;

    return 0;
}