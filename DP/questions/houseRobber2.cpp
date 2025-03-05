// Top-Down
/*#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[101];
int solve(vector<int>&nums,int i,int n){
    if(i>n) return 0;
    if(dp[i]!=-1) return i;
    int steal=nums[i]+solve(nums,i+2,n);
    int skip=solve(nums,i+1,n);
    return dp[i]=max(steal,skip);
}
int main(){
    vector<int>houses={1,2,3,1};
    int n=houses.size();
    if(n==1) return houses[0];
    if(n==2) return max(houses[0],houses[1]);
    memset(dp,-1,sizeof(dp));
    // Case-1 - Take first house 0th index wala house
    int take_0th_index_house=solve(houses,0,n-2);
    memset(dp,-1,sizeof(dp));
    // Case-2  - Take second house 1st index wala house
    int take_1st_index_house=solve(houses,1,n-1);
    cout<<max(take_0th_index_house,take_1st_index_house);
    return 0;
}*/
// Bottom-Up
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>houses={1,2,3,1};
    int n=houses.size();
    if(n==1) return houses[0];
    if(n==2) return max(houses[0],houses[1]);
    vector<int>dp(n+1,0);
    // Case-1 (Take from 1st House - Hence skip the last house)
    dp[0]=0;
    for(int i=1;i<=n-1;i++){
        int steal=houses[i-1]+((i-2>=0)?dp[i-2]:0);
        int skip=dp[i-1];
        dp[i]=max(steal,skip);
    }
    int ans1=dp[n-1];
    dp.clear();
    // Case-2 (Take from 2nd House - Hence take the last house)
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int steal=houses[i-1]+dp[i-2];
        int skip=dp[i-1];
        dp[i]=max(steal,skip);
    }
    int ans2=dp[n];
    cout<<max(ans1,ans2);
    return 0;
}*/
// Constant Space
#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&houses,int l,int r){
    int prev=0,prevPrev=0;
    for(int i=l;i<=r;i++){
        int steal=houses[i]+prevPrev;
        int skip=prev;
        int temp=max(steal,skip);

        prevPrev=prev;
        prev=temp;
    }
    return prev;
}
int main(){
    vector<int>houses={1,2,3,1};
    int n=houses.size();
    if(n==1) return houses[0];
    if(n==2) return max(houses[0],houses[1]);
    int take_first_house=solve(houses,0,n-2);
    int skip_first_house=solve(houses,1,n-1);
    cout<<max(take_first_house,skip_first_house);
    return 0;
}