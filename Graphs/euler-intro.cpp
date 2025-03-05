// Euler’s Theorem deals with traversing all edges of a graph exactly once.
#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>&adj,vector<bool>&visited,int u){
    visited[u]=true;
    for(auto &ngbr:adj[u]){
        if(!visited[ngbr]){
            dfs(adj,visited,ngbr);
        }
    }
}
bool isConnected(vector<vector<int>>&adj,int V){
    vector<bool>visited(V,false);
    // Find any non-zero degree vertex
    int nonZeroDegreeVertex=-1;
    for(int i=0;i<V;i++){
        if(adj[i].size()!=0){
            nonZeroDegreeVertex=i;
            break;
        }
    }
    // Dfs maaro uss nonZeroDegreeVertex se aur saare nodes visit ho jaane chahiye
    dfs(adj,visited,nonZeroDegreeVertex);
    // Check if all nodes are visited kyuki nonZeroDegreeVertex connected hona chahiye
    for(int i=0;i<V;i++){
        if(!visited[i] && adj[i].size()!=0) return false;
    }
    return true;
}
int euler(vector<vector<int>>&adj,int V){
    //Check if all non-zero degree vertices are connected
    if(isConnected(adj,V)==false) return 0; // Non-Eulerian
    //Count vertices with odd degree
    int oddDegree=0;
    for(int i=0;i<V;i++){
        if(adj[i].size()%2!=0) oddDegree++;
    }
    // If count is more than 2, then graph is not Eulerian
    if(oddDegree>2) return 0; // Non-Eulerian
    if(oddDegree==2) return 1; //Semi-Eulerian (It has only Euler Path)
    return 2; // Eulerian circuit
}
int main(){
    int V=3;
    vector<vector<int>>adj(V);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(0);
    cout<<euler(adj,V);
    return 0;
}