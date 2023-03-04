#include <bits/stdc++.h> 
using namespace std;

int prec(char c){
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

string infixtoPostfix(string s){

    stack <char> st;
    string res;

    

    for(int i=0; i<s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            res = res + s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res = res + st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }  
        else{
            while(!st.empty() && prec(st.top()) > prec(s[i])){
                res = res + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res = res + st.top();
        st.pop();
    }
    return res;

}

string infixtoPrefix(string s){

    reverse(s.begin(), s.end());

    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            s[i] = ')';
            i++;
        }
        else if(s[i] == ')'){
            s[i] = '(';
            i++;
        }
    }

    string prefix = infixtoPostfix(s);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main(){

    cout << infixtoPrefix("(a-b/c)*(a/k-l)");

    return 0;
}