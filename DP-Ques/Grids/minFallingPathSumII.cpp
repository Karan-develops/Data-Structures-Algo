// LC - 1289 - HARD - Minimum Falling Path Sum II
// 3 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Top-Down (Rec+Memo) - TLE
// T.C : O(N^3)
// S.C : O(N^2)
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&grid,int i,int j){
        if(i==n-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;

        for(int nextCol=0;nextCol<n;nextCol++){
            if(nextCol!=j){
                ans=min(ans,solve(grid,i+1,nextCol));
            }
        }

        return dp[i][j]=grid[i][j]+ans;
    }
    public:
    int minFallingPathSum(vector<vector<int>>&grid){
        n=grid.size();
        dp.assign(n,vector<int>(n,-1));

        int ans=INT_MAX;

        for(int col=0;col<n;col++){
            ans=min(ans,solve(grid,0,col));
        }

        return ans;
    }
};
// Approach 2 - Bottom Up - ACCEPTED
// T.C : O(N^3)
// S.C : O(N^2)
class BottomUp{
    public:
    int minFallingPathSum(vector<vector<int>>&grid){
        int n=grid.size();

        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

        // Fill the last row
        for(int j=0;j<n;j++){
            dp[n-1][j]=grid[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int ans=INT_MAX;
                for(int nextCol=0;nextCol<n;nextCol++){
                    if(nextCol!=j){
                        ans=min(ans,dp[i+1][nextCol]);
                    }
                }
                dp[i][j]=grid[i][j]+ans;
            }
        }

        return *min_element(begin(dp[0]),end(dp[0]));
    }
};
// Approach 3 - Optimized BottomUp
// T.C : O(N^2)
// S.C : O(N^2)
class Optimized{
    public:
    int minFallingPathSum(vector<vector<int>>&grid){
        int n=grid.size();

        int nextMinCol1=-1;
        int nextMinCol2=-1;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

        for(int j=0;j<n;j++){
            dp[n-1][j]=grid[n-1][j];

            if(nextMinCol1==-1 || dp[n-1][j]<=dp[n-1][nextMinCol1]){
                nextMinCol2=nextMinCol1;
                nextMinCol1=j;
            } else if(nextMinCol2==-1 || dp[n-1][j]<=dp[n-1][nextMinCol2]){
                nextMinCol2=j;
            }
        }

        for(int i=n-2;i>=0;i--){
            int minCol1=-1;
            int minCol2=-1;

            for(int j=0;j<n;j++){
                if(j!=nextMinCol1){
                    dp[i][j]=grid[i][j]+dp[i+1][nextMinCol1];
                } else{
                    dp[i][j]=grid[i][j]+dp[i+1][nextMinCol2];
                }

                if(minCol1==-1 || dp[i][j]<=dp[i][minCol1]){
                    minCol2=minCol1;
                    minCol1=j;
                } else if(minCol2==-1 || dp[i][j]<=dp[i][minCol2]){
                    minCol2=j;
                }
            }
            nextMinCol1=minCol1;
            nextMinCol2=minCol2;
        }

        return dp[0][nextMinCol1];
    }
};
int main(){
    // Output: 13
    vector<vector<int>>grid={{1,2,3},{4,5,6},{7,8,9}};
    // Output: 7
    vector<vector<int>>grid2={{7}};

    BottomUp sol;
    cout<<sol.minFallingPathSum(grid)<<endl;
    cout<<sol.minFallingPathSum(grid2);
    return 0;
}