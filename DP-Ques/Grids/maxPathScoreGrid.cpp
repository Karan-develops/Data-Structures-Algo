// LC - 3742 - Medium - Maximum Path Score in a Grid
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int m,n;
    vector<vector<vector<int>>>dp;
    vector<vector<int>>directions{{0,1},{1,0}};
    int solve(vector<vector<int>>&grid,int k,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n){
            return INT_MIN;
        }

        int cost=grid[i][j]==0?0:1;
        if(k<cost) return INT_MIN;
        k-=cost;


        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int ans=INT_MIN;

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            ans=max(ans,solve(grid,k,i_,j_));
        }

        if(ans==INT_MIN) return dp[i][j][k]=INT_MIN;

        return dp[i][j][k]=ans+grid[i][j];
    }
    public:
    int maxPathScore(vector<vector<int>>&grid,int k){
        m=grid.size();
        n=grid[0].size();

        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));

        int ans=solve(grid,k,0,0);

        return ans==INT_MIN?-1:ans;
    }
};
int main(){
    // Output: 2
    vector<vector<int>>grid={{0,1},{2,0}};
    int k=1;
    // Output: -1
    vector<vector<int>>grid2={{0,1},{1,2}};
    int k2=1;

    DP sol;
    cout<<sol.maxPathScore(grid,k)<<endl;
    cout<<sol.maxPathScore(grid2,k2);
    return 0;
}