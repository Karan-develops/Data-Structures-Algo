// GFG - Rat in a Maze
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int n;
    vector<vector<int>>directions{{1,0},{0,-1},{0,1},{-1,0}};
    char getPath(int i,int j){
        if(i==1) return 'D';
        if(i==-1) return 'U';
        if(j==-1) return 'L';
        return 'R';
    }
    void solve(vector<vector<int>>&maze,vector<string>&ans,string temp,int i,int j){
        if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0){
            return;
        }
        
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        maze[i][j]=0;
        
        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            
            char path=getPath(dir[0],dir[1]);
            
            temp.push_back(path);
            solve(maze,ans,temp,i_,j_);
            temp.pop_back();
        }
        maze[i][j]=1;
    }
    public:
    vector<string> ratInMaze(vector<vector<int>>&maze){
        n=maze.size();
        
        vector<string>ans;
        string temp;
        
        solve(maze,ans,temp,0,0);
        
        return ans;
    }
};
int main(){
    // Output: ["DDRDRR", "DRDDRR"]
    vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    // Output: []
    vector<vector<int>>maze2={{1,0},{1,0}};
    // Output: ["DDRR", "RRDD"]
    vector<vector<int>>maze3={{1,1,1},{1,0,1},{1,1,1}};
    return 0;
}