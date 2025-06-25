// LC - 129 - Medium - Sum Root to Leaf Numbers
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    int solve(TreeNode* root,int curr){
        if(!root) return 0;

        curr=curr*10+root->data;

        if(!root->left && !root->right) return curr;

        int l=solve(root->left,curr);
        int r=solve(root->right,curr);

        return l+r;
    }
    public:
    int sumNumbers(TreeNode* root){
        return solve(root,0);
    }
};
/*
-> Example 1:
Input: root = [1,2,3]
Output: 25
:---------------------------:
-> Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
*/