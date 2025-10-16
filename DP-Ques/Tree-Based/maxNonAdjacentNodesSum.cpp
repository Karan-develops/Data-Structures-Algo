// GFG - Medium - Maximum Non-Adjacent Nodes Sum
// https://chatgpt.com/c/68ebfad6-1110-8323-b8f3-70b1cee5980a
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Tree_DP{
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        
        auto l=solve(root->left);
        auto r=solve(root->right);
        
        int take=root->val+l.second+r.second;
        int skip=max(l.first,l.second)+max(r.first,r.second);
        
        return {take,skip};
    }
    public:
    int getMaxSum(TreeNode *root){
        auto ans=solve(root);
        
        return max(ans.first,ans.second);
    }
};