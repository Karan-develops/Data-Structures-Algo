// LC - 1971 - Find if Path Exists in Graph
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DFS{
    bool dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int src,int dest){
        if(src==dest) return true;

        if(visited[src]) return false;

        visited[src]=true;

        for(auto &ngbr:adj[src]){
            if(dfs(adj,visited,ngbr,dest)) return true;
        }
        return false;
    }
    public:
    bool validPath(int n, vector<vector<int>>&edges, int source, int destination){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        return dfs(adj,visited,source,destination);
    }
};
int main(){
    // true
    int n=3,source=0,destination=2;
    vector<vector<int>>edges={{0,1},{1,2},{2,0}};
    // false
    int n2=6,source2=0,destination2=5;
    vector<vector<int>>edges2={{0,1},{0,2},{3,5},{5,4},{4,3}};
    DFS obj;
    cout<<obj.validPath(n,edges,source,destination)<<endl;
    cout<<obj.validPath(n2,edges2,source2,destination2);
    return 0;
}