// LC - 20 - Easy - Valid Parentheses
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool isValid(string s){
    int n=s.length();
    stack<int>st;
    for(char &ch:s){
        if(st.empty()) st.push(ch);
        else if((st.top()=='(' && ch==')') || (st.top()=='{' && ch=='}') || (st.top()=='[' && ch==']')){
            st.pop();
        } else{
            st.push(ch);
        }
    }
    return st.empty();
}
int main(){
    // Output: true
    string s="()";
    // Output: true
    string s2="()[]{}";
    // Output: false
    string s3="(]";
    // Output: true
    string s4="([])";
    cout<<isValid(s)<<endl;
    cout<<isValid(s2)<<endl;
    cout<<isValid(s3)<<endl;
    cout<<isValid(s4);
    return 0;
}