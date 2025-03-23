// LC - 1976 - Medium - Number of Ways to Arrive at Destination
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

const int MOD=1e9+7;
typedef pair<long long,int>P;

int countPaths(int n, vector<vector<int>>& roads){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto &vec:roads){
        int u=vec[0];
        int v=vec[1];
        int w=vec[2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<P,vector<P>,greater<P>>pq;
    vector<long long>time(n,LLONG_MAX);
    vector<int>pathCount(n-1,0);

    pq.push({0,0});
    time[0]=0;
    pathCount[0]=1;

    while(!pq.empty()){
        long long currDist=pq.top().first;
        int currNode=pq.top().second;
        pq.pop();

        for(auto &ngbr:adj[currNode]){
            int ngbrNode=ngbr.first;
            int ngbrDist=ngbr.second;

            if(currDist+ngbrDist<time[ngbrNode]){
                time[ngbrNode]=currDist+ngbrDist;
                pq.push({currDist+ngbrDist,ngbrNode});
                pathCount[ngbrNode]=pathCount[currNode];
            }
            else if(currDist+ngbrDist==time[ngbrNode]){
                pathCount[ngbrNode]=(pathCount[currNode]+pathCount[ngbrNode])%MOD;
            }
        }
    }
    return pathCount[n-1];
}
int main(){
    // Output: 4
    int n=7;
    vector<vector<int>>roads={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    // Output: 1
    int n2=2;
    vector<vector<int>>roads2={{1,0,10}};
    cout<<countPaths(n,roads)<<endl;
    cout<<countPaths(n2,roads2);
    return 0;
}