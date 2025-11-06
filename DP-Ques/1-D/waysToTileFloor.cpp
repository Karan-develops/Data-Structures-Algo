// GFG - Medium - Ways To Tile A Floor
// 3 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top Down - TLE
class DP{
    vector<int>dp;
    int solve(int n){
        if(n<=1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        return solve(n-1)+solve(n-2);
    }
    public:
    int numberOfWays(int n){
        if(n<=1) return 1; 
        
        dp.resize(n+1,-1);
        
        return solve(n);
    }
};
// Approach 2 - Bottom Up - ACCEPTED
class BottomUp{
    public:
    int numberOfWays(int n){
        vector<long long>dp(n+1);
        
        dp[0]=1;
        dp[1]=1;
    
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
    
        return dp[n];
    }
};
// Approach 3 - Fibonacci
class Fibonacci{
    public:
    int numberOfWays(int n){
        if(n<=1) return 1; 
        
        int first=1;
        int second=1;
    
        for(int i=2;i<=n;i++){
            int third=first+second;
            
            first=second;
            second=third;
        }
    
        return second;
    }
};
int main(){
    // Output: 3
    int n=3;
    // Output: 5
    int n2=4;

    Fibonacci sol;
    cout<<sol.numberOfWays(n)<<endl;
    cout<<sol.numberOfWays(n2);
    return 0;
}