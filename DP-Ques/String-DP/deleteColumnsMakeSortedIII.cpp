// LC - 960 - HARD - Delete Columns to Make Sorted III
// Also in LIS
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
class DP{
    int m,n;
    int dp[101][101];
    int solve(vector<string>&strs,int j,int last){
        if(j<0) return 0;

        if(dp[j][last]!=-1) return dp[j][last];

        // Skip
        int ans=solve(strs,j-1,last);

        auto lambda=[&](const string &s){
            return s[j]<=s[last];
        };

        // Take
        bool take=(last==m) || all_of(begin(strs),end(strs),lambda);

        if(take){
            ans=max(ans,1+solve(strs,j-1,j));
        }

        return dp[j][last]=ans;
    }
    public:
    int minDeletionSize(vector<string>&strs){
        m=strs[0].size();
        n=strs.size();

        memset(dp,-1,sizeof(dp));

        return m-solve(strs,m-1,m);
    }
};
int main(){
    // Output: 3
    vector<string>strs={"babca","bbazb"};
    // Output: 4
    vector<string>strs2={"edcba"};
    // Output: 0
    vector<string>strs3={"ghi","def","abc"};

    DP sol;
    cout<<sol.minDeletionSize(strs)<<endl;
    cout<<sol.minDeletionSize(strs2)<<endl;
    cout<<sol.minDeletionSize(strs3);
    return 0;
}