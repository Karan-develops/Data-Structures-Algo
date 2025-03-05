// ** Hamiltonian Path:
// 1. A path that visits every vertex exactly once.
// 2. Does not need to return to the starting vertex.
// ** Hamiltonian Circuit
// 1. A cycle that visits every vertex exactly once and returns to the starting vertex.
#include<iostream>
#include<vector>
using namespace std;
class HamiltonianGraph{
    int V;
    vector<vector<int>>adj;
    vector<bool>visited;
    public:
    HamiltonianGraph(int V){
        this->V=V;
        adj.resize(V);
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool dfs(vector<int>&path,int u,int count){
        // All vertices visited
        if(V==count) return true;
        for(auto &ngbr:adj[u]){
            if(!visited[ngbr]){
                visited[ngbr]=true;
                path.push_back(ngbr);
                if(dfs(path,ngbr,count+1)) return true;
                // Backtrack
                path.pop_back();
                visited[ngbr]=false;
            }
        }
        return false;
    }
    void hamiltonianPath(){
        visited.assign(V,false);
        vector<int>path;
        for(int u=0;u<V;u++){
            visited[u]=true;
            path.push_back(u);
            if(dfs(path,u,1)){
                cout<<"Hamiltonian Path: ";
                for(int v:path) cout<<v<<" ";
                cout<<endl;
                return;
            }
            path.pop_back();
            visited[u]=false;
        }
        cout<<"No Hamiltonian Path Found!"<<endl;
        return;
    }
};
int main(){
    HamiltonianGraph hg(5);
    hg.addEdge(0,1);
    hg.addEdge(1,2);
    hg.addEdge(2,3);
    hg.addEdge(3,4);
    hg.addEdge(4,0);
    hg.addEdge(1,3);
    hg.hamiltonianPath();
    return 0;
}