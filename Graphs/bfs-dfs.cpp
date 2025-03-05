#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
void BFS(vector<vector<int>>&adj,int u){
    int V=adj.size();
    vector<bool>visited(V,false);
    queue<int>q;
    // BFS Start
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int &ngbr:adj[curr]){
            if(!visited[ngbr]){
                visited[ngbr]=true;
                q.push(ngbr);
            }
        }
    }
    cout<<endl;
    return;
}
void DFS(vector<vector<int>>&adj,vector<bool>&visited,int u){
    if(visited[u]) return;
    visited[u]=true;
    cout<<u<<" ";
    for(int &ngbr:adj[u]){
        if(!visited[ngbr]){
            DFS(adj,visited,ngbr);
        }
    }
}
void DFSusingStack(vector<vector<int>>&adj,int u){
    int V=adj.size();
    vector<bool>visited(V,false);
    stack<int>st;
    // Start DFS
    st.push(u);
    visited[u]=true;
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<" ";
        for(int &ngbr:adj[curr]){
            if(!visited[ngbr]){
                visited[ngbr]=true;
                st.push(ngbr);
            }
        }
    }
    return;
}
int main(){
    int V=5;
    vector<vector<int>>adj(V);
    vector<vector<int>>adj2(V);
    vector<vector<int>>adj3(V);
    vector<bool>visi(V,false);
    adj[0]={1,2};
    adj[1]={0,3,4};
    adj[2]={0,4};
    adj[3]={1};
    adj[4]={1,2};
    adj2[0]={1,2};
    adj2[1]={0,3,4};
    adj2[2]={0,4};
    adj2[3]={1};
    adj2[4]={1,2};
    adj3[0]={1,2};
    adj3[1]={0,3,4};
    adj3[2]={0,4};
    adj3[3]={1};
    adj3[4]={1,2};
    cout<<"BFS:";
    BFS(adj,0);
    cout<<"DFS:";
    DFS(adj2,visi,0);
    cout<<endl<<"DFS-Stack:";
    DFSusingStack(adj3,0);
    return 0;
}