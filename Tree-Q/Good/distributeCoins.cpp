// LC - 979 - Medium - Distribute Coins in Binary Tree
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    int solve(TreeNode* root,int &moves){
        if(!root) return 0;

        int l=solve(root->left,moves);
        int r=solve(root->right,moves);

        moves+=abs(l)+abs(r);

        return l+r+root->val-1;
    }
    public:
    int distributeCoins(TreeNode* root){
        int moves=0;

        solve(root,moves);
        return moves;
    }
};
/*
-> Example 1:
Input: root = [3,0,0]
Output: 2
:----------------------:
-> Example 2:
Input: root = [0,3,0]
Output: 3
*/