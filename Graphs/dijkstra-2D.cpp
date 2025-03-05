#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,pair<int,int>>P;
vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
int dijkstra(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    auto isSafe=[&](int x,int y){
        return x>=0 && y>=0 && x<m && y<n;
    };

    priority_queue<P,vector<P>,greater<P>>pq;
    vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
    ans[0][0]=grid[0][0];
    pq.push({grid[0][0],{0,0}});
    while(!pq.empty()){
        int d=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();

        if(i==m-1 && j==n-1) return ans[m-1][n-1];

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            if(isSafe(i_,j_)){
                int newCost=d+grid[i_][j_];
                if(newCost<ans[i_][j_]){
                    ans[i_][j_]=newCost;
                    pq.push({newCost,{i_,j_}});
                }
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    cout<<"Min Cost:"<<dijkstra(grid);
    return 0;
}