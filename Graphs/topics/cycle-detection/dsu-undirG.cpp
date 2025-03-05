// Cycle detection using DSU in undirected Graph
// Agar 2 nodes ka same parent h toh cycle hai
#include<iostream>
#include<vector>
using namespace std;
class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent != y_parent){
            if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
            else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
            else{
                parent[y_parent]=x_parent;
                rank[x_parent]++;
            }
        }
    }
    int detectCycle(vector<int>adj[],int V){
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                // To ensure each edge is considered once
                if(u<v){
                    int parent_u=find(u);
                    int parent_v=find(v);
                    // Agar 2 nodes ka same parent h toh cycle hai
                    if(parent_u==parent_v) return 1;
                    else Union(parent_u,parent_v);
                }
            }
        }
        return 0;
    }
};
int main(){
    int V=4;
    vector<int>adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);
    DSU dsu(V);
    if(dsu.detectCycle(adj,V)) cout<<"Cycle detected"<<endl;
    else cout<<"No cycle detected"<<endl;
    return 0;
}