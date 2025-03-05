#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char>st;
    string s="abcd";
    for(auto i:s){
        st.push(i);
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}