// LC - 1361 - Medium - Validate Binary Tree Nodes
// DSU Also in Graphs
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class BFS{
    public:
    bool validateBinaryTreeNodes(int n,vector<int>&leftChild,vector<int>&rightChild){
        // Parent to child
        unordered_map<int,vector<int>>adj;
        // Child to parent
        unordered_map<int,int>mp;

        // Step 1 : Check if any child has more than 1 parent
        for(int i=0;i<n;i++){
            int parent=i;
            int lC=leftChild[i];
            int rC=rightChild[i];

            if(lC!=-1){
                adj[parent].push_back(lC);
                // There is more than 1 parent
                if(mp.find(lC)!=mp.end()) return false;

                mp[lC]=parent;
            }
            if(rC!=-1){
                adj[parent].push_back(rC);
                // There is more than 1 parent
                if(mp.find(rC)!=mp.end()) return false;

                mp[rC]=parent;
            }
        }

        // Step 2 : There should be only 1 root
        int root=-1;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                // More than 1 root
                if(root!=-1) return false;

                root=i;
            }
        }

        // No root
        if(root==-1) return false;
            
        // Step 3 : Traversal ( BFS/DFS )
        queue<int>q;
        vector<bool>visited(n,false);

        q.push(root);
        visited[root]=true;
        int count=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int &ngbr:adj[node]){
                if(!visited[ngbr]){
                    visited[ngbr]=true;
                    q.push(ngbr);
                    count++;
                }
            }
        }
        // Also checks for connected tree
        return count==n;
    }
};
int main(){
    // Output: true
    int n=4;
    vector<int>leftChild={1,-1,3,-1},rightChild={2,-1,-1,-1};
    // Output: false
    int n2=4;
    vector<int>leftChild2={1,-1,3,-1},rightChild2={2,3,-1,-1};
    // Output: false
    int n3=2;
    vector<int>leftChild3={1,0},rightChild3={-1,-1};

    BFS sol;
    cout<<sol.validateBinaryTreeNodes(n,leftChild,rightChild)<<endl;
    cout<<sol.validateBinaryTreeNodes(n2,leftChild2,rightChild2)<<endl;
    cout<<sol.validateBinaryTreeNodes(n3,leftChild3,rightChild3);
    return 0;
}