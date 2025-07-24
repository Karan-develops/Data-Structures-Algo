// LC - 2322 - HARD - Minimum Score After Removals on a Tree
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DFS_Tree{
    int n;
    vector<int>parentVec;
    vector<int>subXor;
    void dfs(vector<vector<int>>&adj,vector<int>&nums,int parent,int curr){
        parentVec[curr]=parent;
        subXor[curr]=nums[curr];

        for(int &ngbr:adj[curr]){
            if(ngbr!=parent){
                dfs(adj,nums,curr,ngbr);
                subXor[curr]^=subXor[ngbr];
            }
        }
    }
    bool checkAncestor(int u,int v){
        while(v!=-1){
            if(u==v) return true;
            v=parentVec[v];
        }
        return false;
    }
    public:
    int minimumScore(vector<int>&nums,vector<vector<int>>&edges){
        n=nums.size();
        vector<vector<int>>adj(n);

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        parentVec.resize(n);
        subXor.resize(n);
        dfs(adj,nums,-1,0);

        // After DFS totalXor will be in subXor[0]
        int totalXor=subXor[0];
        int ans=INT_MAX;

        // Check every pair
        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){
                int a,b,c;
                if(checkAncestor(u,v)){
                    a=subXor[v];
                    b=subXor[u]^subXor[v];
                    c=totalXor^subXor[u];
                } else if(checkAncestor(v,u)){
                    a=subXor[u];
                    b=subXor[u]^subXor[v];
                    c=totalXor^subXor[v];
                } else{
                    a=subXor[u];
                    b=subXor[v];
                    c=totalXor^a^b;
                }

                int currMax=max({a,b,c});
                int currMin=min({a,b,c});
                ans=min(ans,currMax-currMin);
            }
        }
        return ans;
    }
};
int main(){
    // Output: 9
    vector<int>nums={1,5,5,4,11};
    vector<vector<int>>edges={{0,1},{1,2},{1,3},{3,4}};
    // Output: 0
    vector<int>nums2={5,5,2,4,4,2};
    vector<vector<int>>edges2={{0,1},{1,2},{5,2},{4,3},{1,3}};

    DFS_Tree sol;
    cout<<sol.minimumScore(nums,edges)<<endl;
    cout<<sol.minimumScore(nums2,edges2);
    return 0;
}