// Cycle detection in directed graphs
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool dfs(vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&currRec,int u){
    visited[u]=true;
    currRec[u]=true;
    for(int &ngbr:adj[u]){
        if(!visited[ngbr] && dfs(adj,visited,currRec,ngbr)) return true;
        else if(visited[ngbr] && currRec[ngbr]) return true;
    }
    currRec[u]=false;
    return false;
}
bool detectCycleByDFS(vector<vector<int>>&adj,int V){
    vector<bool>visited(V,false);
    vector<bool>currRec(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i] && dfs(adj,visited,currRec,i)) return true;
    }
    return false;
}
// Kahn's Algorithm
bool detectCycleByBFS(vector<vector<int>>&adj,int V){
    queue<int>q;
    vector<int>inDegree(V,0);
    // 1. Populate in-degree
    for(int u=0;u<V;u++){
        for(int &v:adj[u]){
            inDegree[v]++;
        }
    }
    // 2. Push nodes with 0 in-degree in queue
    for(int i=0;i<V;i++){
        if(inDegree[i]==0) q.push(i);
    }
    int count=0;
    // 3. Simple BFS
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        count++;
        for(int &ngbr:adj[curr]){
            inDegree[ngbr]--;
            if(inDegree[ngbr]==0) q.push(ngbr);
        }
    }
    return !(count==V);
}
void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
}
int main(){
    int V=5;
    vector<vector<int>>adj(V);
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    if(detectCycleByDFS(adj,V)) cout<<"Has Cycle";
    else cout<<"No Cycle";
    return 0;
}