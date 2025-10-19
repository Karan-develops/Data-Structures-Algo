// LC - 669 - Medium - Trim a Binary Search Tree
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BST{
    public:
    TreeNode* trimBST(TreeNode* root,int low,int high){
        if(!root) return root;

        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);

        if(root->val<low){
            return root->right;
        }
        if(root->val>high){
            return root->left;
        }

        return root;
    }
};
/*
Example 1:
Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
:-------------------------------:
Example 2:
Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
*/