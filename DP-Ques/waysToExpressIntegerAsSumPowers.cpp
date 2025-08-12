// LC - 2787 - Medium - Ways to Express an Integer as Sum of Powers
#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;
class DP{
    int M=1e9+7;
    int dp[301][301];
    int solve(int n,int x,int num){
        // Found One way
        if(n==0) return 1;

        if(n<0) return 0;

        int currPowerVal=pow(num,x);
        if(currPowerVal>n) return 0;

        if(dp[n][num]!=-1) return dp[n][num];

        int take=solve(n-currPowerVal,x,num+1);
        int skip=solve(n,x,num+1);

        return dp[n][num]=(take+skip)%M;
    }
    public:
    int numberOfWays(int n,int x){
        memset(dp,-1,sizeof(dp));

        return solve(n,x,1);
    }
};
int main(){
    // Output: 1
    int n=10,x=2;
    // Output: 2
    int n2=4,x2=1;

    DP sol;
    cout<<sol.numberOfWays(n,x)<<endl;
    cout<<sol.numberOfWays(n2,x2);
    return 0;
}