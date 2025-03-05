#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&st,int &data){
    if(st.empty()){
        st.push(data);
        return;
    }
    int temp=st.top();
    st.pop();
    // RR
    insertAtBottom(st,data);
    // Backtrack
    st.push(temp);
}
void reverseStack(stack<int>&st){
    if(st.empty()) return;
    int topElement=st.top();
    st.pop();
    // Popping all the elements.
    reverseStack(st);
    // While returning putting elements at the bottom.
    insertAtBottom(st,topElement);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}