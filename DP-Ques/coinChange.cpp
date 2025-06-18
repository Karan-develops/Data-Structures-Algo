// LC - 322 - Medium - Coin Change
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&coins,int amount,int curr){
        if(amount==0) return 0;

        if(curr>=n || amount<0) return 1e9;

        if(dp[curr][amount]!=-1) return dp[curr][amount];

        int take=1+solve(coins,amount-coins[curr],curr);
        int skip=solve(coins,amount,curr+1);
        
        return dp[curr][amount]=min(take,skip);
    }
    public:
    int coinChange(vector<int>&coins,int amount){
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));

        int ans=solve(coins,amount,0);
        return (ans>=1e9)?-1:ans;
    }
};
int main(){
    // Output: 3
    vector<int>coins={1,2,5};
    int amount=11;
    // Output: -1
    vector<int>coins2={2};
    int amount2=3;
    // Output: 0
    vector<int>coins3={1};
    int amount3=0;

    DP sol;
    cout<<sol.coinChange(coins,amount)<<endl;
    cout<<sol.coinChange(coins2,amount2)<<endl;
    cout<<sol.coinChange(coins3,amount3);
    return 0;
}