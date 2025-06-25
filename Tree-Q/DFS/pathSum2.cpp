// LC - 113 - Medium - Path Sum II
#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>path,int targetSum){
        if(!root) return;

        path.push_back(root->data);
        targetSum-=root->data;

        // Reached Leaf Node
        if(!root->left && !root->right){
            if(targetSum==0){
                ans.push_back(path);
            }
            return;
        }

        solve(root->left,ans,path,targetSum);
        solve(root->right,ans,path,targetSum);
    }
    public:
    vector<vector<int>> pathSum(TreeNode* root,int targetSum){
        vector<vector<int>>ans;
        vector<int>path;

        solve(root,ans,path,targetSum);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
:---------------------------------:
-> Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []
:---------------------------------:
-> Example 3:
Input: root = [1,2], targetSum = 0
Output: []
*/