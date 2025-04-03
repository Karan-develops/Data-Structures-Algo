// LC - 1249 - Minimum Remove to Make Valid Parentheses
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
string minRemoveToMakeValid(string s){
    int n=s.length();
    stack<int>st;
    unordered_set<int>toRemoveSet;
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            if(st.empty()) toRemoveSet.insert(i);
            else st.pop();
        }
    }
    while(!st.empty()){
        toRemoveSet.insert(st.top());
        st.pop();
    }
    string ans="";
    for(int i=0;i<n;i++){
        if(toRemoveSet.find(i)==toRemoveSet.end()) ans.push_back(s[i]);
    }
    return ans;
}
int main(){
    // Output: "lee(t(c)o)de"
    string s1="lee(t(c)o)de)";
    // Output: "ab(c)d"
    string s2="a)b(c)d";
    // Output: ""
    string s3="))((";
    cout<<minRemoveToMakeValid(s1)<<endl;
    cout<<minRemoveToMakeValid(s2)<<endl;
    cout<<minRemoveToMakeValid(s3);
    return 0;
}