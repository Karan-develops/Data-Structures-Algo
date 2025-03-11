#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int row,col;
    bool isSafe(int i,int j){
        return i>=0 && i<row && j>=0 && j<col;
    }
    void solve(vector<vector<int>>&maze,vector<string>&ans,string &output,int i,int j){
        if(i==row-1 && j==col-1){
            ans.push_back(output);
            return;
        }
        if(!isSafe(i,j) || maze[i][j]==0) return;

        // Mark Visited ( visited vector alag se bhi le skte h but maze bhi kaam kr degi)
        maze[i][j]=0;
        
        // UP
        output.push_back('U');
        solve(maze,ans,output,i-1,j);
        output.pop_back();
        // DOWN
        output.push_back('D');
        solve(maze,ans,output,i+1,j);
        output.pop_back();
        // LEFT
        output.push_back('L');
        solve(maze,ans,output,i,j-1);
        output.pop_back();
        // RIGHT
        output.push_back('R');
        solve(maze,ans,output,i,j+1);
        output.pop_back();

        // BackTrack (Unmark the cell) - Unvisited
        maze[i][j]=1;
    }
    public:
    Solution(int row,int col){
        this->row=row;
        this->col=col;
    }
    vector<string> ratInMaze(vector<vector<int>>&maze){
        vector<string>ans;
        string output;
        solve(maze,ans,output,0,0);
        return ans;
    }
};
int main(){
    vector<vector<int>>maze={{1,0,0},{1,1,0},{1,1,1}};
    Solution sol(maze.size(),maze[0].size());
    vector<string>ans=sol.ratInMaze(maze);
    for(auto &i:ans){
        cout<<"[";
        cout<<i;
        cout<<"]";
    }
    return 0;
}