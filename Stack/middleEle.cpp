#include<iostream>
#include<stack>
using namespace std;
void middleElInStack(stack<int>&st,int& size){
    if(st.size()==0){
        cout<<"Stack is Empty."<<endl;
        return;
    }
    if(st.size()==(size/2)+1){
        cout<<st.top()<<endl;
        return;
    }
    int temp=st.top();
    st.pop();
    // RR
    middleElInStack(st,size);
    // Backtrack
    st.push(temp);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    int s=st.size();
    middleElInStack(st,s);
    return 0;
}