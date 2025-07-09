// LC - 513 - Medium - Find Bottom Left Tree Value
// 2 Approaches - BFS - DFS
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
    int findBottomLeftValue(TreeNode* root){
        queue<TreeNode*>q;

        q.push(root);
        int ans=-1;

        while(!q.empty()){
            int N=q.size();
            ans=q.front()->val;
            while(N--){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};
class DFS{
    int maxDepth;
    int ans;
    void solve(TreeNode* root,int currDepth){
        if(!root) return;
        
        if(currDepth>maxDepth){
            maxDepth=currDepth;
            ans=root->val;
        }
        
        solve(root->left,currDepth+1);
        solve(root->right,currDepth+1);
    }
    public:
    int findBottomLeftValue(TreeNode* root){
        maxDepth=-1;
        
        solve(root,0);
        return ans;
    }
};