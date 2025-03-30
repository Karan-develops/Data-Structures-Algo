// LC - 224 - HARD - Basic Calculator
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int calculate(string s){
    stack<int>st;
    int ans=0,number=0,sign=1;
    for(char &ch:s){
        if(isdigit(ch)){
            number=10*number+(ch-'0');
        } else if(ch=='+'){
            ans+=sign*number;
            number=0;
            sign=1;
        } else if(ch=='-'){
            ans+=sign*number;
            number=0;
            sign=-1;
        } else if(ch=='('){
            st.push(ans);
            st.push(sign);
            ans=0,number=0,sign=1;
        } else if(ch==')'){
            ans+=sign*number;
            number=0;
            // Multiply Sign
            int topSign=st.top(); st.pop();
            ans*=topSign;
            // Add Prev ans
            int topAns=st.top(); st.pop();
            ans+=topAns;
        }
    }
    ans+=sign*number;
    return ans;
}
int main(){
    // Output: 2
    string s="1+1";
    // Output: 3
    string s2="2-1+2";
    // Output: 23
    string s3="(1+(4+5+2)-3)+(6+8)";
    cout<<calculate(s)<<endl;
    cout<<calculate(s2)<<endl;
    cout<<calculate(s3);
    return 0;
}