// LC - 17 - Medium -  Letter Combinations of a Phone Number
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    int n;
    vector<string>ans;
    void solve(string &digits,unordered_map<char,string>mp,string &temp,int idx){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        char digit=digits[idx];
        string str=mp[digit];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);

            solve(digits,mp,temp,idx+1);

            temp.pop_back();
        }
    }
    public:
    vector<string> letterCombinations(string digits){
        if(digits.size()==0) return {};
        n=digits.size();
        ans.clear();
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        solve(digits,mp,temp,0);
        return ans;
    }
};
int main(){
    // OP - ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    string digits1="23";
    // OP - ["a","b","c"]
    string digits2="2";
    Solution sol;
    vector<string>ans1=sol.letterCombinations(digits1);
    vector<string>ans2=sol.letterCombinations(digits2);
    cout<<"[";
    for(auto &str:ans1){
        for(char &ch:str) cout<<ch;
        cout<<",";
    }
    cout<<"]"<<endl;
    cout<<"[";
    for(auto &str:ans2){
        for(char &ch:str) cout<<ch;
        cout<<",";
    }
    cout<<"]";
    return 0;
}