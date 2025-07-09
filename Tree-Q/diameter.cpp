// LC - 543 - Easy - Diameter of Binary Tree
// 2 Approaches
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    int solve(TreeNode* root,int &ans){
        if(!root) return 0;

        int l=solve(root->left,ans);
        int r=solve(root->right,ans);

        ans=max(ans,l+r); // Curved path
        
        return max(l,r)+1;
    }
    public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans=0;
        solve(root,ans);
        return ans;
    }
};
class Solution{
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};

        auto [leftHeight,leftDiameter]=solve(root->left);
        auto [rightHeight,rightDiameter]=solve(root->right);

        int height=max(leftHeight,rightHeight)+1;
        int diameter=max(max(leftDiameter,rightDiameter),leftHeight+rightDiameter);

        return {height,diameter};
    }
    public:
    int diameterOfBinaryTree(TreeNode* root){
        return solve(root).second;
    }
};