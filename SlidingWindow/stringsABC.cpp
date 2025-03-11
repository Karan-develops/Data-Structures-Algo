// LC - 1358 - Medium
#include<iostream>
#include<unordered_map>
using namespace std;
int numberOfSubstrings(string s){
    int n=s.length();
    unordered_map<char,int>mp;
    int i=0,j=0;
    int ans=0;
    while(j<n){
        mp[s[j]]++;
        while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
            ans+=n-j;
            mp[s[i]]--;
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // OP - 10
    string s1="abcabc";
    // OP - 3
    string s2="aaacb";
    // OP - 1
    string s3="abc";
    cout<<numberOfSubstrings(s1)<<endl;
    cout<<numberOfSubstrings(s2)<<endl;
    cout<<numberOfSubstrings(s3);
    return 0;
}