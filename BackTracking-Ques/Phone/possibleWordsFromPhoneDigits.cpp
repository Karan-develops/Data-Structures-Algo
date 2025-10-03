// GFG - Possible Words From Phone Digits
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class BackTracking{
    void solve(vector<int>&arr,vector<string>&ans,unordered_map<int,string>&mp,string temp,int idx){
        if(idx>=arr.size()){
            ans.push_back(temp);
            return;
        }

        if(arr[idx]==0 || arr[idx]==1){
            solve(arr,ans,mp,temp,idx+1);
        }

        int digit=arr[idx];
        string str=mp[digit];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(arr,ans,mp,temp,idx+1);
            temp.pop_back();
        }
    }
    public:
    vector<string> possibleWords(vector<int>&arr){
        unordered_map<int,string>mp;
        vector<string>ans;
        string temp;
        
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        solve(arr,ans,mp,temp,0);

        return ans;
    }
};
int main(){
    // Output: [ad, ae, af, bd, be, bf, cd, ce, cf]
    vector<int>arr={2,3};
    // Output: [a, b, c]
    vector<int>arr2={2};
    return 0;
}