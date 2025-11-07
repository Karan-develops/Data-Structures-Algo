// LC - 3607 - Medium - Power Grid Maintenance
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;
// Approach 1 - BFS OR DFS - TLE
class BFS{
    int N;
    int solveQuery(unordered_map<int,vector<int>>&adj,vector<bool>&operational,int tower){
        queue<int>q;
        vector<bool>visited(N,false);

        q.push(tower);
        visited[tower]=true;
        int ans=INT_MAX;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            if(operational[curr]==true){
                ans=min(ans,curr+1);
            }

            for(int &ngbr:adj[curr]){
                if(!visited[ngbr]){
                    q.push(ngbr);
                    visited[ngbr]=true;
                }
            }
        }

        return ans==INT_MAX?-1:ans;
    }
    public:
    vector<int> processQueries(int c,vector<vector<int>>&connections,vector<vector<int>>&queries){
        N=c;
        unordered_map<int,vector<int>>adj;

        // 1-Based Indexing
        for(auto &vec:connections){
            int u=vec[0]-1;
            int v=vec[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>ans;
        vector<bool>operational(c,true);

        for(auto &q:queries){
            int type=q[0];
            int tower=q[1]-1;

            if(type==2){
                operational[tower]=false;
                continue;
            }

            if(type==1 && operational[tower]==true){
                ans.push_back(tower+1);
                continue;
            }

            ans.push_back(solveQuery(adj,operational,tower));
        }

        return ans;
    }
};
// Approach 2 - DSU
class DSU{
    unordered_map<int,set<int>>mp;
    void bfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<int>&componentId,int id,int i){
        queue<int>q;

        q.push(i);
        visited[i]=true;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            componentId[curr]=id;
            mp[id].insert(curr);

            for(int &ngbr:adj[curr]){
                if(!visited[ngbr]){
                    visited[ngbr]=true;
                    q.push(ngbr);
                }
            }
        }
    }
    public:
    vector<int> processQueries(int c,vector<vector<int>>&connections,vector<vector<int>>&queries){
        unordered_map<int,vector<int>>adj;

        // 1-Based Indexing
        for(auto &vec:connections){
            int u=vec[0]-1;
            int v=vec[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(c,false);
        vector<int>componentId(c);

        for(int i=0;i<c;i++){
            if(!visited[i]){
                bfs(adj,visited,componentId,i,i);
            }
        }

        vector<int>ans;

        for(auto &q:queries){
            int type=q[0];
            int tower=q[1]-1;

            if(type==1){
                int id=componentId[tower];

                if(mp[id].count(tower)){
                    ans.push_back(tower+1);
                } else if(!mp[id].empty()){
                    ans.push_back(*mp[id].begin()+1);
                } else{
                    ans.push_back(-1);
                }
            } else{
                int id=componentId[tower];
                mp[id].erase(tower);
            }
        }

        return ans;
    }
};
int main(){
    // Output: [3,2,3]
    int c=5;
    vector<vector<int>>connections={{1,2},{2,3},{3,4},{4,5}},queries={{1,3},{2,1},{1,1},{2,2},{1,2}};
    // Output: [1,-1]
    int c2=3;
    vector<vector<int>>connections2={},queries2={{1,1},{2,1},{1,1}};
    return 0;
}