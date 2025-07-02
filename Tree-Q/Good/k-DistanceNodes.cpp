// LC - 863 - Medium - All Nodes Distance K in Binary Tree
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    unordered_map<TreeNode*,TreeNode*>parent;
    void inOrder(TreeNode* root){
        if(!root) return;

        if(root->left){
            parent[root->left]=root;
            inOrder(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            inOrder(root->right);
        }
    }
    void solve(TreeNode* target,vector<int>&ans,int k){
        queue<TreeNode*>q;
        unordered_set<int>visited;

        q.push(target);
        visited.insert(target->val);

        while(!q.empty()){
            if(k==0) break;

            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited.count(node->left->val)){
                    visited.insert(node->left->val);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right->val)){
                    visited.insert(node->right->val);
                    q.push(node->right);
                }
                if(parent.count(node) && !visited.count(parent[node]->val)){
                    visited.insert(parent[node]->val);
                    q.push(parent[node]);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            ans.push_back(temp->val);
        }
    }
    public:
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k){
        inOrder(root);

        vector<int>ans;

        solve(target,ans,k);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
:-----------------------:
-> Example 2:
Input: root = [1], target = 1, k = 3
Output: []
*/