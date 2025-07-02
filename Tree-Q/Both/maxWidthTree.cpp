// LC - 662 - Medium - Maximum Width of Binary Tree
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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;

        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});

        ll ans=0;

        while(!q.empty()){
            ll L=q.front().second;
            ll R=q.back().second;

            ans=max(ans,R-L+1);

            int N=q.size();
            while(N--){
                TreeNode* node=q.front().first;
                ll w=q.front().second;
                q.pop();

                if(node->left) q.push({node->left,2*w+1});
                if(node->right) q.push({node->right,2*w+2});
            }
        }
        return ans;
    }
};
class DFS{
    typedef unsigned long long ll;
    void solve(TreeNode* root,ll d,int level,vector<int>&arr,ll &ans){
        if(!root) return;
        
        if(level==arr.size()) arr.push_back(d);
        else ans=max(ans,d-arr[level]+1);   
        
        solve(root->left,2*d+1,level+1,arr,ans);
        solve(root->right,2*d+2,level+1,arr,ans);
    }
    public:
    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        
        ll ans=1;
        vector<int>arr;
        solve(root,0,0,arr,ans);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
:------------------------:
-> Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
:------------------------:
-> Example 3:
Input: root = [1,3,2,5]
Output: 2
*/