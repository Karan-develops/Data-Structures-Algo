// LC - 3693 - Medium - Climbing Stairs II
#include<iostream>
#include<vector>
using namespace std;
class DP{
    public:
    int climbStairs(int n,vector<int>&costs){
        vector<long long>dp(n+1,1e18);
        dp[0]=0;

        for(int i=1;i<=n;i++){
            for(int step=1;step<=3;step++){
                int curr=i-step;
                if(curr>=0){
                    dp[i]=min(dp[i],dp[curr]+costs[i-1]+1LL*step*step);
                }
            }
        }

        return dp[n];
    }
};
int main(){
    // Output: 13
    int n=4;
    vector<int>costs={1,2,3,4};
    // Output: 11
    int n2=4;
    vector<int>costs2={5,1,6,2};
    // Output: 12
    int n3=3;
    vector<int>costs3={9,8,3};

    DP sol;
    cout<<sol.climbStairs(n,costs)<<endl;
    cout<<sol.climbStairs(n2,costs2)<<endl;
    cout<<sol.climbStairs(n3,costs3);
    return 0;
}