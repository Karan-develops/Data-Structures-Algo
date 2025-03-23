// LC - 886 - Possible Bipartition
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
bool bipartite(unordered_map<int,vector<int>>&adj,vector<int>&colors,int i){
    queue<int>q;
    q.push(i);
    colors[i]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto &ngbr:adj[node]){
            if(colors[node]==colors[ngbr]) return false;
            if(colors[ngbr]==-1){
                colors[ngbr]=1-colors[node];
                q.push(ngbr);
            }
        }
    }
    return true;
}
bool possibleBipartition(int n, vector<vector<int>>& dislikes){
    unordered_map<int,vector<int>>adj;
    for(auto &vec:dislikes){
        int u=vec[0];
        int v=vec[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>colors(n+1,-1);

    for(int i=1;i<=n;i++){
        if(colors[i]==-1){
            if(!bipartite(adj,colors,i)) return false;
        }
    }
    return true;
}
int main(){
    // Output: true
    int n=4;
    vector<vector<int>>dislikes={{1,2},{1,3},{2,4}};
    // Output: false
    int n2=3;
    vector<vector<int>>dislikes2={{1,2},{1,3},{2,3}};
    cout<<possibleBipartition(n,dislikes)<<endl;
    cout<<possibleBipartition(n2,dislikes2);
    return 0;
}