// LC - 392 - Easy - Is Subsequence
#include<iostream>
using namespace std;
bool isSubsequence(string s,string t){
    int m=s.length(),n=t.length();
    int i=0,j=0;
    while(i<m && j<n){
        if(s[i]==t[j]) i++,j++;
        else j++;
    }
    if(i==m) return true;
    return false;
}
int main(){
    // Output: true
    string s="abc",t="ahbgdc";
    // Output: false
    string s2="axc",t2="ahbgdc";
    cout<<isSubsequence(s,t)<<endl;
    cout<<isSubsequence(s2,t2);
    return 0;
}