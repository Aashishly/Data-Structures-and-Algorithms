#include <iostream>
#include <queue>
using namespace std;

int main(){

    cout << "Max heap" << endl;
    priority_queue<int> pq_max; //maxHeap

    pq_max.push(1);
    pq_max.push(2);
    pq_max.push(3);
    pq_max.push(4);
    pq_max.push(5);

    while(!pq_max.empty()){
        int val = pq_max.top();
        cout << val << " ";
        pq_max.pop();
    }
    cout << endl;

    cout << "---------" << endl;

    cout << "Min heap" << endl;
    priority_queue<int, vector<int>, greater<int> > pq; //minHeap

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    while(!pq.empty()){
        int val = pq.top();
        cout << val << " ";
        pq.pop();
    }
    cout << endl;


    return 0;
}
