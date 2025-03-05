#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&st,int &data){
    if(st.empty()){
        st.push(data);
        return;
    }
    int temp=st.top();
    st.pop();
    // RR
    solve(st,data);
    // Backtrack
    st.push(temp);
}
void insertAtBottom(stack<int>&st){
    if(st.empty()){
        cout<<"Stack is Empty."<<endl;
        return;
    }
    int data=st.top();
    st.pop();
    solve(st,data);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    insertAtBottom(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}