// LC - 834 - HARD -  Sum of Distances in Tree
// Brute Force - BFS - DFS
// Optimal Approach - (2-DFS) - Compute count & Use Formula
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// This is Brute Force (O(n^2)) -> TLE
class BFS{
    public:
    vector<int> sumOfDistancesInTree(int n,vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int sum=0;
            queue<pair<int,int>>q;
            vector<bool>visited(n,false);
            q.push({i,0});
            visited[i]=true;
            
            while(!q.empty()){
                int node=q.front().first;
                int distance=q.front().second;
                q.pop();

                sum+=distance;

                for(auto &ngbr:adj[node]){
                    if(!visited[ngbr]){
                        visited[ngbr]=true;
                        q.push({ngbr,distance+1});
                    }
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};
// This is Brute Force (O(n^2)) -> TLE
class DFS{
    int dfs(unordered_map<int,vector<int>>&adj,int node,int parent,int depth){
        int sum=depth;
        for(auto &ngbr:adj[node]){
            if(ngbr!=parent){
                sum+=dfs(adj,ngbr,node,depth+1);
            }
        }
        return sum;
    }
    public:
    vector<int> sumOfDistancesInTree(int n,vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=dfs(adj,i,-1,0);
        }
        return ans;
    }
};
// This is Optimized Approach
class Optimized{
    int N;
    long root_result=0;
    vector<int>childCount;
    vector<int>ans;
    int baseDFS(unordered_map<int,vector<int>>&adj,int curr_node,int prev_node,int depth){
        int total_node=1;
        
        root_result+=depth;
        
        for(auto &child:adj[curr_node]){
            if(child==prev_node) continue;

            total_node+=baseDFS(adj,child,curr_node,depth+1);
        }

        childCount[curr_node]=total_node;
        return total_node;
    }
    void dfs(unordered_map<int,vector<int>>&adj,int parent_node,int prev_node){
        for(auto &child:adj[parent_node]){
            if(child==prev_node) continue;

            ans[child]=ans[parent_node]-childCount[child]+(N-childCount[child]);
            dfs(adj,child,parent_node);
        }
    }
    public:
    vector<int> sumOfDistancesInTree(int n,vector<vector<int>>&edges){
        N=n;
        childCount.assign(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        baseDFS(adj,0,-1,0);

        ans.assign(n,0);
        ans[0]=root_result;
        dfs(adj,0,-1);

        return ans;
    }
};
int main(){
    // Output: {8,12,6,10,10,10}
    int n=6;
    vector<vector<int>>edges={{0,1},{0,2},{2,3},{2,4},{2,5}};
    // Output: {0}
    int n2=1;
    vector<vector<int>>edges2={};
    // Output: {1,1}
    int n3=2;
    vector<vector<int>>edges3={{1,0}};
    Optimized obj;
    vector<int>ans=obj.sumOfDistancesInTree(n,edges);
    for(auto &i:ans) cout<<i<<" ";
    return 0;
}