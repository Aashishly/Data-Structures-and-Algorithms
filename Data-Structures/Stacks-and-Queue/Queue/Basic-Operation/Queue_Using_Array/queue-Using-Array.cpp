#include <iostream>
using namespace std;

#define size 20

class queue{
    int *arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[size];
        front = -1;
        back = -1;
    }

    void push(int elem);
    int pop();
    int peek();
    bool empty();
    void show();

};

void queue::push(int elem){

    if(back == size - 1){
        cout << "Queue Overflow" << endl;
        return;
    }

    back++;
    arr[back] = elem;

    if(front == -1)
    front++;
}

int queue::pop(){

    if(front == -1|| front > back){
        cout << "Queue Underflow" << endl;
        return -1;
    }

    int temp = arr[front];
    front++;
    return temp;
}

int queue::peek(){
     
    if(front == -1|| front > back){
        cout << "Queue Underflow" << endl;
        return -1;
    }

    return arr[front];
}

bool queue::empty(){

    if(front == -1|| front > back){
        cout << "Queue Underflow" << endl;
        return true;
    }

    return false;
}

void queue::show(){

    for(int i=front; i<=back; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    queue q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);

    cout << q1.pop() << endl;
    q1.show();

    cout << q1.peek() << endl;

    if(q1.empty())
    cout << "Queue is Empty"<< endl;
    else
    cout << "Queue is not Empty" << endl;


    return 0;
}