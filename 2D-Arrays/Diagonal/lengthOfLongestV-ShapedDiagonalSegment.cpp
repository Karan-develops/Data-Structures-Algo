// LC - 3459 - HARD - Length of Longest V-Shaped Diagonal Segment
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Diagonal{
    int m,n;
    int dp[501][501][4][2];
    vector<vector<int>>directions{{1,1},{1,-1},{-1,-1},{-1,1}};
    bool isSafe(int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int solve(vector<vector<int>>&grid,int d,bool canTurn,int nextNum,int i,int j){
        int i_=i+directions[d][0];
        int j_=j+directions[d][1];

        if(!isSafe(i_,j_) || grid[i_][j_]!=nextNum){
            return 0;
        }

        if(dp[i_][j_][d][canTurn]!=-1) return dp[i_][j_][d][canTurn];

        int ans=0;

        // nextNum^2 OR nextNum==2?0:2
        int keepMoving=1+solve(grid,d,canTurn,nextNum^2,i_,j_);
        ans=max(ans,keepMoving);

        if(canTurn){
            // Turn 90° --> (d+1)%4
            int turn=1+solve(grid,(d+1)%4,false,nextNum^2,i_,j_);
            ans=max(ans,turn);
        }

        return dp[i_][j_][d][canTurn]=ans;
    }
    public:
    int lenOfVDiagonal(vector<vector<int>>&grid){
        m=grid.size();
        n=grid[0].size();

        int ans=0;
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int d=0;d<4;d++){
                        ans=max(ans,1+solve(grid,d,true,2,i,j));
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    // Output: 5
    vector<vector<int>>grid={{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    // Output: 4
    vector<vector<int>>grid2={{2,2,2,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    // Output: 5
    vector<vector<int>>grid3={{1,2,2,2,2},{2,2,2,2,0},{2,0,0,0,0},{0,0,2,2,2},{2,0,0,2,0}};
    // Output: 1
    vector<vector<int>>grid4={{1}};

    Diagonal sol;
    cout<<sol.lenOfVDiagonal(grid)<<endl;
    cout<<sol.lenOfVDiagonal(grid2)<<endl;
    cout<<sol.lenOfVDiagonal(grid3)<<endl;
    cout<<sol.lenOfVDiagonal(grid4);
    return 0;
}