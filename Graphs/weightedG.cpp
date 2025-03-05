#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<pair<int,int>>>&adj,int u,int v,int weight){
    adj[u].push_back({v,weight});
    adj[v].push_back({u,weight});
}
void printGraph(vector<vector<pair<int,int>>>&adj){
    for(int i=0;i<adj.size();i++){
        cout<<i<<":";
        for(const auto &ngbr:adj[i]){
            cout<<"("<<ngbr.first<<","<<ngbr.second<<")";
        }
        cout<<endl;
    }
}
int main(){
    int V=5;
    vector<vector<pair<int,int>>>adj(V);
    addEdge(adj,0,1,10);
    addEdge(adj,0,4,5);
    addEdge(adj,1,2,2);
    addEdge(adj,1,3,1);
    addEdge(adj,2,3,4);
    addEdge(adj,3,4,3);
    printGraph(adj);
    return 0;
}