// LC - 309 - Medium - Best Time to Buy and Sell Stock with Cooldown
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&prices,bool canBuy,int idx){
        if(idx>=n) return 0;

        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];

        int profit=0;

        if(canBuy){
            int take=-prices[idx]+solve(prices,false,idx+1);
            int skip=solve(prices,true,idx+1);
            profit=max(take,skip);
        } else{
            int sell=prices[idx]+solve(prices,true,idx+2);
            int skip=solve(prices,canBuy,idx+1);
            profit=max(sell,skip);
        }

        return dp[idx][canBuy]=profit;
    }
    public:
    int maxProfit(vector<int>&prices){
        n=prices.size();

        dp.assign(n,vector<int>(2,-1));

        return solve(prices,true,0);
    }
};
int main(){
    // Output: 3
    vector<int>prices={1,2,3,0,2};
    // Output: 0
    vector<int>prices2={1};

    DP sol;
    cout<<sol.maxProfit(prices)<<endl;
    cout<<sol.maxProfit(prices2);
    return 0;
}