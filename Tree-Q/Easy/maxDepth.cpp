// LC - 104 - Easy - Maximum Depth of Binary Tree
// 2 Approaches
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class DFS{
    int ans=0;
    void solve(Node* root,int h){
        if(!root) return;

        ans=max(ans,h);

        solve(root->left,h+1);
        solve(root->right,h+1);
    }
    public:
    int maxDepth(Node* root){
        if(!root) return 0;
        solve(root,0);
        return ans+1; // Including Root :)
    }
};
class BFS{
    public:
    int maxDepth(Node* root){
        if(!root) return 0;
        int ans=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int N=q.size();
            while(N--){
                Node* currNode=q.front();
                q.pop();

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            ans++;
        }
        return ans;
    }
};