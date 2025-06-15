// LC - 2192 - Medium - All Ancestors of a Node in a Directed Acyclic Graph
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DFS{
     void dfs(unordered_map<int,vector<int>>&adj,vector<vector<int>>&ans,int ancestor,int curr){
        for(auto &ngbr:adj[curr]){
            if(ans[ngbr].empty() || ans[ngbr].back()!=ancestor){
                ans[ngbr].push_back(ancestor);
                dfs(adj,ans,ancestor,ngbr);
            }
        }
    }
    public:
    vector<vector<int>> getAncestors(int n,vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
        }

        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            int ancestor=i;
            dfs(adj,ans,ancestor,i);
        }

        return ans;
    }
};
int main(){
    // Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
    int n=8;
    vector<vector<int>>edgeList={{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    // Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
    int n2=5;
    vector<vector<int>>edgeList2={{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};

    return 0;
}