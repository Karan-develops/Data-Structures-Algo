// GFG - Medium - Median of BST
#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BST{
    void solve(TreeNode* root,vector<int>&v){
        if(!root) return;
        
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    public:
    int findMedian(TreeNode* root){
        vector<int>v;
        
        solve(root,v);
        
        int n=v.size();
        if(n&1) return v[((n+1)/2)-1];
        
        return v[(n/2)-1];
    }
};
/*
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14]
Output: 12
:----------------------------:
Input: root = [5, 4, 8, 1]
Output: 4
*/