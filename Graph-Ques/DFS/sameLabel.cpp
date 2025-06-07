// LC - 1519 - Medium - Number of Nodes in the Sub-Tree With the Same Label
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DFS{
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&ans,vector<int>&count,string &labels,int curr,int parent){
        char my_label=labels[curr];
        int count_before_me=count[my_label-'a'];

        count[my_label-'a']++;

        for(auto &ngbr:adj[curr]){
            if(ngbr!=parent){
                dfs(adj,ans,count,labels,ngbr,curr);
            }
        }

        int count_after_me=count[my_label-'a'];
        ans[curr]=count_after_me-count_before_me;
    }
    public:
    vector<int> countSubTrees(int n,vector<vector<int>>&edges,string labels){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>ans(n);
        vector<int>count(26,0);

        dfs(adj,ans,count,labels,0,-1);
        return ans;
    }
};
int main(){
    // Output: [2,1,1,1,1,1,1]
    int n=7;
    vector<vector<int>>edges={{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    string labels="abaedcd";
    // Output: [4,2,1,1]
    int n2=4;
    vector<vector<int>>edges2={{0,1},{1,2},{0,3}};
    string labels2="bbbb";
    // Output: [3,2,1,1,1]
    int n3=5;
    vector<vector<int>>edges3={{0,1},{0,2},{1,3},{0,4}};
    string labels3="aabab";

    DFS sol;
    vector<int>ans=sol.countSubTrees(n,edges,labels);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}