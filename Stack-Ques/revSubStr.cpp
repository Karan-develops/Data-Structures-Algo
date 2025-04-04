// LC - 1190 - Medium - Reverse Substrings Between Each Pair of Parentheses
// 2 Approaches - WarmHole Teleportation
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
string reverseParentheses(string s){
    stack<int>openBrackets;
    string ans="";
    for(char &ch:s){
        if(ch=='(') openBrackets.push(ans.length());
        else if(ch==')'){
            int start=openBrackets.top();
            openBrackets.pop();
            reverse(ans.begin()+start,ans.end());
        } else ans.push_back(ch);
    }
    return ans;
}
string warmholeTeleportation(string s){
    int n=s.length();
    stack<int>openBrackets;
    vector<int>doors(n);
    for(int i=0;i<n;i++){
        if(s[i]=='(') openBrackets.push(i);
        else if(s[i]==')'){
            int j=openBrackets.top();
            openBrackets.pop();
            doors[i]=j;
            doors[j]=i;
        }
    }
    string ans="";
    int direction=1;
    for(int i=0;i<n;i+=direction){
        if(s[i]=='(' || s[i]==')'){
            i=doors[i];
            direction=-direction;
        } else ans.push_back(s[i]);
    }
    return ans;
}
int main(){
    // Output: "dcba"
    string s="(abcd)";
    // Output: "iloveu"
    string s2="(u(love)i)";
    // Output: "leetcode"
    string s3="(ed(et(oc))el)";
    cout<<warmholeTeleportation(s)<<endl;
    cout<<warmholeTeleportation(s2)<<endl;
    cout<<warmholeTeleportation(s3);
    return 0;
}