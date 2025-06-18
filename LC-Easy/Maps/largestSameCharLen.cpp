// LC - 1624 - Easy - Largest Substring Between Two Equal Characters
#include<iostream>
#include<unordered_map>
using namespace std;
int maxLengthBetweenEqualCharacters(string s){
    int n=s.length();
    int ans=-1;
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        if(mp.count(s[i]-'a')){
            ans=max(ans,i-mp[s[i]-'a']-1);
            continue;
        }
        
        mp[s[i]-'a']=i;
    }
    return ans;
}
int main(){
    // Output: 0
    string s="aa";
    // Output: 2
    string s2="abca";
    // Output: -1
    string s3="cbzxy";
    cout<<maxLengthBetweenEqualCharacters(s)<<endl;
    cout<<maxLengthBetweenEqualCharacters(s2)<<endl;
    cout<<maxLengthBetweenEqualCharacters(s3);
    return 0;
}