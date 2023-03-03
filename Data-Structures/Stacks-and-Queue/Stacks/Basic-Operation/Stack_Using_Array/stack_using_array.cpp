#include <iostream>
using namespace std;

#define size 10

class Stack{
    int stack[size];
    int top;

    public:
        void push(int pushnum);
        int pop();
        void display();
        int front();
        bool empty();
    Stack(){
        top = -1;
    }
    
};

void Stack::push(int pushnum){

    if(top == size-1){
    cout << "Stack is Full" << endl;
    }
    else{
        top += 1;
        stack[top] = pushnum;
    }

}

int Stack::pop(){

    int temp;

    if(top == -1){
        cout << "Empty stack" << endl;
    }
    else{
        temp = stack[top];
        top -= 1;
    }

    return temp;
}

void Stack::display(){
    if(top == -1){
        cout << "Empty stack" << endl;
    }
    else{
        for(int i=top; i>=0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int Stack::front(){
    if(top == -1){
        cout << "Empty stack" << endl;
    }
    else{
        cout << stack[top] << endl;
    }
}

bool Stack::empty(){
    if(top == -1)
    return true;
    else
    false;
}

int main(){

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();
    // st.pop();

    st.front();




    return 0;
}