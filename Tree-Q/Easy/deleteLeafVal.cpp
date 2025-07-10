// LC - 1325 - Medium - Delete Leaves With a Given Value
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    TreeNode* solve(TreeNode* root,int &target){
        if(!root) return NULL;

        root->left=solve(root->left,target);
        root->right=solve(root->right,target);

        if(!root->left && !root->right && root->val==target){
            return NULL;
        }

        return root;
    }
    public:
    TreeNode* removeLeafNodes(TreeNode* root,int target){
        return solve(root,target);
    }
};
/*
-> Example 1:
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
:--------------------------:
-> Example 2:
Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
:--------------------------:
-> Example 3:
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
*/