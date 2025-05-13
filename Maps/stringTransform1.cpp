// LC - 3335 - Medium - Total Characters in String After Transformations I
// Good Map Question
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
const int MOD=1e9+7;
// Approach 1 - Using Map - TLE
int lengthAfterTransformationsTLE(string s,int t){
    int n=s.length();
    unordered_map<char,int>mp;
    for(char &ch:s) mp[ch]++;

    for(int i=0;i<t;i++){
        unordered_map<char,int>temp;
        for(auto &it:mp){
            char ch=it.first;
            int freq=it.second;
            
            if(ch!='z'){
                temp[ch+1]=(temp[ch+1]+freq)%MOD;
            } else{
                temp['a']=(temp['a']+freq)%MOD;
                temp['b']=(temp['b']+freq)%MOD;
            }
        }
        // Don't call copy constructor
        mp=move(temp);
    }
    int ans=0;
    for(auto &it:mp){
        ans=(ans+it.second)%MOD;
    }
    return ans;
}
int lengthAfterTransformations(string s,int t){
    int n=s.length();
    vector<int>mp(26,0);
    for(char &ch:s) mp[ch-'a']++;

    for(int i=0;i<t;i++){
        vector<int>temp(26,0);
        for(int i=0;i<26;i++){
            char ch=i+'a';
            int freq=mp[i];
            if(ch!='z'){
                temp[ch-'a'+1]=(temp[ch-'a'+1]+freq)%MOD;
            } else{
                temp[0]=(temp[0]+freq)%MOD;
                temp[1]=(temp[1]+freq)%MOD;
            }
        }
        mp=move(temp);
    }
    int ans=0;
    for(int &i:mp){
        ans=(ans+i)%MOD;
    }
    return ans;
}
int main(){
    // Output: 7
    string s="abcyy";
    int t=2;
    // Output: 5
    string s2="azbk";
    int t2=1;
    cout<<lengthAfterTransformations(s,t)<<endl;
    cout<<lengthAfterTransformations(s2,t2);
    return 0;
}