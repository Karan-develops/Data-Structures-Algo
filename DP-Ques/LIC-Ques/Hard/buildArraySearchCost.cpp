// LC - 1420 - HARD - Build Array Where You Can Find The Maximum Exactly K Comparisons
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class DP{
    int N,M,K;
    const int MOD=1e9+7;
    int dp[51][51][101];
    int solve(int idx,int searchCost,int maxSoFar){
        if(idx==N){
            if(searchCost==K) return 1;
            return 0;
        }

        if(dp[idx][searchCost][maxSoFar]!=-1){
            return dp[idx][searchCost][maxSoFar];
        }

        int ans=0;

        for(int i=1;i<=M;i++){
            if(i>maxSoFar){
                ans=(ans+solve(idx+1,searchCost+1,i))%MOD;
            } else{
                ans=(ans+solve(idx+1,searchCost,maxSoFar))%MOD;
            }
        }
        return dp[idx][searchCost][maxSoFar]=ans%MOD;
    }
    public:
    int numOfArrays(int n,int m,int k){
        N=n,M=m,K=k;

        memset(dp,-1,sizeof(dp));

        return solve(0,0,0);
    }
};
int main(){
    // Output: 6
    int n=2,m=3,k=1;
    // Output: 0
    int n2=5,m2=2,k2=3;
    // Output: 1
    int n3=9,m3=1,k3=1;

    DP sol;
    cout<<sol.numOfArrays(n,m,k)<<endl;
    cout<<sol.numOfArrays(n2,m2,k2)<<endl;
    cout<<sol.numOfArrays(n3,m3,k3);
    return 0;
}