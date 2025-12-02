// LC - 2435 - HARD - Paths in Matrix Whose Sum Is Divisible by K
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int m,n;
    const int M=1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>&grid,int k,int rem,int i,int j){
        if(i>=m || j>=n) return 0;

        if(i==m-1 && j==n-1){
            return ((rem+grid[i][j])%k==0);
        }

        if(dp[i][j][rem]!=-1) return dp[i][j][rem];

        int newRem=(rem+grid[i][j])%k;

        int down=solve(grid,k,newRem,i+1,j);
        int right=solve(grid,k,newRem,i,j+1);

        return dp[i][j][rem]=(down+right)%M;
    }
    public:
    int numberOfPaths(vector<vector<int>>&grid,int k){
        m=grid.size();
        n=grid[0].size();
        
        dp.assign(m,vector<vector<int>>(n,vector<int>(k,-1)));

        return solve(grid,k,0,0,0);
    }
};
int main(){
    // Output: 2
    vector<vector<int>>grid={{5,2,4},{3,0,5},{0,7,2}};
    int k=3;
    // Output: 1
    vector<vector<int>>grid2={{0,0}};
    int k2=5;
    // Output: 10
    vector<vector<int>>grid3={{7,3,4,9},{2,3,6,2},{2,3,7,0}};
    int k3=1;

    DP sol;
    cout<<sol.numberOfPaths(grid,k)<<endl;
    cout<<sol.numberOfPaths(grid2,k2)<<endl;
    cout<<sol.numberOfPaths(grid3,k3);
    return 0;
}