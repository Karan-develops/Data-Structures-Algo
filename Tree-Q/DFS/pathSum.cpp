// LC - 112 - Easy - Path Sum
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    bool solve(TreeNode* root,int targetSum){
        if(!root) return false;

        targetSum-=root->data;

        if(!root->left && !root->right){
            if(targetSum==0) return true;
        }

        bool l=solve(root->left,targetSum);
        bool r=solve(root->right,targetSum);

        // Either Get Answer from left or right
        return l||r;
    }
    public:
    bool hasPathSum(TreeNode* root, int targetSum){
        return solve(root,targetSum);
    }
};
/*
-> Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
:-----------------------:
-> Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
:-----------------------:
-> Example 3:
Input: root = [], targetSum = 0
Output: false
*/