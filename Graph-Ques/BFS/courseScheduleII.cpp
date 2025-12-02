// LC - 210 - Medium - Course Schedule II
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class BFS{
    vector<int> bfs(vector<vector<int>>&adj,vector<int>&inDegree,int V){
        vector<int>ans;
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(int &ngbr:adj[curr]){
                inDegree[ngbr]--;
                if(inDegree[ngbr]==0){
                    ans.push_back(ngbr);
                    q.push(ngbr);
                }
            }
        }
        
        if(ans.size()==V) return ans;
        
        return {};
    }
    public:
    vector<int> findOrder(int numCourses,vector<vector<int>>&prerequisites){
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);
        
        for(auto &vec:prerequisites){
            int u=vec[0];
            int v=vec[1];
            
            adj[v].push_back(u);
            inDegree[u]++;
        }
        
        return bfs(adj,inDegree,numCourses);
    }
};
int main(){
    // Output: [0,1]
    int numCourses=2;
    vector<vector<int>>prerequisites={{1,0}};
    // Output: [0,2,1,3]
    int numCourses2=4;
    vector<vector<int>>prerequisites2={{1,0},{2,0},{3,1},{3,2}};
    // Output: [0]
    int numCourses3=1;
    vector<vector<int>>prerequisites3={};
    return 0;
}