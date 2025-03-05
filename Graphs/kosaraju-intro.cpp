// Kosaraju’s Algorithm is used to find all Strongly Connected Components (SCCs) in a directed graph.
// Steps
// 1. Stack me topo Order me nodes daalo
// 2. Reverse krdo edges ko
// 3. Stack ke order me dfs maaro
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfsTopo(vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st,int u){
    visited[u]=true;
    for(auto &ngbr:adj[u]){
        if(!visited[ngbr]){
            dfsTopo(adj,visited,st,ngbr);
        }
    }
    st.push(u);
}
void dfs(vector<vector<int>>&adj,vector<bool>&visited,int u){
    visited[u]=true;
    for(auto &ngbr:adj[u]){
        if(!visited[ngbr]){
            dfs(adj,visited,ngbr);
        }
    }
}
int kosaRaju(vector<vector<int>>&adj,int V){
    // 1. Fill stack with topo order
    stack<int>st;
    vector<bool>visited(V,false);
    for(int u=0;u<V;u++){
        if(!visited[u]){
            dfsTopo(adj,visited,st,u);
        }
    }
    // 2. Reverse edges of graph (Transpose)
    vector<vector<int>>reversedAdj(V);
    for(int u=0;u<V;u++){
        for(auto &v:adj[u]){
            reversedAdj[v].push_back(u);
        }
    }
    // 3. Dfs in stack order to count SCC
    int count=0;
    visited=vector<bool>(V,false);
    while(!st.empty()){
        if(visited[st.top()]) st.pop();
        else{
            dfs(reversedAdj,visited,st.top());
            count++;
        }
    }
    return count;
}
int main(){
    int V=5;
    vector<vector<int>>adj={{1},{2},{0,3},{4},{}};
    cout<<kosaRaju(adj,V);
    return 0;
}