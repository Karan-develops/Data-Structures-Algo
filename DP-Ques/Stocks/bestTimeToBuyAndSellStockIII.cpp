// LC - 123 - Medium - Best Time to Buy and Sell Stock III
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class DP{
    int n;
    int solve(int dp[][2][3],vector<int>&prices,bool canBuy,int count,int idx){
        if(idx>=n || count>=2) return 0;

        if(dp[idx][canBuy][count]!=-1) return dp[idx][canBuy][count];

        int profit=0;

        if(canBuy){
            int take=solve(dp,prices,false,count,idx+1)-prices[idx];
            int skip=solve(dp,prices,true,count,idx+1);

            profit=max(take,skip);
        } else{
            int sell=solve(dp,prices,true,count+1,idx+1)+prices[idx];
            int skip=solve(dp,prices,canBuy,count,idx+1);

            profit=max(sell,skip);
        }

        return dp[idx][canBuy][count]=profit;
    }
    public:
    int maxProfit(vector<int>&prices){
        n=prices.size();

        int dp[n][2][3];
        memset(dp,-1,sizeof(dp));

        return solve(dp,prices,true,0,0);
    }
};
int main(){
    // Output: 6
    vector<int>prices={3,3,5,0,0,3,1,4};
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