// GFG - Medium - Max DAG Edges
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Topo{
    public:
    int maxEdgesToAdd(int V,vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(V,0);
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        vector<int>topo;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            topo.push_back(curr);
            
            for(int &ngbr:adj[curr]){
                inDegree[ngbr]--;
                
                if(inDegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        
        // Mark existing edges
        vector<vector<bool>>hasEdge(V,vector<bool>(V,false));
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            hasEdge[u][v]=true;
        }
        
        int ans=0;
        
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int u=topo[i];
                int v=topo[j];
                
                if(!hasEdge[u][v]) ans++;
            }
        }

        return ans;
    }
};
int main(){
    // Output: 1
    int V=3;
    vector<vector<int>>edges={{0,1},{1,2}};
    // Output: 2
    int V2=4;
    vector<vector<int>>edges2={{0,1},{0,2},{1,2},{2,3}};

    Topo sol;
    cout<<sol.maxEdgesToAdd(V,edges)<<endl;
    cout<<sol.maxEdgesToAdd(V2,edges2);
    return 0;
}