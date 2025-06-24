// LC - 366 - Medium - Find Leaves of Binary Tree
// Premium Question - Google
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    map<int,vector<int>>mp;
    int collectNodeWithHeight(TreeNode* root){
        if(!root) return 0;
        
        int height=1+max(collectNodeWithHeight(root->left),collectNodeWithHeight(root->right));
        
        mp[height].push_back(root->data);

        return height;
    }
    vector<vector<int>> findLeaves(TreeNode * root){       
        mp.clear();
        collectNodeWithHeight(root);

        vector<vector<int>>ans;
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};