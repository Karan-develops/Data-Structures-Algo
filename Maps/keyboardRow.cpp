// LC - 500 - Easy - Keyboard Row
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<string> findWords(vector<string>& words) {
    vector<string>ans;
    unordered_map<char,int>mp;

    string s1="qwertyuiop",s2="asdfghjkl",s3="asdfghjkl";
    for(char &ch:s1) mp[tolower(ch)]=1;
    for(char &ch:s2) mp[tolower(ch)]=2;
    for(char &ch:s3) mp[tolower(ch)]=3;

    for(string &s:words){
        int row1=mp[tolower(s[0])];
        bool flag=true;
        for(char &ch:s){
            if(mp[tolower(ch)]!=row1){
                flag=false;
                break;
            }
        }
        if(flag) ans.push_back(s);
    }
    return ans;
}
int main(){
    // Output: ["Alaska","Dad"]
    vector<string>words={"Hello","Alaska","Dad","Peace"};
    // Output: []
    vector<string>words2={"omk"};
    // Output: ["adsdf","sfd"]
    vector<string>words3={"adsdf","sfd"};
    return 0;
}