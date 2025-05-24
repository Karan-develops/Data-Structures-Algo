// LC - 2186 - Medium - Minimum Number of Steps to Make Two Strings Anagram II
#include<iostream>
#include<vector>
using namespace std;
int minSteps(string s, string t) {
    int ans=0;
    vector<int>v1(26,0);
    vector<int>v2(26,0);

    for(char &ch:s) v1[ch-'a']++;
    for(char &ch:t) v2[ch-'a']++;

    for(int i=0;i<26;i++){
        ans+=abs(v1[i]-v2[i]);
    }
    return ans;
}
int main(){
    // Output: 7
    string s="leetcode",t="coats";
    // Output: 0
    string s2="night",t2="thing";
    cout<<minSteps(s,t)<<endl;
    cout<<minSteps(s2,t2);
    return 0;
}