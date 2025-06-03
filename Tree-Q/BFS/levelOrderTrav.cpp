// LC - 102 - Easy - Binary Tree Level Order Traversal
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class levelBFS{
    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root) return {};
        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int N=q.size();
            vector<int>temp;
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                temp.push_back(node->data);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
/*
-> Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
:------------------------:
-> Example 2:
Input: root = [1]
Output: [[1]]
:------------------------:
-> Example 3:
Input: root = []
Output: []
*/