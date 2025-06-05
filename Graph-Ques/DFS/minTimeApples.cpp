// LC - 1443 - Medium - Minimum Time to Collect All Apples in a Tree
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DFS{
    int dfs(unordered_map<int,vector<int>>&adj,vector<bool>&hasApple,int curr,int parent){
        int time=0;

        for(int &ngbr:adj[curr]){
            if(ngbr!=parent){
                int timeFromChildren=dfs(adj,hasApple,ngbr,curr);

                if(timeFromChildren || hasApple[ngbr]){
                    time+=(timeFromChildren+2);
                }
            }
        }
        return time;
    }
    public:
    int minTime(int n,vector<vector<int>>&edges,vector<bool>&hasApple){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj,hasApple,0,-1);
    }
};
int main(){
    // Output: 8
    int n=7;
    vector<vector<int>>edges={{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool>hasApple={false,false,true,false,true,true,false};
    // Output: 6
    int n2=7;
    vector<vector<int>>edges2={{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool>hasApple2={false,false,true,false,false,true,false};
    // Output: 0
    int n3=7;
    vector<vector<int>>edges3={{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool>hasApple3={false,false,false,false,false,false,false};

    DFS sol;
    cout<<sol.minTime(n,edges,hasApple)<<endl;
    cout<<sol.minTime(n2,edges2,hasApple2)<<endl;
    cout<<sol.minTime(n3,edges3,hasApple3);
    return 0;
}