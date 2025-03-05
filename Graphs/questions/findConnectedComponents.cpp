#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>&adj,vector<bool>&visited,int u){
    visited[u]=true;
    cout<<u<<" ";
    for(int &ngbr:adj[u]){
        if(!visited[ngbr]){
            dfs(adj,visited,ngbr);
        }
    }
}
void connectComponents(vector<vector<int>>&adj,int V){
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            cout<<"Component:";
            dfs(adj,visited,i);
            cout<<endl;
        }
    }
}
int main(){
    int V=6;
    vector<vector<int>>adj(V);
    adj[0]={1,2};
    adj[1]={0,3};
    adj[2]={0};
    adj[3]={1};
    adj[4]={5};
    adj[5]={4};
    connectComponents(adj,V);
    return 0;
}