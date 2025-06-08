// LC - 2596 - Medium - Check Knight Tour Configuration
#include<iostream>
#include<vector>
using namespace std;
class Knight{
    int n;
    vector<vector<int>>directions{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    bool checkValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<n;
    }
    pair<int,int> findSquare(vector<vector<int>>&grid,int i,int j,int nextSpot){
        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            if(checkValid(i_,j_) && grid[i_][j_]==nextSpot) return {i_,j_};
        }
        return {-1,-1};
    }
    bool checkMove(vector<vector<int>>&grid,int currX,int currY,int nextSpot){
        if(nextSpot==n*n) return true;

        pair<int,int>nextMove=findSquare(grid,currX,currY,nextSpot);
        if(nextMove.first==-1 && nextMove.second==-1) return false;

        return checkMove(grid,nextMove.first,nextMove.second,nextSpot+1);
    }
    public:
    bool checkValidGrid(vector<vector<int>>&grid){
        n=grid.size();
        if(grid[0][0]!=0) return false;

        return checkMove(grid,0,0,1);
    }
};
int main(){
    // Output: true
    vector<vector<int>>grid={{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    // Output: false
    vector<vector<int>>grid2={{0,3,6},{5,8,1},{2,7,4}};

    Knight sol;
    cout<<sol.checkValidGrid(grid)<<endl;
    cout<<sol.checkValidGrid(grid2);
    return 0;
}