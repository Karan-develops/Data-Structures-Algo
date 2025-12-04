// LC - 2872 - HARD - Maximum Number of K-Divisible Components
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DFS{
    int ans=0;
    int dfs(unordered_map<int,vector<int>>&adj,vector<int>&values,int k,int parent,int curr){
        int sum=0;

        for(auto &ngbr:adj[curr]){
            if(ngbr!=parent){
                sum+=dfs(adj,values,k,curr,ngbr);
                sum%=k;
            }
        }

        sum+=values[curr];
        sum%=k;

        if(sum==0) ans++;

        return sum;
    }
    public:
    int maxKDivisibleComponents(int n,vector<vector<int>>&edges,vector<int>&values,int k){
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans=0;
        dfs(adj,values,k,-1,0);

        return ans;
    }
};
int main(){
    // Output: 2
    int n=5,k=6;
    vector<vector<int>>edges={{0,2},{1,2},{1,3},{2,4}};
    vector<int>values={1,8,1,4,4};
    // Output: 3
    int n2=7,k2=3;
    vector<vector<int>>edges2={{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    vector<int>values2={3,0,6,1,5,2,1};

    DFS sol;
    cout<<sol.maxKDivisibleComponents(n,edges,values,k)<<endl;
    cout<<sol.maxKDivisibleComponents(n2,edges2,values2,k2);
    return 0;
}