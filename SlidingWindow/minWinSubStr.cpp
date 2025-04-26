// LC - 76 - HARD - Minimum Window Substring
#include<iostream>
#include<unordered_map>
using namespace std;
string minWindow(string s, string t) {
    if(s.length()<t.length()) return "";

    int n=s.length();
    unordered_map<char,int>mp;
    
    for(char &ch:t) mp[ch]++;

    int i=0,j=0;
    int minStart=0;
    int minEnd=INT_MAX;
    int reqCount=t.length();
    
    while(j<n){
        char ch=s[j];
        if(mp[ch]>0) reqCount--;

        mp[ch]--;

        while(reqCount==0){
            if(minEnd>j-i+1){
                minEnd=j-i+1;
                minStart=i;
            }
            mp[s[i]]++;
            if(mp[s[i]]>0) reqCount++;
            i++;
        }
        j++;
    }
    return minEnd==INT_MAX?"":s.substr(minStart,minEnd);
}
int main(){
    // Output: "BANC"
    string s="ADOBECODEBANC",t="ABC";
    // Output: "a"
    string s2="a",t2="a";
    // Output: ""
    string s3="a",t3="aa";
    cout<<minWindow(s,t)<<endl;
    cout<<minWindow(s2,t2)<<endl;
    cout<<minWindow(s3,t3);
    return 0;
}