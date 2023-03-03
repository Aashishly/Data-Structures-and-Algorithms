#include <iostream>
#include <stack>
using namespace std;

int main(){

    // initializing stack
    stack <int> st;

    // push() operation
    st.push(34);
    st.push(87);
    st.push(23);

    // size() operation
    cout << st.size() << endl;

    // empty(), pop() and top() operation
   while(!st.empty()){
    int stacknum = st.top();
    cout << stacknum << " ";
    st.pop();
   }
   cout << endl;



   return 0;

}