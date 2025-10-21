// GFG - Medium - K closest Values
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BST{
    int K,T;
    priority_queue<pair<int,int>>pq;
    void solve(TreeNode* root){
        if(!root) return;
        
        solve(root->left);
        
        pq.push({abs(T-root->val),root->val});
        
        if(pq.size()>K) pq.pop();
        
        solve(root->right);
    }
    public:
    vector<int> getKClosest(TreeNode* root,int target,int k){
        K=k;
        T=target;
        pq=priority_queue<pair<int,int>>();
        
        solve(root);
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
/*
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], target = 17, k = 3
Output: [14, 20, 12]
:-----------------------------:
Input: root = [5, 4, 8, 1], target = 5, k = 2
Output: [5, 4]
*/