// GFG - Longest Substring with K Uniques
#include<iostream>
#include<unordered_map>
using namespace std;
int longestKSubstr(string &s,int k){
    int n=s.length();
    unordered_map<int,int>mp;
    
    int ans=0;
    int i=0,j=0;
    
    while(j<n){
        mp[s[j]-'a']++;
        
        while(mp.size()>k){
            mp[s[i]-'a']--;
            if(mp[s[i]-'a']==0){
                mp.erase(s[i]-'a');
            }
            i++;
        }
        if(mp.size()==k){
            ans=max(ans,j-i+1);
        }
        j++;
    }
    return ans==0?-1:ans;
}
int main(){
    // Output: 7
    string s="aabacbebebe";
    int k=3;
    // Output: -1
    string s2="aaaa";
    int k2=2;
    // Output: 7
    string s3="aabaaab";
    int k3=2;
    cout<<longestKSubstr(s,k)<<endl;
    cout<<longestKSubstr(s2,k2)<<endl;
    cout<<longestKSubstr(s3,k3);
    return 0;
}