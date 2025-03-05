#include<iostream>
#include<vector>
using namespace std;
bool dfs_findPath(vector<vector<int>>&adj,vector<bool>&visited,int u,int v){
    if(u==v) return true;
    visited[u]=true;
    for(int &ngbr:adj[u]){
        if(!visited[ngbr]){
            if(dfs_findPath(adj,visited,ngbr,v)) return true;
        }
    }
    return false;
}
int main(){
    int V=5;
    vector<vector<int>>adj(V);
    adj[0]={1,2};
    adj[1]={0,3};
    adj[2]={0};
    adj[3]={1};
    vector<bool>visited(V,false);
    int u=0,v=3;
    if(dfs_findPath(adj,visited,u,v)) cout<<"There is a path from "<<u<<" to "<<v;
    else cout<<"There is no path from "<<u<<" to "<<v;
    return 0;
}