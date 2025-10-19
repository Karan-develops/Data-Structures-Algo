// GFG - Medium - BST to greater sum tree
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BST{
    int sum;
    void solve(TreeNode* root){
        if(!root) return;
        
        solve(root->right);
        
        int curr=root->val;
        root->val=sum;
        sum+=curr;
        
        solve(root->left);
    }
    public:
    void transformTree(TreeNode *root){
        sum=0;
        
        solve(root);
    }
};
/*
Input: root = [11, 2, 29, 1, 7, 15, 40, N, N, N, N, N, N, 35, N]
Output: [119, 137, 75, 139, 130, 104, 0, N, N, N, N, N, N, 40, N]
:-------------------------:
Input: root = [2, 1, 6, N, N, 3, 7]
Output: [16, 18, 7, N, N, 13, 0]
*/