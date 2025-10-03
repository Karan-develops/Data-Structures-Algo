// LC - 17 - Medium - Letter Combinations of a Phone Number
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class BackTracking{
    void solve(string &digits,vector<string>&ans,unordered_map<char,string>&mp,string &temp,int idx){
        if(idx>=digits.length()){
            ans.push_back(temp);
            return;
        }
        
        char digit=digits[idx];
        string str=mp[digit];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(digits,ans,mp,temp,idx+1);
            temp.pop_back();
        }
    }
    public:
     vector<string> letterCombinations(string digits){
        if(digits.length()==0) return {};
        
        unordered_map<char,string>mp;
        vector<string>ans;
        string temp;
        
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        solve(digits,ans,mp,temp,0);

        return ans;
    }
};
int main(){
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    string digits="23";
    // Output: []
    string digits2="";
    // Output: ["a","b","c"]
    string digits3="2";
    return 0;
}