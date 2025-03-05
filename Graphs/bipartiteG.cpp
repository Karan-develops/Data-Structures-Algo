// Adjacent nodes shouldn't have same color
// If odd length cycle -> can't be bipartite
// Even length cycle -> bipartite
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool dfs(vector<vector<int>>&adj,vector<int>&color,int curr,int currColor){
    color[curr]=currColor;
    for(int &ngbr:adj[curr]){
        if(color[ngbr]==color[curr]) return false;
        if(color[ngbr]==-1){
            return dfs(adj,color,ngbr,1-currColor);
        }
    }
    return true;
}
bool bfs(vector<vector<int>>&adj,vector<int>&color,int u,int currColor){
    queue<int>q;
    q.push(u);
    color[u]=currColor;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int &ngbr:adj[curr]){
            if(color[ngbr]==color[curr]) return false;
            else if(color[ngbr]==-1){
                color[ngbr]=1-color[curr];
                q.push(ngbr);
            }
        }
    }
    return true;
}
int main(){
    int V=4;
    vector<vector<int>>adj(V);
    adj[0]={1,3};
    adj[1]={0,2};
    adj[2]={1,3};
    adj[3]={0,2};
    vector<int>color(V,-1);
    if(bfs(adj,color,0,0)) cout<<"Yes, Bipartite";
    else cout<<"Not Bipartite";
    return 0;
}