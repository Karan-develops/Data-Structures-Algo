#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void multiSourceBFS(vector<vector<int>>&adj,vector<int>&sources,int V){
    vector<int>distance(V,-1);
    queue<int>q;
    // Initialize queue with all sources and set distance = 0
    for(auto &s:sources){
        q.push(s);
        distance[s]=0;
    }
    // Simple BFS
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto &ngbr:adj[curr]){
            if(distance[ngbr]==-1){
                distance[ngbr]=distance[curr]+1;
                q.push(ngbr);
            }
        }
    }
    // Output shortest distances
    cout<<"Shortest distances from multiple sources:"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<" -> "<<distance[i]<<" distance"<<endl;
    }
}
int main(){
    int V=6;
    vector<vector<int>>adj(V);
    adj[0]={1,2};
    adj[1]={0,3};
    adj[2]={0,3,4};
    adj[3]={1,2,5};
    adj[4]={2,5};
    adj[5]={3,4};
    vector<int>sources={0,5};
    multiSourceBFS(adj,sources,V);
    return 0;
}