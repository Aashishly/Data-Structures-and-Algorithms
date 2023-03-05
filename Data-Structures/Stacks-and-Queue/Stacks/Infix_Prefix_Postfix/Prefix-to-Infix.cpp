#include <bits/stdc++.h>
using namespace std;

bool isOperator(char op) {
  if(op =='+' || op =='*' || op =='-' || op =='/'){
    return true;
  }
  return false;
}

string prefixtoinfix(string prefix){

    stack <string> mystack;

    for(int i = prefix.length()-1; i >= 0; i--){
        if(isOperator(prefix[i])){
            string op1 = mystack.top();
            mystack.pop();
            string op2 = mystack.top();
            mystack.pop();

            string exp = "(" + op1 + prefix[i] + op2 + ")";
            mystack.push(exp);
        }
        else{
            mystack.push(string(1, prefix[i]));
        }
    }
    return mystack.top();
}

int main(){

    cout << prefixtoinfix("*+AB-CD");

    return 0;
}