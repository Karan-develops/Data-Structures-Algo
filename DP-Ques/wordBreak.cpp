// LC - 139 - Medium - Word Break
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class DP{
    int n;
    vector<int>dp;
    unordered_set<string>st;
    bool solve(string s,int idx){
        if(idx>=n) return true;
        if(st.find(s)!=st.end()) return dp[idx]=true;

        if(dp[idx]!=-1) return dp[idx];

        for(int l=1;l<=n;l++){
            // How much lgth we need to break
            string temp=s.substr(idx,l);
            if(st.count(temp) && solve(s,idx+l)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    public:
    bool wordBreak(string s,vector<string>&wordDict){
        n=s.length();
        dp.assign(n+1,-1);

        st=unordered_set<string>(begin(wordDict),end(wordDict));

        return solve(s,0);
    }
};
int main(){
    // Output: true
    string s="leetcode";
    vector<string>wordDict={"leet","code"};
    // Output: true
    string s2="applepenapple";
    vector<string>wordDict2={"apple","pen"};
    // Output: false
    string s3="catsandog";
    vector<string>wordDict3={"cats","dog","sand","and","cat"};

    
}