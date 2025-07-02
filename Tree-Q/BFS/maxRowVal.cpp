// LC - 515 - Medium - Find Largest Value in Each Tree Row
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
class BFS{
    public:
    vector<int> largestValues(TreeNode* root){
        if(!root) return {};

        queue<TreeNode*>q;
        vector<int>ans;
        
        q.push(root);

        while(!q.empty()){
            int N=q.size();
            int maxVal=INT_MIN;
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                maxVal=max(maxVal,node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
:---------------------:
-> Example 2:
Input: root = [1,2,3]
Output: [1,3]
*/