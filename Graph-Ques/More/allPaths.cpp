// LC - 797 - Medium - All Paths From Source to Target
// 2 Approaches - BFS - BackTrack DFS
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef vector<int> V;
class BFS{
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        int n=graph.size();
        int src=0,dest=n-1;

        vector<V>ans;
        queue<V>q;
        V temp;

        temp.push_back(src);
        q.push(temp);

        while(!q.empty()){
            auto currPath=q.front();
            q.pop();

            int lastNode=currPath.back();

            if(lastNode==dest){
                ans.push_back(currPath);
            } else{
                for(auto &ngbr:graph[lastNode]){
                    V path=currPath;
                    path.push_back(ngbr);
                    q.push(path);
                }
            }
        }
        return ans;
    }
};
class DFS{
    int target;
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,int start,vector<int>& temp){
        if(start==target) {
            ans.push_back(temp);
            return;
        }
        for(int &x:graph[start]) {
            temp.push_back(x);
            dfs(graph,ans,x,temp);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<vector<int>>ans;
        vector<int> temp;
        target = graph.size()-1;
        temp.push_back(0);
        dfs(graph,ans,0,temp);
        
        return ans;
    }
};
int main(){
    // Output: {0,1,3},{0,2,3}}
    vector<V>graph={{1,2},{3},{3},{}};
    // Output: {0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}}
    vector<V>graph2={{4,3,1},{3,2,4},{3},{4},{}};
    DFS obj;
    vector<V> ans=obj.allPathsSourceTarget(graph2);
    for(auto &vec:ans){
        cout<<"{";
        for(int &i:vec) cout<<i<<" ";
        cout<<"}";
    }
    return 0;
}