// LC - 3573 - Medium - Best Time to Buy and Sell Stock V
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DP{
    int n;
    typedef long long ll;
    vector<vector<vector<ll>>>dp;
    long long solve(vector<int>&prices,int state,int k,int idx){
        if(k==0) return 0;

        if(idx==n-1){ 
            // last day → force close positions
            if(state==0) return 0; 
            // must sell
            else if(state==1) return prices[idx];
            // must buy back (short cover)
            else return -prices[idx];
        }

        if(dp[idx][state][k]!=-1) return dp[idx][state][k];

        ll profit=0;

        if(state==0){
            ll buy=solve(prices,1,k,idx+1)-prices[idx];
            ll skip=solve(prices,0,k,idx+1);
            ll shortSell=solve(prices,2,k,idx+1)+prices[idx];

            profit=max({buy,skip,shortSell});
        } else if(state==1){
            ll sell=solve(prices,0,k-1,idx+1)+prices[idx];
            ll hold=solve(prices,1,k,idx+1);

            profit=max(sell,hold);
        } else{
            ll cover=solve(prices,0,k-1,idx+1)-prices[idx];
            ll hold=solve(prices,2,k,idx+1);
            
            profit=max(cover,hold);
        }

        return dp[idx][state][k]=profit;
    }
    public:
    long long maximumProfit(vector<int>&prices,int k){
        n=prices.size();

        dp.assign(n,vector<vector<ll>>(3,vector<ll>(k+1,-1)));
        
        return solve(prices,0,k,0);
    }
};
int main(){
    // Output: 14
    vector<int>prices={1,7,9,8,2};
    int k=2;
    // Output: 36
    vector<int>prices2={12,16,19,19,8,1,19,13,9};
    int k2=3;

    DP sol;
    cout<<sol.maximumProfit(prices,k)<<endl;
    cout<<sol.maximumProfit(prices2,k2);
    return 0;
}