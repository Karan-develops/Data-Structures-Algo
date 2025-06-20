// LC - 1970 - HARD - Last Day Where You Can Still Cross
// Both --> DFS - BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class BinarySearch{
    int m,n;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    bool dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1){
            return false;
        }
        if(i==m-1) return true;

        grid[i][j]=1;

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            if(dfs(grid,i_,j_)) return true;
        }
        return false;
    }
    bool bfs(vector<vector<int>>&grid,int i,int j){
        queue<pair<int,int>>q;

        q.push({i,j});
        grid[i][j]=1;

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i==m-1) return true;

            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];

                if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]==0){
                    grid[i_][j_]=1;
                    q.push({i_,j_});
                }
            }
        }
        return false;
    }
    bool canCross(vector<vector<int>>&cells,int mid){
        vector<vector<int>>grid(m,vector<int>(n,0));

        for(int i=0;i<=mid;i++){
            int x=cells[i][0];
            int y=cells[i][1];

            grid[x-1][y-1]=1;
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==0 && bfs(grid,0,j)){
                return true;
            }
        }
        return false;
    }
    public:
    int latestDayToCross(int row,int col,vector<vector<int>>&cells){
        m=row,n=col;

        int l=0;
        int r=cells.size()-1;
        int lastDay=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(canCross(cells,mid)){
                lastDay=mid+1;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return lastDay;
    }
};
int main(){
    // Output: 2
    int row=2,col=2;
    vector<vector<int>>cells={{1,1},{2,1},{1,2},{2,2}};
    // Output: 1
    int row2=2,col2=2;
    vector<vector<int>>cells2={{1,1},{1,2},{2,1},{2,2}};
    // Output: 3
    int row3=3,col3=3;
    vector<vector<int>>cells3={{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};

    BinarySearch sol;
    cout<<sol.latestDayToCross(row,col,cells)<<endl;
    cout<<sol.latestDayToCross(row2,col2,cells2)<<endl;
    cout<<sol.latestDayToCross(row3,col3,cells3);
    return 0;
}