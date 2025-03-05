// Shortest Path in Weighted undirected graph
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void shortestPath(unordered_map<int,vector<pair<int,int>>>&adj,int src,int dest,int V){
    vector<int>ans(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    ans[src]=1;
    vector<int>parent(V);
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &vec:adj[node]){
            int ngbr=vec.first;
            int w=vec.second;
            if(d+w<ans[ngbr]){
                ans[ngbr]=d+w;
                pq.push({d+w,ngbr});
                parent[ngbr]=node;
            }
        }
    }
    vector<int>path;
    while(dest!=parent[dest]){
        path.push_back(dest);
        dest=parent[dest];
    }
    // **Push src before reversing
    path.push_back(src);
    reverse(path.begin(),path.end());
    for(auto &i:path){
        cout<<i<<" ";
    }
}
int main(){
    int V=5;
    unordered_map<int,vector<pair<int,int>>>adj;
    adj[0]={{1,2},{2,4}};
    adj[1]={{2,1},{3,7}};
    adj[2]={{4,3}};
    adj[3]={{4,2}};
    adj[4]={};
    int src=0;
    int dest=3;
    shortestPath(adj,src,dest,V);
    return 0;
}