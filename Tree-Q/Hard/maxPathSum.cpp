// LC - 124 - HARD - Binary Tree Maximum Path Sum
#include<iostream>
#include<algorithm>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    int ans;
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        int found_answer_below=l+r+root->val; // (1)

        int best_of_left_right=max(l,r)+root->val; // (2)

        int root_is_best=root->val; // (3)

        // Best Max between 1,2,3
        ans=max({ans,found_answer_below,best_of_left_right,root_is_best});

        /* Note that we can proceed making path with (1) Bcoz we are considering curved
           path in the tree */
        return max(root_is_best,best_of_left_right);
    }
    public:
    int maxPathSum(TreeNode* root){
        ans=INT_MIN;

        solve(root);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,2,3]
Output: 6
:-------------------:
-> Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
*/