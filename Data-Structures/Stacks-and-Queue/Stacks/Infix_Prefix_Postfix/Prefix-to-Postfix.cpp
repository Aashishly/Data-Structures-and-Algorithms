#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string prefixtoPostfix(string s){
    stack <string> st;

    for(int i=s.length()-1; i>=0; i--){
        if(isOperator(s[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = op1 + op2 + s[i];
            st.push(temp);
        }
        else{
            st.push(string(1, s[i]));
        }
    }

    return st.top();
}

int main(){

    cout << prefixtoPostfix("*-A/BC-/AKL") << endl;

    return 0;
}