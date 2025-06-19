// LC - 518 - Medium - Coin Change II
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&coins,int amount,int curr){
        if(amount==0) return dp[curr][amount]=1;
        
        if(curr>=n || amount<0) return dp[curr][amount]=0;
        
        if(dp[curr][amount]!=-1) return dp[curr][amount];
        
        if(coins[curr]>amount) return solve(coins,amount,curr+1);
        
        int take=solve(coins,amount-coins[curr],curr);
        int skip=solve(coins,amount,curr+1);
        
        return dp[curr][amount]=take+skip;
    }
    public:
    int change(int amount,vector<int>&coins){
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        
        return solve(coins,amount,0);
    }
};
int main(){
    // Output: 4
    int amount=5;
    vector<int>coins={1,2,5};
    // Output: 0
    int amount2=3;
    vector<int>coins2={2};
    // Output: 1
    int amount3=10;
    vector<int>coins3={10};

    DP sol;
    cout<<sol.change(amount,coins);
    cout<<sol.change(amount2,coins2)<<endl;
    cout<<sol.change(amount3,coins3);
    return 0;
}