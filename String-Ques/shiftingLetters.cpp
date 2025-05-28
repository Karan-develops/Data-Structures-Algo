// LC - 848 - Medium - Shifting Letters
#include<iostream>
#include<vector>
using namespace std;
string shiftingLetters(string s,vector<int>&shifts){
    int n=s.length();

    for(int i=n-2;i>=0;i--){
        shifts[i]=(shifts[i]+shifts[i+1])%26;
    }

    for(int i=0;i<n;i++){
        s[i]=(s[i]-'a'+shifts[i])%26+'a';
    }
    return s;
}
int main(){
    // Output: "rpl"
    string s="abc";
    vector<int>shifts={3,5,9};
    // Output: "gfd"
    string s2="aaa";
    vector<int>shifts2={1,2,3};
    cout<<shiftingLetters(s,shifts)<<endl;
    cout<<shiftingLetters(s2,shifts2);
    return 0;
}