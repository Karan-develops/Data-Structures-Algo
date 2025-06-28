// LC - 652 - Medium - Find Duplicate Subtrees
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
public:
    string solve(TreeNode* root,unordered_map<string,int>&subTrees,vector<TreeNode*>&ans){
        if(!root) return "$";

        string l=solve(root->left,subTrees,ans);
        string r=solve(root->right,subTrees,ans);

        string s=l+","+r+","+to_string(root->val);

        if(subTrees[s]==1) ans.push_back(root);

        subTrees[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
        unordered_map<string,int>subTrees;
        vector<TreeNode*>ans;
        
        solve(root,subTrees,ans);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
:------------------------:
-> Example 2:
Input: root = [2,1,1]
Output: [[1]]
:------------------------:
-> Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
*/