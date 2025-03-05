// LC - 994
// Application of Multi-Source BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>P;
vector<vector<int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    vector<vector<int>>grid={{2,1,0},{1,1,0},{0,1,1}};
    int m=grid.size();
    int n=grid[0].size();    
    queue<P>q;
    int freshCount=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2) q.push({i,j});
            else if(grid[i][j]==1) freshCount++;
        }
    }
    if(freshCount==0) return 0;
    int time=0;
    
    auto isSafe=[&](int x,int y){
        return x>=0 && y>=0 && x<m && y<n && grid[x][y]==1;
    };

    while(!q.empty()){
        int N=q.size();
        while(N--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];
                if(isSafe(i_,j_)){
                    grid[i_][j_]=2;
                    q.push({i_,j_});
                    freshCount--;
                }
            }
        }
        time++;
    }
    if(freshCount==0) cout<<time-1;
    else cout<<-1;
    return 0;
}