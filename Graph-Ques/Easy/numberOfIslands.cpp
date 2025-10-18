// LC - 200 - Medium - Number of Islands
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Approach 1 - DFS
class DFS{
    int m,n;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1'){
            return;
        }

        grid[i][j]='$';

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            dfs(grid,i_,j_);
        }
    }
    public:
    int numIslands(vector<vector<char>>&grid){
        m=grid.size();
        n=grid[0].size();

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// Approach 2 - BFS
class BFS{
    int m,n;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    void bfs(vector<vector<char>>&grid,int i,int j){
        queue<pair<int,int>>q;

        q.push({i,j});
        grid[i][j]='$';

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];

                if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]=='1'){
                    q.push({i_,j_});
                    grid[i_][j_]='$';
                }
            }
        }
    }
    public:
    int numIslands(vector<vector<char>>&grid){
        m=grid.size();
        n=grid[0].size();

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main(){
    // Output: 1
    vector<vector<char>>grid={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    // Output: 3
    vector<vector<char>>grid2={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

    DFS sol;
    cout<<sol.numIslands(grid)<<endl;
    cout<<sol.numIslands(grid2);
    return 0;
}