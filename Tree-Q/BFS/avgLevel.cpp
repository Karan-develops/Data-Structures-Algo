// LC - 637 - Easy - Average of Levels in Binary Tree
#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class BFS{
public:
    vector<double> averageOfLevels(TreeNode* root){
        if(!root) return {};

        vector<double>ans;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int N=q.size();
            double avg=0;
            int count=N;
            while(N--){
                TreeNode* node=q.front();
                q.pop();

                avg+=(node->data);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(avg/count);
        }
        return ans;
    }
};
/*
-> Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
:----------------------------:
-> Example 2:
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
*/