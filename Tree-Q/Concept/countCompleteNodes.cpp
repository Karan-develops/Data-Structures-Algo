// LC - 222 - Easy - Count Complete Tree Nodes
// 2 Approaches - O(n) - Less than < O(n)
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    int getLeftHeight(TreeNode* root){
        TreeNode* temp=root;
        int h=0;

        while(temp){
            temp=temp->left;
            h++;
        }
        return h;
    }
    int getRightHeight(TreeNode* root){
        TreeNode* temp=root;
        int h=0;

        while(temp){
            temp=temp->right;
            h++;
        }
        return h;
    }
    public:
    // < O(n)
    int countNodes(TreeNode* root){
        if(!root) return 0;

        int lh=getLeftHeight(root);
        int rh=getRightHeight(root);

        if(lh==rh) return pow(2,lh)-1; // 2^h - 1

        return countNodes(root->left)+countNodes(root->right)+1;
    }
    // O(n)
    int countNodes(TreeNode* root){
        if(!root) return 0;

        queue<TreeNode*>q;

        q.push(root);
        int ans=0;

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            ans++;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6
:------------------:
-> Example 2:
Input: root = []
Output: 0
:------------------:
-> Example 3:
Input: root = [1]
Output: 1
*/