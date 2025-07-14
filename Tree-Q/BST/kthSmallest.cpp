// LC - 230 - Medium - Kth Smallest Element in a BST
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
// Approach 1 - Using Vector
class BST_Vector{
    void solve(TreeNode* root,vector<int>&ans){
        if(!root) return;

        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    public:
    int kthSmallest(TreeNode* root,int k){
        vector<int>ans;

        solve(root,ans);
        return ans[k-1];
    }
};
// Approach 2 - Just System Recursion Stack Space
class BST{
    void solve(TreeNode* root,int &k,int &ans){
        if(!root) return;

        solve(root->left,k,ans);

        k--;
        if(k==0){
            ans=root->val;
            return;
        }

        solve(root->right,k,ans);
    }
    public:
    int kthSmallest(TreeNode* root,int k){
        int ans=-1;
        solve(root,k,ans);

        return ans;
    }
};