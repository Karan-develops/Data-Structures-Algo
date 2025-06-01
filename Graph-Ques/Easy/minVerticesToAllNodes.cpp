// LC - 1557 - Easy - Minimum Number of Vertices to Reach All Nodes
#include<iostream>
#include<vector>
using namespace std;
vector<int> findSmallestSetOfVertices(int n,vector<vector<int>>&edges){
    vector<int>inDegree(n,false);

    for(auto &vec:edges){
        int u=vec[0];
        int v=vec[1];

        inDegree[v]=true;
    }

    vector<int>ans;

    for(int i=0;i<n;i++){
        if(inDegree[i]==false){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    // Output: [0,3]
    int n=6;
    vector<vector<int>>edges={{0,1},{0,2},{2,5},{3,4},{4,2}};
    // Output: [0,2,3]
    int n2=5;
    vector<vector<int>>edges2={{0,1},{2,1},{3,1},{1,4},{2,4}};
    return 0;
}