// GFG - Medium - Get Minimum Squares
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top Down (Rec+Memo)
class DP{
    vector<int>dp;
    int solve(int n){
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int ans=INT_MAX;
        
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i));
        }
        
        return dp[n]=ans;
    }
    public:
    int minSquares(int n){
        dp.resize(n+1,-1);
        
        return solve(n);
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    public:
    int minSquares(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
int main(){
    // Output: 1
    int n=100;
    // Output: 3
    int n2=6;

    DP sol;
    cout<<sol.minSquares(n)<<endl;
    cout<<sol.minSquares(n2);
    return 0;
}