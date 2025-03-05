// Top-Down
/*#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[101];
int solve(vector<int>&nums,int i,int n){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    // steals ith house and moves to i+2 (because we can't steal adjacent)
    int steal=nums[i]+solve(nums,i+2,n);
    //skips this house, now we can move to adjacent next house
    int skip=solve(nums,i+1,n);
    return dp[i]=max(steal,skip);
}
int main(){
    vector<int>houses={2,7,9,3,1};
    int n=houses.size();
    memset(dp,-1,sizeof(dp));
    cout<<solve(houses,0,n);
    return 0;
}*/
// Bottom-Up
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>houses={2,7,9,3,1};
    int n=houses.size();
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=houses[0];
    for(int i=2;i<=n;i++){
        int steal=houses[i-2]+dp[i];
        int skip=dp[i-1];
        dp[i]=max(steal,skip);
    }
    cout<<dp[n];
    return 0;
}*/
// Constant Space
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>houses={2,7,9,3,1};
    int n=houses.size();
    int prevPrev=0;
    int prev=houses[0];
    for(int i=2;i<=n;i++){
        int steal=houses[i-1]+prevPrev;
        int skip=prev;
        int temp=max(steal,skip);

        prevPrev=prev;
        prev=temp;
    }
    cout<<prev;
    return 0;
}