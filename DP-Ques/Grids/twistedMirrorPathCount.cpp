// LC - 3665 - Medium - Twisted Mirror Path Count
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class DP{
    int m,n;
    const int M=1e9+7;
    long long dp[501][501][3];
    long long solve(vector<vector<int>>&grid,int dir,int i,int j){
        if(i==m-1 && j==n-1) return 1LL;

        if(i>=m || j>=n) return 0LL;

        if(dp[i][j][dir]!=-1) return dp[i][j][dir];

        // Enters a mirror
        if(grid[i][j]==1){
            // Came from right, go to down
            if(dir==0){
                return dp[i][j][dir]=solve(grid,1,i+1,j)%M;
            } else{ // Came from down, go to ryt
                return dp[i][j][dir]=solve(grid,0,i,j+1)%M;
            }
        }
        
        // If normal cell move right or down
        long long right=solve(grid,0,i,j+1)%M;
        long long down=solve(grid,1,i+1,j)%M;

        return dp[i][j][dir]=(right+down)%M;
    }
    public:
    int uniquePaths(vector<vector<int>>&grid){
        m=grid.size();
        n=grid[0].size();

        memset(dp,-1,sizeof(dp));

        return solve(grid,2,0,0)%M;
    }
};
int main(){
    // Output: 5
    vector<vector<int>>grid={{0,1,0},{0,0,1},{1,0,0}};
    // Output: 2
    vector<vector<int>>grid2={{0,0},{0,0}};
    // Output: 1
    vector<vector<int>>grid3={{0,1,1},{1,1,0}};

    DP sol;
    cout<<sol.uniquePaths(grid)<<endl;
    cout<<sol.uniquePaths(grid2)<<endl;
    cout<<sol.uniquePaths(grid3);
    return 0;
}