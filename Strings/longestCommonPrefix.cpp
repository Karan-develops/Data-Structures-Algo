// LC - 14 - Easy - Longest Common Prefix
#include<iostream>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>&strs){
    int n=strs.size();
    string ans="";
    for(int i=0;i<strs[0].length();i++){
        char ch=strs[0][i];
        bool match=true;
        for(int j=1;j<n;j++){
            if(i>=strs[j].length() || ch!=strs[j][i]){
                match=false;
                break;
            }
        }
        if(!match) return ans;
        else ans.push_back(ch);
    }
    return ans;
}
int main(){
    // OP - "fl"
    vector<string>strs={"flower","flow","flight"};
    // OP - ""
    vector<string>strs2={"dog","racecar","car"};
    cout<<longestCommonPrefix(strs)<<endl;
    cout<<longestCommonPrefix(strs2);
    return 0;
}