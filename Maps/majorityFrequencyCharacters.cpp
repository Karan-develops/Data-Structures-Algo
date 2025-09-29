// LC - 3692 - Easy - Majority Frequency Characters
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
string majorityFrequencyGroup(string s){
    unordered_map<char,int>mp;
    for(char &ch:s) mp[ch]++;

    unordered_map<int,vector<char>>groups;
    
    for(auto &p:mp){
        groups[p.second].push_back(p.first);
    }

    int bestSize=0;
    int bestFreq=0;
    vector<char>bestGrp;

    for(auto &p:groups){
        int k=p.first;
        auto &chars=p.second;
        int n=chars.size();

        if(n>bestSize || (n==bestSize && k>bestFreq)){
            bestSize=n;
            bestFreq=k;
            bestGrp=chars;
        }
    }

    string ans;
    for(char &ch:bestGrp) ans.push_back(ch);

    return ans;
}
int main(){
    // Output: "ab"
    string s="aaabbbccdddde";
    // Output: "abcd"
    string s2="abcd";
    // Output: "fp"
    string s3="pfpfgi";
    cout<<majorityFrequencyGroup(s)<<endl;
    cout<<majorityFrequencyGroup(s2)<<endl;
    cout<<majorityFrequencyGroup(s3);
    return 0;
}