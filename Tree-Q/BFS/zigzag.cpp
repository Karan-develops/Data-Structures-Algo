// LC - 103 - Medium - Binary Tree Zigzag Level Order Traversal
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class BFS{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>ans;
        bool flag=true;

        while(!q.empty()){
            int N=q.size();
            vector<int>temp;
            flag=!flag;
            while(N--){
                TreeNode* curr=q.front();
                q.pop();

                temp.push_back(curr->data);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(flag) reverse(begin(temp),end(temp));
            ans.push_back(temp);
        }
        return ans;
    }
};
/*
-> Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
:------------------------:
-> Example 2:
Input: root = [1]
Output: [[1]]
:------------------------:
-> Example 3:
Input: root = []
Output: []
*/