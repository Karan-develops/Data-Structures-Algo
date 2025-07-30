// LC - 3259 - Medium - Maximum Energy Boost From Two Drinks
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    typedef long long ll;
    vector<vector<ll>>dp;
    ll solve(vector<int>&A,vector<int>&B,int idx,int isA){
        if(idx>=n) return 0;

        if(dp[idx][isA]!=-1) return dp[idx][isA];

        ll takeCurrDrink=A[idx]+solve(A,B,idx+1,isA);
        ll switchDrink=solve(B,A,idx+1,1-isA);

        return dp[idx][isA]=max(takeCurrDrink,switchDrink);
    }
    public:
    long long maxEnergyBoost(vector<int>&energyDrinkA,vector<int>&energyDrinkB){
        n=energyDrinkA.size();
        
        ll ans=0;
        dp=vector<vector<ll>>(n+1,vector<ll>(2,-1));

        return max(solve(energyDrinkA,energyDrinkB,0,1),solve(energyDrinkB,energyDrinkA,0,0));
    }
};
int main(){
    // Output: 5
    vector<int>energyDrinkA={1,3,1},energyDrinkB={3,1,1};
    // Output: 7
    vector<int>energyDrinkC={4,1,1},energyDrinkD={1,1,3};

    DP sol;
    cout<<sol.maxEnergyBoost(energyDrinkA,energyDrinkB)<<endl;
    cout<<sol.maxEnergyBoost(energyDrinkC,energyDrinkD);
    return 0;
}