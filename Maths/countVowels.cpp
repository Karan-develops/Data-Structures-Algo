// GFG - Count Unique Vowel Strings
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution{
    int fact(int n){
        int fac=1;
        
        while(n>=1){
            fac*=n;
            n--;
        }
        return fac;
    }
    public:
    int vowelCount(string &s){
        unordered_map<char,int>mp;
        
        auto checkVowel=[](char &ch){
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        };
        
        for(char &ch:s){
            if(checkVowel(ch)){
                mp[ch]++;
            }
        }
        
        if(mp.size()==0) return 0;
        
        int ans=fact(mp.size());
        
        for(auto &it:mp){
            ans*=it.second;
        }
        return ans;
    }
};
int main(){
    // Output: 120
    string s="aeiou";
    // Output: 2
    string s2="ae";
    // Output: 4
    string s3="aacidf";

    Solution sol;
    cout<<sol.vowelCount(s)<<endl;
    cout<<sol.vowelCount(s2)<<endl;
    cout<<sol.vowelCount(s3);
    return 0;
}