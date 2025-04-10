// LC - 1137 - Easy - N-th Tribonacci Number
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int solve(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    }
    public:
    int tribonacci(int n){
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
int main(){
    // Output: 4
    int n=4;
    // Output: 1389537
    int n2=25;
    Solution sol;
    cout<<sol.tribonacci(n)<<endl;
    cout<<sol.tribonacci(n2);
    return 0;
}