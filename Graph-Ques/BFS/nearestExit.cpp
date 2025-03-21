// LC - 1926 - Medium - Nearest Exit from Entrance in Maze
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class BFS{
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    public:
    int nearestExit(vector<vector<char>>&maze,vector<int>&entrance){
        int m=maze.size(),n=maze[0].size();

        int level=0;
        queue<pair<int,int>>q;

        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';

        auto hasReachedLambda=[&](int i,int j){
            return (i==0 || j==0 || i==m-1 || j==m-1);
        };

        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto currNode=q.front();
                q.pop();

                if(currNode!=make_pair(entrance[0],entrance[1]) && 
                    hasReachedLambda(currNode.first,currNode.second)){
                        return level;
                }

                for(auto &dir:directions){
                    int i_=currNode.first+dir[0];
                    int j_=currNode.second+dir[1];

                    if(i_>=0 && i_<m && j_>=0 && j_<n && maze[i_][j_]!='+'){
                        q.push({i_,j_});
                        maze[i_][j_]!='+';
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
int main(){
    // OP - 1
    vector<vector<char>>maze={{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    vector<int>entrance={1,2};
    // OP - 2
    vector<vector<char>>maze2={{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    vector<int>entrance2={1,0};
    BFS obj;
    cout<<obj.nearestExit(maze,entrance)<<endl;
    cout<<obj.nearestExit(maze2,entrance2);
    return 0;
}