// Kruskal’s Algorithm (Greedy + DSU)
// Sort edges by weight.
// Use Disjoint Set Union (DSU) to avoid cycles.
// Pick smallest edge if it doesn’t form a cycle.
// Stop when V - 1 edges are included.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DSU{
    vector<int>rank;
    vector<int>parent;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x != parent_y){
            if(rank[parent_x]>rank[parent_y]) parent[parent_y]=parent_x;
            else if(rank[parent_x]<rank[parent_y]) parent[parent_x]=parent_y;
            else{
                parent[parent_y]=parent_x;
                rank[parent_x]++;
            }
        }
    }
};
int kruskalMst(vector<vector<int>>&adj,int V){
    auto lambda=[&](auto &v1,auto &v2){
        return v1[2]<v2[2];
    };
    sort(adj.begin(),adj.end(),lambda);
    DSU dsu(V);
    int cost=0;
    for(auto &vec:adj){
        int u=vec[0],v=vec[1],w=vec[2];
        if(dsu.find(u)!=dsu.find(v)){
            dsu.Union(u,v);
            cost+=w;
        }
    }
    return cost;
}
int main(){
    int V=5;
    vector<vector<int>>adj={{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}};
    cout<<kruskalMst(adj,V);
    return 0;
}