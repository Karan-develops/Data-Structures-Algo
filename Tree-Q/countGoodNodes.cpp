// LC - 1448 - Medium - Count Good Nodes in Binary Tree
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
    void solve(Node* root,int maxValSeen){
        if(!root) return;

        if(root->data>maxValSeen){
            ans++;
            maxValSeen=root->data;
        }

        solve(root->left,maxValSeen);
        solve(root->right,maxValSeen);
    }
    public:
    int goodNodes(Node* root){
        if(!root) return 0;
        solve(root,root->data);
        return ans;
    }
};
class BFS{
    public:
    int goodNodes(Node* root){
        if(!root) return 0;
        queue<pair<Node*,int>>q;
        q.push({root,root->data});
        int ans=0;
        while(!q.empty()){
            auto [currNode,maxValSeen]=q.front();
            q.pop();

            if(currNode->data>maxValSeen) ans++;
            int newMax=max(maxValSeen,currNode->data);

            if(currNode->left) q.push({currNode->left,newMax});
            if(currNode->right) q.push({currNode->right,newMax});
        }
        return ans;
    }
};