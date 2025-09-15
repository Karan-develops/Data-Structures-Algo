// LC - 122 - Medium - Best Time to Buy and Sell Stock II
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&prices,bool canTake,int idx){
        if(idx>=n) return 0;

        if(dp[idx][canTake]!=-1) return dp[idx][canTake];

        int profit=0;

        if(canTake){
            int take=solve(prices,false,idx+1)-prices[idx];
            int skip=solve(prices,true,idx+1);

            profit=max(take,skip);
        } else{
            int sell=solve(prices,true,idx+1)+prices[idx];
            int skip=solve(prices,canTake,idx+1);

            profit=max(sell,skip);
        }

        return dp[idx][canTake]=profit;
    }
    public:
    int maxProfit(vector<int>&prices){
        n=prices.size();

        dp.resize(n,vector<int>(2,-1));

        return solve(prices,true,0);
    }
};
int main(){
    // Output: 7
    vector<int>prices={7,1,5,3,6,4};
    // Output: 4
    vector<int>prices2={1,2,3,4,5};
    // Output: 0
    vector<int>prices3={7,6,4,3,1};

    DP sol;
    cout<<sol.maxProfit(prices)<<endl;
    cout<<sol.maxProfit(prices2)<<endl;
    cout<<sol.maxProfit(prices3);
    return 0;
}