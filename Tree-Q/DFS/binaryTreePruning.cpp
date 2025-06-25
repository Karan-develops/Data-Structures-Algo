// LC - 814 - Medium - Binary Tree Pruning
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    public:
    TreeNode* pruneTree(TreeNode* root){
        if(!root) return NULL;

        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);

        if(!root->left && !root->right && root->data==0){
            return NULL;
        }
        
        return root;
    }
};
/*
-> Example 1:
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
:--------------------:
-> Example 2:
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
:--------------------:
-> Example 3:
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
*/