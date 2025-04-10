// LC - 958 - Medium - Check Completeness of a Binary Tree
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
// If you ever encounter a NULL node, you must not encounter a non NULL node after that in a Level Order Traversal, this is the definition of a complete Binary Tree.
class BFS{
    public:
    bool isCompleteTree(Node* root){
        if(!root) return false;

        queue<Node*>q;
        q.push(root);
        // past me koi null node dekha h?
        bool past=false;
        
        while(!q.empty()){
            Node* currNode=q.front();
            q.pop();

            if(currNode==NULL) past=true;
            else{
                if(past) return false;

                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return true;
    }
};
class DFS{
    int countNodes(Node* root){
        if(!root) return 0;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    bool solve(Node* root,int totalNodes,int i){
        if(!root) return true;

        if(i>totalNodes) return false;

        return solve(root->left,totalNodes,2*i) && solve(root->right,totalNodes,2*i+1);
    }
    public:
    bool isCompleteTree(Node* root){
        int totalNodes=countNodes(root);
        return solve(root,totalNodes,1);
    }
};