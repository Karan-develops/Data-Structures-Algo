// LC - 32 - HARD
#include<iostream>
#include<stack>
using namespace std;
int longestValidParentheses(string s){
    if(s=="") return 0;
    int n=s.length();
    stack<int>st;
    st.push(-1);
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(i);
        else{
            st.pop();
            // Pushing i bcoz we are tracking count of parantheses
            if(st.empty()) st.push(i);
            else{
                int len=i-st.top();
                ans=max(ans,len);
            }
        }
    }
    return ans;
}
int main(){
    string s1="(()"; // OP - 2
    string s2=")()())"; // OP - 4
    string s3=""; // OP - 0
    cout<<longestValidParentheses(s2);
    return 0;
}