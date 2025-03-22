// LC 3203 - HARD
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class Solution{
    public:
    unordered_map<int,vector<int>> buildAdj(vector<vector<int>>&edges){
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    pair<int,int> bfs(unordered_map<int,vector<int>>&adj,int src){
        queue<int>q;
        unordered_map<int,bool>visited;
        q.push(src);
        visited[src]=true;
    
        int distance=0,farthestNode=src;
        while(!q.empty()){
            int n=q.size();
            while(n--){
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
    int findDiameter(unordered_map<int,vector<int>>&tree){
        // 1. Find the diameter from any random node
        auto [farthestNode,distance]=bfs(tree,0);
        // 2. Now we got that node now start find dia from that we will get diameter
        // the farthestNode we got above is nothing but one end of the diameter of adj
        // 3. Bfs from that node
        auto [otherEnd,diameter]=bfs(tree,farthestNode);
        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2){
        unordered_map<int,vector<int>>t1=buildAdj(edges1);
        unordered_map<int,vector<int>>t2=buildAdj(edges2);
    
        int d1=findDiameter(t1);
        int d2=findDiameter(t2);
        int combinedDiameter=(d1+1)/2+(d2+1)/2+1;
        return max({d1,d2,combinedDiameter});
    }
};
int main(){
    Solution sol;
    vector<vector<int>>edges1={{0,1},{1,2},{2,3}};
    vector<vector<int>>edges2={{0,1},{1,2},{2,3},{3,4}};

    int result=sol.minimumDiameterAfterMerge(edges1,edges2);
    cout<<"Minimum diameter after merge: "<<result;
    return 0;
}