// Graph should be DAG (Directed Acyclic Graph)
// 'u' se pehle 'v' ko daalo stack me
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st,int u){
    visited[u]=true;
    //pehle mere ('u' node ke ) bachho ko daalo
    for(int &ngbr:adj[u]){
        if(!visited[ngbr]){
            dfs(adj,visited,st,ngbr);
        }
    }
    //ab mujhe daalo stack me
    st.push(u);
}
vector<int> topoSort(vector<vector<int>>&adj,int V){
    vector<bool>visited(V,false);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(adj,visited,st,i);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int V=6;
    vector<vector<int>>adj(V);
    adj[0]={1,2};
    adj[1]={3};
    adj[2]={3};
    adj[3]={4};
    adj[4]={5};
    adj[5]={};
    vector<int>ans=topoSort(adj,V);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}