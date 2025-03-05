// Detect cycle in a undirected graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool dfs(vector<vector<int>>&adj,vector<bool>&visited,int u,int parent){
    visited[u]=true;
    for(auto &ngbr:adj[u]){
        if(ngbr==parent) continue;
        if(visited[ngbr]) return true;
        if(!visited[ngbr]) dfs(adj,visited,ngbr,u); 
    }
    return false;
}
bool bfs(vector<vector<int>>&adj,vector<bool>&visited,int u,int parent){
    cout<<"Undirected Graph with BFS:";
    queue<pair<int,int>>q;
    q.push({u,parent});
    while(!q.empty()){
        int curr=q.front().first;
        int p=q.front().second;
        q.pop();
        for(int &ngbr:adj[curr]){
            if(ngbr==p) continue;
            if(visited[ngbr]) return true;
            if(!visited[ngbr]){
                visited[ngbr]=true;
                q.push({ngbr,curr});
            }
        }
    }
    return false;
}
bool detectCycle(vector<vector<int>>&adj,int V){
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i] && bfs(adj,visited,i,-1)) return true;
    }
    return false;
}
int main(){
    int V=5;
    vector<vector<int>>adj(V);
    adj[0]={1,2};
    adj[1]={0,2,3};
    adj[2]={0,1};
    adj[3]={1};
    adj[4]={};
    if(detectCycle(adj,V)) cout<<"Has Cycle";
    else cout<<"No Cycle";
    return 0;
}