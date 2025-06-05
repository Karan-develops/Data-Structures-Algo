// LC - 1110 - Medium - Delete Nodes And Return Forest
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    TreeNode* solve(TreeNode* root,vector<TreeNode*>&ans,unordered_set<int>&st){
        if(!root) return NULL;

        root->left=solve(root->left,ans,st);
        root->right=solve(root->right,ans,st);

        if(st.find(root->data)!=st.end()){
            if(root->left) ans.push_back(root->left);
            else if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    public:
    vector<TreeNode*> delNodes(TreeNode* root,vector<int>&to_delete){
        vector<TreeNode*>ans;

        unordered_set<int>st;
        for(int &i:to_delete) st.insert(i);

        solve(root,ans,st);

        if(st.count(root->data)) ans.push_back(root);

        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
:---------------------:
-> Example 2:
Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
*/