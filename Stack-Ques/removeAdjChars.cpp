// LC - 1047 - Easy - Remove All Adjacent Duplicates In String
// 2 Approaches - With Stack - Without Stack
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
string removeDuplicates(string s){
    stack<char>st;
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        if(st.empty() || st.top()!=s[i]) st.push(s[i]);
        else st.pop();
    }
    string ans="";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
string removeDuplicates2(string s){
    int n=s.length();
    int i=0;
    string ans="";
    while(i<n){
        if(ans.length() && (s[i]==ans[ans.length()-1])) ans.pop_back();
        else ans.push_back(s[i]);
        i++;
    }
    return ans;
}
int main(){
    // Output: "ca"
    string s="abbaca";
    // Output: "ay"
    string s2="azxxzy";
    cout<<removeDuplicates2(s)<<endl;
    cout<<removeDuplicates2(s2);
    return 0;
}