// LC - 714 - Medium - Best Time to Buy and Sell Stock with Transaction Fee
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    int FEE;
    vector<vector<int>>dp;
    int solve(vector<int>&prices,bool canBuy,int idx){
        if(idx>=n) return 0;

        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];

        int profit=0;

        if(canBuy){
            int take=solve(prices,false,idx+1)-prices[idx];
            int skip=solve(prices,true,idx+1);

            profit=max(take,skip);   
        } else{
            int sell=solve(prices,true,idx+1)+prices[idx]-FEE;
            int skip=solve(prices,canBuy,idx+1);

            profit=max(sell,skip);
        }

        return dp[idx][canBuy]=profit;
    }
    public:
    int maxProfit(vector<int>&prices,int fee){
        n=prices.size();
        FEE=fee;

        dp.assign(n,vector<int>(2,-1));

        return solve(prices,true,0);
    }
};
int main(){
    // Output: 8
    vector<int>prices={1,3,2,8,4,9};
    int fee=2;
    // Output: 6
    vector<int>prices2={1,3,7,5,10,3};
    int fee2=3;

    DP sol;
    cout<<sol.maxProfit(prices,fee)<<endl;
    cout<<sol.maxProfit(prices2,fee2);
    return 0;
}