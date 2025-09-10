// LC - 2327 - Medium - Number of People Aware of a Secret
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top Down (Rec + Memo)
class DP{
    int Delay,Forget;
    vector<int>dp;
    const int MOD=1e9+7;
    // This returns number of people who first learn the secret on "day"
    int solve(int day){
        if(day==1) return 1;

        if(day==0) return 0;

        if(dp[day]!=-1) return dp[day];

        long long ans=0;

        // people who can share today are those who learned it in
        // [day-forget+1, day-delay]
        for(int prev=day-Forget+1;prev<=day-Delay;prev++){
            if(prev>0){
                ans=(ans+solve(prev))%MOD;
            }
        }

        return dp[day]=(int)ans;
    }
    public:
    int peopleAwareOfSecret(int n,int delay,int forget){
        Delay=delay,Forget=forget;

        int ans=0;
        dp.assign(n+1,-1);

        // only count people who haven't forgotten by day n
        for(int day=n-forget+1;day<=n;day++){
            ans=(ans+solve(day))%MOD;
        }
        return ans;
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    int M=1e9+7;
    public:
    int peopleAwareOfSecret(int n,int delay,int forget){
        vector<int>dp(n+1);

        // dp[day]=number of people who learn the secret on "day"
        dp[1]=1;

        for(int day=2;day<=n;day++){
            long long count=0;
            for(int prev=day-forget+1;prev<=day-delay; prev++){
                if(prev>0){
                    count=(count+dp[prev])%M;
                }
            }
            dp[day]=count;
        }

        int ans=0;
        for(int day=n-forget+1;day<=n;day++){
            if(day>0){
                ans=(ans+dp[day])%M;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 5
    int n=6,delay=2,forget=4;
    // Output: 6
    int n2=4,delay2=1,forget2=3;

    DP sol;
    cout<<sol.peopleAwareOfSecret(n,delay,forget)<<endl;
    cout<<sol.peopleAwareOfSecret(n2,delay2,forget2);
    return 0;
}