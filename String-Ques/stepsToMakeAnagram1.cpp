// LC - 1347 - Medium - Minimum Number of Steps to Make Two Strings Anagram
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
    return ans/2;
}
int main(){
    // Output: 1
    string s="bab",t="aba";
    // Output: 5
    string s2="leetcode",t2="practice";
    // Output: 0
    string s3="anagram",t3="mangaar";
    cout<<minSteps(s,t)<<endl;
    cout<<minSteps(s2,t2)<<endl;
    cout<<minSteps(s3,t3);
    return 0;
}