// Dijkstra’s algorithm fails when a graph contains negative weight edges.
// Bellman-Ford is used to find the shortest path from a single source, even when negative weights exist.
#include<iostream>
#include<vector>
using namespace std;
void bellmanFord(vector<vector<int>>&edges,int V,int src){
    vector<int>ans(V,INT_MAX);
    ans[src]=0;
    for(int i=1;i<=V-1;i++){
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int d=edge[2];
            if(ans[u]!=INT_MAX && ans[v]>ans[u]+d){
                ans[v]=ans[u]+d;
            }
        }
    }
    // Check for negative weight cycles
    for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        int d=edge[2];
        if(ans[u]!=INT_MAX && ans[v]>ans[u]+d){
            cout<<"Negative Cycle"<<endl;
            return;
        }
    }
    cout<<"Shortest distances from source "<<src<<endl;
    for(int i=0;i<V;i++){
        cout<<"To "<<i<<" -> "<<(ans[i]==INT_MAX?-1:ans[i])<<endl;
    }
}
int main(){
    int V=5,E=8;
     vector<vector<int>> edges = {{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
    int src=0;
    bellmanFord(edges,V,src);
    return 0;
}