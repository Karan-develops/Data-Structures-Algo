// LC - 111 - Easy - Minimum Depth of Binary Tree
#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BFS{
    public:
    int minDepth(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int ans=1;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int N=q.size();
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                if(!node->left && !node->right) return ans;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans++;
        }
        return ans;
    }
};
class DFS{
    public:
    int minDepth(TreeNode* root){
        if(!root) return 0;
        
        if(!root->left && !root->right) return 1;
        
        int l=root->left?minDepth(root->left):INT_MAX;
        int r=root->right?minDepth(root->right):INT_MAX;
        
        return 1+min(l,r);
    }
};