// GFG - Count the paths
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DFS{
    int dfs(unordered_map<int,vector<int>>&adj,vector<int>&dp,int src,int dest){
        if(src==dest) return 1;
        
        if(dp[src]!=-1) return dp[src];
        
        int ans=0;
        
        for(int &ngbr:adj[src]){
            ans+=dfs(adj,dp,ngbr,dest);
        }
        return dp[src]=ans;
    }
    public:
    int countPaths(vector<vector<int>>&edges,int V,int src,int dest){
        unordered_map<int,vector<int>>adj;
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
        }
        
        int ans=0;
        
        vector<int>dp(V,-1);
        return dfs(adj,dp,src,dest);
    }
};
int main(){
    // Output: 3
    vector<vector<int>>edges={{0,1},{0,3},{2,0},{2,1}, {1,3}};
    int V=4,src=2,dest=3;
    // Output: 2
    vector<vector<int>>edges2={{0,1},{1,2},{1,3},{2,3}};
    int V2=4,src2=0,dest2=3;

    DFS sol;
    cout<<sol.countPaths(edges,V,src,dest)<<endl;
    cout<<sol.countPaths(edges2,V2,src2,dest2);
    return 0;
}