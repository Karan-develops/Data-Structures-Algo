// LC - 242 - Easy - Valid Anagram
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    bool isAnagram(string s, string t) {
        int m=s.length(),n=t.length();
        if(m!=n) return false;
        vector<int>mp(26,0);
        for(char &ch:s) mp[ch-'a']++;
        for(char &ch:t) mp[ch-'a']--;
        for(int i=0;i<26;i++){
            if(mp[i]!=0) return false;
        }
        return true;
    }
};
int main(){
    // true
    string s1="anagram",t1="nagaram";
    // false
    string s2="rat",t2="car";
    Solution sol;
    cout<<sol.isAnagram(s1,t1)<<endl;
    cout<<sol.isAnagram(s2,t2);
    return 0;
}