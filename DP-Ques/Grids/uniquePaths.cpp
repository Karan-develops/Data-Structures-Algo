// LC - 62 - Medium - Unique Paths
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Rec+Memo ( Top Down )
class DP{
    vector<vector<int>>dp;
    int solve(int &m,int &n,int i,int j){
        // Reached the end
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(m,n,i,j+1);
        int bottom=solve(m,n,i+1,j);

        return dp[i][j]=right+bottom;
    }
    public:
    int uniquePaths(int m,int n){
        dp.resize(m+1,vector<int>(n+1,-1));

        return solve(m,n,0,0);
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    public:
    int uniquePaths(int m,int n){
        // State Definition
        // dp[i][j] = total no. of ways to reach [i][j] from [0][0]
        vector<vector<int>>dp(m,vector<int>(n));

        dp[0][0]=1; // total ways to reach 0,0 from 0,0

        // Fill 0th row
        for(int col=1;col<n;col++){
            dp[0][col]=1;
        }

        // Fill 0th col
        for(int row=1;row<m;row++){
            dp[row][0]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
int main(){
    // Output: 28
    int m=3,n=7;
    // Output: 3
    int m2=3,n2=2;

    BottomUp sol;
    cout<<sol.uniquePaths(m,n)<<endl;
    cout<<sol.uniquePaths(m2,n2);
    return 0;
}