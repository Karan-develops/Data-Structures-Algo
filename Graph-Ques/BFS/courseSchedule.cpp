// LC - 207 - Medium - Course Schedule
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class BFS{
    bool bfs(vector<vector<int>>&adj,int V){
        queue<int>q;
        vector<int>inDegree(V,0);
        
        // 1. Populate inDegree's
        for(int u=0;u<V;u++){
            for(int &v:adj[u]) inDegree[v]++;
        }
        
        // 2. Push nodes with 0 in-degree
        for(int i=0;i<V;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        int count=0;
        // 3.Simple BFS
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            count++;
            
            for(int &ngbr:adj[curr]){
                inDegree[ngbr]--;
                if(inDegree[ngbr]==0) q.push(ngbr);
            }
        }
        
        return count==V;
    }
    public:
    bool canFinish(int numCourses,vector<vector<int>>&prerequisites){
        vector<vector<int>>adj(numCourses);
        
        for(auto &vec:prerequisites){
            int u=vec[0];
            int v=vec[1];
            
            adj[v].push_back(u);
        }
        
        return bfs(adj,numCourses);
    }
};
int main(){
    // Output: true
    int numCourses=2;
    vector<vector<int>>prerequisites={{1,0}};
    // Output: false
    int numCourses2=2;
    vector<vector<int>>prerequisites2={{1,0},{0,1}};

    BFS sol;
    cout<<sol.canFinish(numCourses,prerequisites)<<endl;
    cout<<sol.canFinish(numCourses2,prerequisites2);
    return 0;
}