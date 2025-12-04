// LC - 802 - Medium - Find Eventual Safe States
// GFG - Safe States
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Approach 1 - DFS
class DFS{
    bool isCyclic(vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&currRec,int i){
        visited[i]=true;
        currRec[i]=true;
        
        for(int &v:adj[i]){
            // If not visited we check for cycle in DFS
            if(visited[v]==false && isCyclic(adj,visited,currRec,v)){
                return true;
            } else if(currRec[v]) return true;
        }
        
        currRec[i]=false;
        return false;
    }
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>&graph){
        int V=graph.size();
        
        vector<bool>visited(V,false);
        vector<bool>currRec(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                isCyclic(graph,visited,currRec,i);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!currRec[i]) ans.push_back(i);
        }
        
        return ans;
    }
};
// Approach 2 - Topological Sort
class Topo{
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>&graph){
        int V=graph.size();

        vector<vector<int>>adj(V);
        vector<int>inDegree(V);

        for(int u=0;u<V;u++){
            for(int &v:graph[u]){
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int>q;

        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<bool>safe(V,false);

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            safe[curr]=true;

            for(int &ngbr:adj[curr]){
                inDegree[ngbr]--;
                if(inDegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }

        vector<int>ans;
        
        for(int i=0;i<V;i++){
            if(safe[i]) ans.push_back(i);
        }

        return ans;
    }
};
int main(){
    // Output: [2,4,5,6]
    vector<vector<int>>graph={{1,2},{2,3},{5},{0},{5},{},{}};
    // Output: [4]
    vector<vector<int>>graph2={{1,2,3,4},{1,2},{3,4},{0,4},{}};
    return 0;
}