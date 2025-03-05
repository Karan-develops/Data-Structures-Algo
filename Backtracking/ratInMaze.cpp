#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int> >&maze,vector<vector<bool> >visited,int row,int col,int i,int j){
    // 3 cases to check
    if(((i<row && i>=0) && (j<col && j>=0)) && (visited[i][j]==false) && (maze[i][j]==true)){
        return true;
    } else {
        return false;
    }
}
void solveMaze(vector<vector<int> >&maze,vector<vector<bool> >&visited,int row,int col,int srcx,int srcy,vector<string>&path,string output){
    // Base Case -> when the rat reaches the destination
    if(srcx==row-1 && srcy==col-1){
        path.push_back(output);
        return;
    }
    // Down Move -> (i+1)(j)
    if(isSafe(maze,visited,row,col,srcx+1,srcy)){
        visited[srcx+1][srcy]=true;
        solveMaze(maze,visited,row,col,srcx+1,srcy,path,output+'D');
        // Backtracking -> Unmark the visited to explore all paths
        visited[srcx+1][srcy]=false;
    }
    // Left Move -> (i)(j-1)
    if(isSafe(maze,visited,row,col,srcx,srcy-1)){
        visited[srcx][srcy-1]=true;
        solveMaze(maze,visited,row,col,srcx,srcy-1,path,output+'L');
        // Backtracking -> Unmark the visited to explore all paths
        visited[srcx][srcy-1]=false;
    }
    // Right Move -> (i)(j+1)
    if(isSafe(maze,visited,row,col,srcx,srcy+1)){
        visited[srcx][srcy+1]=true;
        solveMaze(maze,visited,row,col,srcx,srcy+1,path,output+'R');
        // Backtracking -> Unmark the visited to explore all paths
        visited[srcx][srcy+1]=false;
    }
    // Up Move -> (i-1)(j)
    if(isSafe(maze,visited,row,col,srcx-1,srcy)){
        visited[srcx-1][srcy]=true;
        solveMaze(maze,visited,row,col,srcx-1,srcy,path,output+'U');
        // Backtracking -> Unmark the visited to explore all paths
        visited[srcx-1][srcy]=false;
    }
}
int main(){
    vector<vector<int> >maze{{1,0,0},{1,1,0},{1,1,1}};
    if(maze[0][0]==0){
        cout<<"The source is blocked, So Path doesn't exists";
        return 0;
    }
    int row=maze.size();
    int col=maze[0].size();
    if(maze[row-1][col-1]==0){
        cout<<"The Destination is blocked, So Path doesn't exists";
        return 0;
    }
    vector<vector<bool> >visited(row,vector<bool>(col,false));
    visited[0][0]=true;
    vector<string>path;
    string output="";
    solveMaze(maze,visited,row,col,0,0,path,output);
    if(path.size()==0){
        cout<<"No Path exists!";
        return 0;
    }
    for(auto i:path){
        cout<<i<<endl;
    }
    return 0;
}