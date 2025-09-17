// LC - 188 - HARD - Best Time to Buy and Sell Stock IV
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    vector<vector<vector<int>>>dp;
    int solve(vector<int>&prices,bool canBuy,int k,int idx){
        if(idx>=n || k==0) return 0;

        if(dp[idx][canBuy][k]!=-1) return dp[idx][canBuy][k];

        int profit=0;

        if(canBuy){
            int take=solve(prices,false,k,idx+1)-prices[idx];
            int skip=solve(prices,true,k,idx+1);

            profit=max(take,skip);
        } else{
            int sell=solve(prices,true,k-1,idx+1)+prices[idx];
            int skip=solve(prices,canBuy,k,idx+1);

            profit=max(sell,skip);
        }

        return dp[idx][canBuy][k]=profit;
    }
    public:
    int maxProfit(int k,vector<int>&prices){
        n=prices.size();

        dp.assign(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(prices,true,k,0);
    }
};
int main(){
    // Output: 2
    int k=2;
    vector<int>prices={2,4,1};
    // Output: 7
    int k2=2;
    vector<int>prices2={3,2,6,5,0,3};

    DP sol;
    cout<<sol.maxProfit(k,prices)<<endl;
    cout<<sol.maxProfit(k2,prices2);
    return 0;
}