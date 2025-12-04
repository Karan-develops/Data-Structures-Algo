// GFG - Medium - Graph Diameter
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// Approach 1 - Brute Force - TLE
class BruteForce{
    int solve(unordered_map<int,vector<int>>&adj,int V,int i){
        queue<int>q;
        vector<bool>visited(V,false);
        
        q.push(i);
        visited[i]=true;
        
        int count=0;
        
        while(!q.empty()){
            int N=q.size();
            
            while(N--){
                int curr=q.front();
                q.pop();
                
                for(auto &ngbr:adj[curr]){
                    if(!visited[ngbr]){
                        q.push(ngbr);
                        visited[ngbr]=true;
                    }
                }
            }
            count++;
        }
        
        return count;
    }
    public:
    int diameter(int V,vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans=0;
        
        for(int i=0;i<V;i++){
            ans=max(ans,solve(adj,V,i));
        }
        
        return ans-1;
    }
};
// Approach 2 - Better
class BFS{
    pair<int,int> bfs(unordered_map<int,vector<int>>&adj,int src){
        queue<int>q;
        unordered_map<int,bool>visited;
        
        q.push(src);
        visited[src]=true;
    
        int distance=0,farthestNode=src;
        
        while(!q.empty()){
            int N=q.size();
        
            while(N--){
                int curr=q.front();
                q.pop();
                
                farthestNode=curr;
                
                for(auto &ngbr:adj[curr]){
                    if(!visited[ngbr]){
                        visited[ngbr]=true;
                        q.push(ngbr);
                    }
                }
            }
            
            if(!q.empty()) distance++;
        }
        return {farthestNode,distance};
    }
    int findDiameter(unordered_map<int,vector<int>>&adj){
        // 1. Find the diameter from any random node
        auto [farthestNode,distance]=bfs(adj,0);
        // 2. Now we got that node now start find dia from that we will get diameter
        // the farthestNode we got above is nothing but one end of the diameter of adj
        // 3. Bfs from that node
        auto [otherEnd,diameter]=bfs(adj,farthestNode);
        return diameter;
    }
    public:
    int diameter(int V,vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return findDiameter(adj);
    }
};
int main(){
    // Output: 4
    int V=6;
    vector<vector<int>>edges={{0,1},{0,4},{1,3},{1,2},{2,5}};
    // Output: 4
    int V2=7;
    vector<vector<int>>edges2={{0,2},{0,4},{0,3},{3,1},{3,5},{1,6}};

    BFS sol;
    cout<<sol.diameter(V,edges)<<endl;
    cout<<sol.diameter(V2,edges2);
    return 0;
}