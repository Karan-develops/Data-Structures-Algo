// LC - 865 - Medium - Smallest Subtree with all the Deepest Nodes
#include<iostream>
#include<map>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Tree{
    int max_h=0;
    map<TreeNode*,int>mp;
    TreeNode* lca(TreeNode* root){
        if(!root || mp[root]==max_h) return root;

        TreeNode* l=lca(root->left);
        TreeNode* r=lca(root->right);

        if(l&&r) return root;
        return l?l:r;
    }
    void solve(TreeNode* root,int h){
        if(!root) return;

        mp[root]=h;
        max_h=max(max_h,h);

        solve(root->left,h+1);
        solve(root->right,h+1);
    }
    public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        solve(root,0);
        return lca(root);
    }
};