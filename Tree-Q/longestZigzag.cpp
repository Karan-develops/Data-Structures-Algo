// LC - 1372 - Medium - Longest ZigZag Path in a Binary Tree
// 3 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Approach1{
    int ans=0;
    void solve(TreeNode* root,int steps,bool goLeft){
        if(!root) return;

        ans=max(ans,steps);

        if(goLeft){
            solve(root->right,steps+1,false);
            solve(root->left,1,true);
        } else{
            solve(root->left,steps+1,true);
            solve(root->right,1,false);
        }
    }
    public:
    int longestZigZag(TreeNode* root){
        ans=0;
        solve(root,0,true);
        solve(root,0,false);

        return ans;
    }
};
class Approach2{
    int ans=0;
    void solve(TreeNode* root,int left,int right){
        if(!root) return;

        ans=max({ans,left,right});
        
        solve(root->left,right+1,0);
        solve(root->right,0,left+1);
    }
    int longestZigZag(TreeNode* root){
        ans=0;   
        solve(root,0,0);

        return ans;
    }
};
class Approach3{
    int ans=0;
    vector<int> solve(TreeNode* root){
        if(!root) return {0,0};
        
        vector<int>reL=solve(root->left);
        vector<int>reR=solve(root->right);
        
        int L=reL[0];
        int R=reR[1];
        
        ans=max({ans,L,R});
        
        return {R+1,L+1};
    }
    int longestZigZag(TreeNode* root){
        ans=0;
        solve(root);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
:-------------------------------:
-> Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
:-------------------------------:
-> Example 3:
Input: root = [1]
Output: 0
*/