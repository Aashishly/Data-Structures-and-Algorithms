#include <bits/stdc++.h>
using namespace std;


string postfixToInfix(string postfix){
    stack<string> myStack;
    
    for(int i=0; i<postfix.length(); i++){
        if(isalpha(postfix[i])){
            string opr(1, postfix[i]);
            myStack.push(opr);
        }
        else{
            string opr1 = myStack.top();
            myStack.pop();
            string opr2 = myStack.top();
            myStack.pop();
            string exp = "(" + opr2 + postfix[i] + opr1 + ")";
            myStack.push(exp);
        }
    }

    return myStack.top();
}

int main(){
    

    string res = postfixToInfix("abc++");
    cout << res;

    return 0;
}