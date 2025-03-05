#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>P;
int primsAlgo(vector<vector<P>>&adj,int V){
    priority_queue<P,vector<P>,greater<P>>pq;
    vector<bool>inMst(V,false);
    vector<int>parent(V,-1);
    pq.push({0,0}); // {weight,node}
    int totalCost=0;
    while(!pq.empty()){
        int w=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(inMst[node]==true) continue;

        inMst[node]=true;
        totalCost+=w;

        for(auto &vec:adj[node]){
            int ngbr=vec.first;
            int w_ngbr=vec.second;
            if(inMst[ngbr]==false){
                pq.push({w_ngbr,ngbr});
                parent[ngbr]=node;
            }
        }
    }
    return totalCost;
}
int main(){
    int V=5;
    vector<vector<P>>adj(V);
    vector<vector<int>>edges={{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}};
    for(auto &e:edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }
    cout<<primsAlgo(adj,V);
    return 0;
}