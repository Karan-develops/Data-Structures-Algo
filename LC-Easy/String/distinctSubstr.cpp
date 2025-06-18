// LC - 1876 - Easy - Substrings of Size Three with Distinct Characters
#include<iostream>
using namespace std;
int countGoodSubstrings(string s){
    int n=s.length();
    int ans=0;
    
    for(int i=0;i<n-2;i++){
        if(s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2]) ans++;
    }
    return ans;
}
int main(){
    // Output: 1
    string s="xyzzaz";
    // Output: 4
    string s2="aababcabc";
    cout<<countGoodSubstrings(s)<<endl;
    cout<<countGoodSubstrings(s2);
    return 0;
}