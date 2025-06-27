// LC - 1026 - Medium - Maximum Difference Between Node and Ancestor
// 2 Approaches - Brute Force - Optimal
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    int ans=0;
    void solve(TreeNode* root,int &parentVal,int &curr){
        if(!root) return;

        curr=max(curr,abs(parentVal-root->val));

        solve(root->left,parentVal,curr);
        solve(root->right,parentVal,curr);
    }
    public:
    int maxAncestorDiff(TreeNode* root){
        if(!root) return 0;

        int curr=0;

        solve(root->left,root->val,curr);
        solve(root->right,root->val,curr);

        ans=max(ans,curr);

        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);

        return ans;
    }
};
class DFS2{
public:
    int solve(TreeNode* root,int minV,int maxV){
        if(!root) return abs(minV-maxV);
        
        minV=min(root->val,minV);
        maxV=max(root->val,maxV);

        int l=solve(root->left,minV,maxV);
        int r=solve(root->right,minV,maxV);

        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root){
        int minV=root->val;
        int maxV=root->val;

        return solve(root,minV,maxV);
    }
};
/*
-> Example 1:
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
:------------------:
-> Example 2:
Input: root = [1,null,2,null,0,3]
Output: 3
*/