// LC - 2257 - Medium - Count Unguarded Cells in the Grid
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Brute Force - ACCEPTED
class Matrix{
    void fillDirections(vector<vector<int>>&guardMap,int i_,int j_){
        // Top
        for(int i=i_-1;i>=0;i--){
            if(guardMap[i][j_]==3 || guardMap[i][j_]==2) break;

            guardMap[i][j_]=1;
        }
        // Down
        for(int i=i_+1;i<guardMap.size();i++){
            if(guardMap[i][j_]==3 || guardMap[i][j_]==2) break;

            guardMap[i][j_]=1;
        }
        // Left
        for(int j=j_-1;j>=0;j--){
            if(guardMap[i_][j]==3 || guardMap[i_][j]==2) break;
            
            guardMap[i_][j]=1;
        }
        // Right
        for(int j=j_+1;j<guardMap[0].size();j++){
            if(guardMap[i_][j]==3 || guardMap[i_][j]==2) break;

            guardMap[i_][j]=1;
        }
    }
    public:
    int countUnguarded(int m,int n,vector<vector<int>>&guards,vector<vector<int>>&walls){
        vector<vector<int>>guardMap(m,vector<int>(n,0));

        for(auto &guard:guards){
            int i=guard[0];
            int j=guard[1];

            guardMap[i][j]=2;
        }

        for(auto &wall:walls){
            int i=wall[0];
            int j=wall[1];

            guardMap[i][j]=3;
        }

        for(auto &guard:guards){
            int i=guard[0];
            int j=guard[1];

            fillDirections(guardMap,i,j);
        }

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(guardMap[i][j]==0) ans++;
            }
        }

        return ans;
    }
};
// Approach 2 - DFS
class DFS{
    void dfs(vector<vector<int>>&grid,int row,int col,int m,int n,int direction){
        // Boundary check and skipping guarded or walled cells
        if(row<0 || col<0 || row>=m || col>=n || grid[row][col]==1 || grid[row][col]==2){
            return;
        }

        // Mark the current cell as visited by a guard's line of sight
        grid[row][col]=3;

        // Continue the DFS in the specified direction
        if(direction==1){
            dfs(grid,row-1,col,m,n,direction);
        } else if(direction==2){
            dfs(grid,row+1,col,m,n,direction);
        } else if(direction==3){
            dfs(grid,row,col-1,m,n,direction);
        } else{
            dfs(grid,row,col+1,m,n,direction);
        }
    }
    public:
    int countUnguarded(int m,int n,vector<vector<int>>&guards,vector<vector<int>>&walls){
        vector<vector<int>>grid(m,vector<int>(n,0));

        for(const auto &guard:guards){
            int i=guard[0];
            int j=guard[1];

            grid[i][j]=1;
        }

        for(const auto &wall:walls){
            int i=wall[0];
            int j=wall[1];

            grid[i][j]=2;
        }

        for(const auto &guard:guards){
            int i=guard[0];
            int j=guard[1];

            dfs(grid,i-1,j,m,n,1); // UP
            dfs(grid,i+1,j,m,n,2); // DOWN
            dfs(grid,i,j-1,m,n,3); // LEFT
            dfs(grid,i,j+1,m,n,4); // RIGHT
        }

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans++;
                }
            }
        }

        return ans;
    }
};
int main(){
    // Output: 7
    int m=4,n=6;
    vector<vector<int>>guards={{0,0},{1,1},{2,3}},walls={{0,1},{2,2},{1,4}};
    // Output: 4
    int m2=3,n2=3;
    vector<vector<int>>guards2={{1,1}},walls2={{0,1},{1,0},{2,1},{1,2}};

    Matrix sol;
    cout<<sol.countUnguarded(m,n,guards,walls)<<endl;
    cout<<sol.countUnguarded(m2,n2,guards2,walls2);
    return 0;
}