// LC - 1743 - Medium - Restore the Array From Adjacent Pairs
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DFS{
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&ans,int curr,int prev){
        ans.push_back(curr);

        for(auto &ngbr:adj[curr]){
            if(ngbr!=prev){
                dfs(adj,ans,ngbr,curr);
            }
        }
    }
    public:
    vector<int> restoreArray(vector<vector<int>>&adjacentPairs){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:adjacentPairs){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int startingPoint=-1;
        for(auto &it:adj){
            if(it.second.size()==1){
                startingPoint=it.first;
                break;
            }
        }

        vector<int>ans;
        dfs(adj,ans,startingPoint,INT_MIN);

        return ans;
    }
};
int main(){
    // Output: [1,2,3,4]
    vector<vector<int>>adjacentPairs={{2,1},{3,4},{3,2}};
    // Output: [-2,4,1,-3]
    vector<vector<int>>adjacentPairs2={{4,-2},{1,4},{-3,1}};
    // Output: [100000,-100000]
    vector<vector<int>>adjacentPairs3={{100000,-100000}};

    DFS sol;
    vector<int>ans=sol.restoreArray(adjacentPairs);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}