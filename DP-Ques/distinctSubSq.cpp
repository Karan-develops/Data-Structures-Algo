// LC - 115 - HARD - Distinct Subsequences
#include<iostream>
#include<cstring>
using namespace std;
class DP{
    int dp[1001][1001];
    int solve(string &s,string &t,int m,int n){
        if(n==0) return dp[m][n]=1;
        if(m==0) return dp[m][n]=0;

        if(dp[m][n]!=-1) return dp[m][n];

        if(s[m-1]==t[n-1]){
            return dp[m][n]=solve(s,t,m-1,n)+solve(s,t,m-1,n-1);
        }
        return dp[m][n]=solve(s,t,m-1,n);
    }
    public:
    int numDistinct(string s,string t){
        int m=s.length(),n=t.length();

        memset(dp,-1,sizeof(dp));
        return solve(s,t,m,n);
    }
};
int main(){
    // Output: 3
    string s="rabbbit",t="rabbit";
    // Output: 5
    string s2="babgbag",t2="bag";

    DP sol;
    cout<<sol.numDistinct(s,t)<<endl;
    cout<<sol.numDistinct(s2,t2);
    return 0;
}