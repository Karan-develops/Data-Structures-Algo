// LC - 3373 - HARD - Maximize the Number of Target Nodes After Connecting Trees II
#include<iostream>
#include<vector>
using namespace std;
class Graph{
    vector<vector<int>> getAdj(vector<vector<int>>&edges,int n){
        vector<vector<int>>adj(n);

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(vector<vector<int>>&adj,vector<int>&mark,int &zeroMarkedCount,int &oneMarkedCount,int curr,int parent){
        if(mark[curr]==1){
            oneMarkedCount++;
        } else{
            zeroMarkedCount++;
        }

        for(auto &ngbr:adj[curr]){
            if(ngbr!=parent){
                mark[ngbr]=1-mark[curr];
                dfs(adj,mark,zeroMarkedCount,oneMarkedCount,ngbr,curr);
            }
        }
    }
    public:
    vector<int> maxTargetNodes(vector<vector<int>>&edges1,vector<vector<int>>&edges2){
        int m=edges1.size()+1;
        int n=edges2.size()+1;

        vector<vector<int>>adjA=getAdj(edges1,m);
        vector<vector<int>>adjB=getAdj(edges2,n);

        vector<int>markA(m,-1);
        markA[0]=0;
        int zeroMarkedCountA=0;
        int oneMarkedCountA=0;
        dfs(adjA,markA,zeroMarkedCountA,oneMarkedCountA,0,-1);
        
        vector<int>markB(n,-1);
        markB[0]=0;
        int zeroMarkedCountB=0;
        int oneMarkedCountB=0;
        dfs(adjB,markB,zeroMarkedCountB,oneMarkedCountB,0,-1);

        int maxEvenInTree2=max(zeroMarkedCountB,oneMarkedCountB);

        vector<int>ans(m,0);
        for(int i=0;i<m;i++){
            if(markA[i]==0){
                ans[i]=zeroMarkedCountA+maxEvenInTree2;
            } else{
                ans[i]=oneMarkedCountA+maxEvenInTree2;
            }
        }
        return ans;
    }
};
int main(){
    // Output: [8,7,7,8,8]
    vector<vector<int>>edges1={{0,1},{0,2},{2,3},{2,4}},edges2={{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    // Output: [3,6,6,6,6]
    vector<vector<int>>edges3={{0,1},{0,2},{0,3},{0,4}},edges4={{0,1},{1,2},{2,3}};

    Graph sol;
    vector<int>ans=sol.maxTargetNodes(edges1,edges2);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}