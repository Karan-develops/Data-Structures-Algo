// LC - 150 - Medium - Evaluate Reverse Polish Notation
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int operate(const string &s,int &a,int &b){
    if(s=="+") return a+b;
    else if(s=="-") return b-a;
    else if(s=="*") return a*b;
    else if(s=="/") return b/a;
    else return -1;
}
int evalRPN(vector<string>&tokens){
    stack<int>st;
    for(string &s:tokens){
        if(s=="+" || s=="-" || s=="*" || s=="/"){
            int operand1=st.top(); st.pop();
            int operand2=st.top(); st.pop();
            int ans=operate(s,operand1,operand2);
            st.push(ans);
        } else{
            st.push(stoi(s));
        }
    }
    return st.top();
}
int main(){
    // Output: 9
    vector<string>tokens={"2","1","+","3","*"};
    // Output: 6
    vector<string>tokens2={"4","13","5","/","+"};
    // Output: 22
    vector<string>tokens3={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(tokens)<<endl;
    cout<<evalRPN(tokens2)<<endl;
    cout<<evalRPN(tokens3);
    return 0;
}