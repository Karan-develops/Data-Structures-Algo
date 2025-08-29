// GFG - HARD - Smallest window containing all characters
#include<iostream>
#include<unordered_map>
using namespace std;
string smallestWindow(string &s,string &p){
    int m=s.length();
    int n=p.length();
    
    unordered_map<char,int>mp;
    for(const char &ch:p) mp[ch]++;
    
    int minLen=INT_MAX;
    int idx=-1;
    
    int count=0;
    int i=0,j=0;
    
    while(j<m){
        if(mp[s[j]]>0) count++;
        
        mp[s[j]]--;
        
        while(count==n){
            if(j-i+1<minLen){
                idx=i;
                minLen=j-i+1;
            }
            
            mp[s[i]]++;
            if(mp[s[i]]>0) count--;
            i++;
        }
        j++;
    }
    
    if(idx==-1) return "";

    return s.substr(idx,minLen);
}
int main(){
    // Output: "toprac"
    string s="timetopractice",p="toc";
    // Output: "apzo"
    string s2="zoomlazapzo",p2="oza";
    // Output: ""
    string s3="zoom",p3="zooe";
    cout<<smallestWindow(s,p)<<endl;
    cout<<smallestWindow(s2,p2)<<endl;
    cout<<smallestWindow(s3,p3);
    return 0;
}