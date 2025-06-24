// GFG - Lexicographically Largest String After K Deletions
#include<iostream>
#include<stack>
using namespace std;
string maxSubseq(string &s,int k){
    stack<char>st;
    
    for(auto &ch:s){
        while(!st.empty() && st.top()<ch && k>0){
            st.pop();
            k--;
        }
        st.push(ch);
    }
    
    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
    
    string ans="";
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
}
int main(){
    // Output: tz
    string s="ritz";
    int k=2;
    // Output: zr
    string s2="zebra";
    int k2=3;
    cout<<maxSubseq(s,k)<<endl;
    cout<<maxSubseq(s2,k2);
    return 0;
}