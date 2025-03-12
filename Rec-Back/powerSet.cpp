#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    int N;
    vector<string>ans;
    void solve(string &s,string &output,int i){
        if(i>=N){
            if(output!=""){
                ans.push_back(output);
            }
            return;
        }
        output.push_back(s[i]);
        solve(s,output,i+1);
        
        output.pop_back();
        solve(s,output,i+1);
    }
    public:
    vector<string> powerSet(string s){
        N=s.length();
        string output="";
        solve(s,output,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    Solution sol;
    // OP - a ab abc ac b bc c
    string s1="abc";
    vector<string>ans=sol.powerSet(s1);
    for(auto &i:ans) cout<<i<<" ";
    return 0;
}