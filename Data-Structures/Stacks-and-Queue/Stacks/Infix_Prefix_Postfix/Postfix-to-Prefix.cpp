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

string postfixtoPrefix(string s){

    stack <string> st;

    for(int i=0; i<s.length(); i++){
        if(isOperator(s[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = s[i] + op2 + op1;
            st.push(temp);
        }
        else{
            st.push(string(1,s[i]));
        }

    }

    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){

    cout << postfixtoPrefix("ABC/-AK/L-*");

    return 0;
}