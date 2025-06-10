// LC - 2265 - Medium - Count Nodes Equal to Average of Subtree
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    int ans=0;
    pair<int,int> solve(TreeNode* root){
        if(!root) return {};

        pair<int,int> l=solve(root->left);
        pair<int,int> r=solve(root->right);

        int leftSum=l.first;
        int leftCount=l.second;

        int rightSum=r.first;
        int rightCount=r.second;

        int sum=leftSum+rightSum+root->data;
        int count=leftCount+rightCount+1;

        int avg=sum/count;

        if(root->data==avg) ans++;

        return {sum,count};
    }
    public:
    int averageOfSubtree(TreeNode* root){
        ans=0;

        solve(root);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [4,8,5,0,1,null,6]
Output: 5
:-------------------------:
-> Example 2:
Input: root = [1]
Output: 1
*/