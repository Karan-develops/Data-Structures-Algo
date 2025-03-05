// Stack has by-default property
// Data you put in stack will be returned in reverse order while popping it.
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // Pop the top element
    st.pop();
    // Accessing the top element
    cout<<st.top()<<endl;
    // stack is empty or not
    cout<<st.empty()<<endl;
    // printing the stack
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    cout<<st.empty()<<endl;
    return 0;
}