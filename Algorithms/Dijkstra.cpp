// Using min-heap(priority queue)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dijkstra(vector<vector<pair<int,int>>>&adj,int V,int src){
    vector<int>ans(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    ans[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int currD=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &vec:adj[node]){
            int ngbr=vec.first;
            int w=vec.second;
            if(currD+w<ans[ngbr]){
                ans[ngbr]=currD+w;
                pq.push({currD+w,ngbr});
            }
        }
    }
    cout<<"Shortest distances from source "<<src<<endl;
    for(int i=0;i<V;i++){
        cout<<"To "<<i<<"->"<<(ans[i]==INT_MAX?-1:ans[i])<<endl;
    }
}
int main(){
    int V=5;
    vector<vector<pair<int,int>>>adj(V);
    adj[0]={{1,2},{2,4}};
    adj[1]={{2,1},{3,7}};
    adj[2]={{4,3}};
    adj[3]={{4,2}};
    adj[4]={};
    int src=0;
    dijkstra(adj,V,src);
    return 0;
}