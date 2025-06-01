// LC - 3372 - Medium - Maximize the Number of Target Nodes After Connecting Trees I
// Good Question
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class BFS{
    int bfs(unordered_map<int,vector<int>>&adj,int k,int N,int curr){
        vector<bool>visited(N,false);
        queue<pair<int,int>>q;

        q.push({curr,0});
        visited[curr]=true;
        int count=0;

        while(!q.empty()){
            int node=q.front().first;
            int distance=q.front().second;
            q.pop();

            if(distance>k) continue;
            count++;

            for(auto &ngbr:adj[node]){
                if(!visited[ngbr]){
                    visited[ngbr]=true;
                    q.push({ngbr,distance+1});
                }
            }
        }
        return count;
    }
    vector<int> findCount(vector<vector<int>>&edges,int k){
        int N=edges.size()+1;
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>ans(N);
        for(int i=0;i<N;i++){
            ans[i]=bfs(adj,k,N,i);
        }
        return ans;
    }
    public:
    vector<int> maxTargetNodes(vector<vector<int>>&edges1,vector<vector<int>>&edges2,int k){
        vector<int>ans1=findCount(edges1,k);
        vector<int>ans2=findCount(edges2,k-1);

        int maxTargetNodesCount=*max_element(begin(ans2),end(ans2));

        for(int i=0;i<ans1.size();i++){
            ans1[i]+=maxTargetNodesCount;
        }
        return ans1;
    }
};
class DFS{
    int dfs(unordered_map<int,vector<int>>&adj,int k,int curr,int currKaParent){
        if(k<0) return 0;

        int count=1;

        for(auto &ngbr:adj[curr]){
            if(ngbr!=currKaParent){
                count+=dfs(adj,k-1,ngbr,curr);
            }
        }
        return count;
    }
    vector<int> findCount(vector<vector<int>>&edges,int k){
        int N=edges.size()+1;
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>ans(N);
        for(int i=0;i<N;i++){
            ans[i]=dfs(adj,k,i,-1);
        }
        return ans;
    }
    public:
    vector<int> maxTargetNodes(vector<vector<int>>&edges1,vector<vector<int>>&edges2,int k){
        vector<int>ans1=findCount(edges1,k);
        vector<int>ans2=findCount(edges2,k-1);

        int maxTargetNodesCount=*max_element(begin(ans2),end(ans2));

        for(int i=0;i<ans1.size();i++){
            ans1[i]+=maxTargetNodesCount;
        }
        return ans1;
    }
};
int main(){
    // Output: [9,7,9,8,8]
    vector<vector<int>>edges1={{0,1},{0,2},{2,3},{2,4}},edges2={{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k=2;
    // Output: [6,3,3,3,3]
    vector<vector<int>>edges3={{0,1},{0,2},{0,3},{0,4}},edges4={{0,1},{1,2},{2,3}};
    int k2=1;

    DFS sol;
    vector<int>ans=sol.maxTargetNodes(edges1,edges2,k);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}