// Kahn's algorithm
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>>&adj,vector<int>&ans,int V){
    queue<int>q;
    vector<int>inDegree(V,0);
    // 1. Populate the in-degree
    for(int u=0;u<V;u++){
        for(int &v:adj[u]){
            inDegree[v]++;
        }
    }
    // 2. Push nodes with nodes with 0 in-degree
    for(int i=0;i<V;i++){
        if(inDegree[i]==0) q.push(i);
    }
    // 3. Simple BFS
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        ans.push_back(curr);
        for(int &ngbr:adj[curr]){
            inDegree[ngbr]--;
            if(inDegree[ngbr]==0) q.push(ngbr);
        }
    }
}
int main(){
    int V=6;
    vector<vector<int>>adj(V);
    vector<int>ans;
    adj[0]={1,2};
    adj[1]={3};
    adj[2]={3};
    adj[3]={4};
    adj[4]={5};
    adj[5]={};
    bfs(adj,ans,V);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}