// LC - 980 - HARD - Unique Paths III
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int m,n;
    int emptyCells;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};

    void solve(vector<vector<int>>&grid,int &ans,int i,int j,int currCount){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
            return;
        }

        if(grid[i][j]==2){
            if(emptyCells==currCount){
                ans++;
            }
            return;
        }

        grid[i][j]=-1;

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            solve(grid,ans,i_,j_,currCount+1);
        }

        grid[i][j]=0;
    }
    public:
    int uniquePathsIII(vector<vector<int>>&grid){
        m=grid.size(),n=grid[0].size();
        int ans=0;

        int start_x=0;
        int start_y=0;
        emptyCells=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }
                if(grid[i][j]==0) emptyCells++;
            }
        }

        // Walk over every non-obstacle square exactly once.
        emptyCells+=1;

        solve(grid,ans,start_x,start_y,0);
        return ans;
    }
};
int main(){
    // Output: 2
    vector<vector<int>>grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    // Output: 4
    vector<vector<int>>grid2={{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    // Output: 0
    vector<vector<int>>grid3={{0,1},{2,0}};

    BackTracking sol;
    cout<<sol.uniquePathsIII(grid)<<endl;
    cout<<sol.uniquePathsIII(grid2)<<endl;
    cout<<sol.uniquePathsIII(grid3);
    return 0;
}