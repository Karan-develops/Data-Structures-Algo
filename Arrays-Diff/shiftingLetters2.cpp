// LC - 2381 - Medium - Shifting Letters II
#include<iostream>
#include<vector>
using namespace std;
string shiftingLetters(string s,vector<vector<int>>&shifts){
    int n=s.length();

    vector<int>diff(n,0);

    for(auto &vec:shifts){
        int start=vec[0];
        int end=vec[1];
        int dir=(vec[2]==0)?-1:1;

        diff[start]+=dir;
        if(end+1<n) diff[end+1]-=dir;
    }

    for(int i=1;i<n;i++){
        diff[i]+=diff[i-1];
    }

    for(int i=0;i<n;i++){
        int shift=diff[i]%26;
        if(shift<0) shift+=26;

        s[i]=(s[i]-'a'+shift)%26+'a';
    }
    return s;
}
int main(){
    // Output: "ace"
    string s="abc";
    vector<vector<int>>shifts={{0,1,0},{1,2,1},{0,2,1}};
    // Output: "catz"
    string s2="dztz";
    vector<vector<int>>shifts2={{0,0,0},{1,1,1}};
    cout<<shiftingLetters(s,shifts)<<endl;
    cout<<shiftingLetters(s2,shifts2);
    return 0;
}