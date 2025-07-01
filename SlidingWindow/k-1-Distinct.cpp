// GFG - Substrings of length k with k-1 distinct elements
#include<iostream>
#include<unordered_map>
using namespace std;
int substrCount(string &s,int k){
    int n=s.length();
    unordered_map<int,int>mp;
    
    int ans=0;
    int i=0,j=0;
    
    while(j<n){
        mp[s[j]-'a']++;
        
        if(j-i+1==k){
            if(mp.size()==k-1) ans++;
            
            mp[s[i]-'a']--;
            
            if(mp[s[i]-'a']==0){
                mp.erase(s[i]-'a');
            }
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // Output: 1
    string s="abcc";
    int k=2;
    // Output: 3
    string s2="aabab";
    int k2=3;
    cout<<substrCount(s,k)<<endl;
    cout<<substrCount(s2,k2);
    return 0;
}