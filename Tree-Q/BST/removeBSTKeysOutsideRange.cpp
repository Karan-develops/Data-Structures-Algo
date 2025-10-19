// GFG - Remove BST keys outside given range
// Same as LC - 669 (Trim a Binary Search Tree)
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
// * -> We can comment these also
class BST{
    public:
    TreeNode* removekeys(TreeNode* root,int l,int r){
        if (!root) return NULL;

        root->left=removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
    
        if(root->val<l){
            TreeNode* rightChild=root->right; // *
            delete root; // *
            return rightChild;
        }
        if(root->val>r){
            TreeNode* leftChild=root->left; // *
            delete root; // *
            return leftChild;
        }
    
        return root;
    }
};
/*
Input: root = [6, -13, 14, N, -8, 13, 15, N, N, 7], l = -10, r = 13
Output: [6, -8, 13, N, N, 7]
:-----------------------------------:
Input: root = [14, 4, 16, 2, 8, 15, N, -8, 3, 7, 10], l = 2, r = 6 
Output: [4, 2, N, N, 3]
*/