// Optimized DSU
// DSU by Rank and Path Compression
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
        if(i==parent[i]) return i;
        // Compressing the path by telling nodes who are thier parent while coming back from recursion 
        return parent[i]=find(parent[i]);
    }
    void unite(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent!=y_parent){
            if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
            else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
            // Increasing rank if both nodes have same rank
            else{
                parent[y_parent]=x_parent;
                rank[x_parent]++;
            }
        }
    }
};
int main(){
    DSU dsu(5);
    dsu.unite(0,1);
    dsu.unite(1,2);
    dsu.unite(3,4);
    cout<<(dsu.find(0)==dsu.find(2) ? "Connected\n":"Not Connected\n");
    cout<<(dsu.find(3)==dsu.find(4) ? "Connected\n":"Not Connected\n");
    cout<<(dsu.find(0)==dsu.find(4) ? "Connected\n":"Not Connected\n");
    return 0;
}