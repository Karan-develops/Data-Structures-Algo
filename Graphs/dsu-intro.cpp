// DSU (Disjoint Set Union) OR (Union Find)
#include<iostream>
#include<vector>
using namespace std;
class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            // Initially, each node is its own parent
            parent[i]=i;
        }
    }
    int find(int i){
        if(i==parent[i]) return i;
        return find(parent[i]);
    }
    void unite(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x!=parent_y){
            parent[parent_x]=parent_y;
        }
    }
};
int main(){
    DSU dsu(5);
    dsu.unite(0,1);
    dsu.unite(1,2);
    cout<<(dsu.find(0)==dsu.find(2) ? "Connected\n":"Not Connected\n");
    cout<<(dsu.find(3)==dsu.find(4) ? "Connected\n":"Not Connected\n");
    return 0;
}