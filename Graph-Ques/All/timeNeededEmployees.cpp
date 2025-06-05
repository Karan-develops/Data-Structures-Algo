// LC - 1376 - Medium - Time Needed to Inform All Employees
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class BFS{
    void bfs(unordered_map<int,vector<int>>&adj,vector<int>&informTime,int headID,int &ans){
        queue<pair<int,int>>q;

        q.push({headID,0});

        while(!q.empty()){
            int curr_emp=q.front().first;
            int curr_time=q.front().second;
            q.pop();

            ans=max(ans,curr_time);

            for(int &ngbr:adj[curr_emp]){
                q.push({ngbr,curr_time+informTime[curr_emp]});
            }
        }
    }
    public:
    int numOfMinutes(int n,int headID,vector<int>&manager,vector<int>&informTime){
        int ans=INT_MIN;
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<manager.size();i++){
            int manager_i=manager[i];

            if(manager_i!=-1){
                adj[manager_i].push_back(i);
            }
        }

        bfs(adj,informTime,headID,ans);
        return ans;
    }
};
class DFS{
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&informTime,int headID,int currTime,int &ans){
        ans=max(ans,currTime);

        for(auto &ngbr:adj[headID]){
            dfs(adj,informTime,ngbr,currTime+informTime[headID],ans);
        }
    }
    public:
    int numOfMinutes(int n,int headID,vector<int>&manager,vector<int>&informTime){
        int ans=INT_MIN;
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<manager.size();i++){
            int manager_i=manager[i];

            if(manager_i!=-1){
                adj[manager_i].push_back(i);
            }
        }

        dfs(adj,informTime,headID,0,ans);
        return ans;
    }
};
int main(){
    // Output: 0
    int n=1,headID=0;
    vector<int>manager={-1},informTime={0};
    // Output: 1
    int n2=6,headID2=2;
    vector<int>manager2={2,2,-1,2,2,2},informTime2={0,0,1,0,0,0};

    BFS sol;
    cout<<sol.numOfMinutes(n,headID,manager,informTime)<<endl;
    cout<<sol.numOfMinutes(n2,headID2,manager2,informTime2);
    return 0;
}