// LC - 1339 - Medium - Maximum Product of Splitted Binary Tree
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    long M=1e9+7;
    long totalSum=0,maxP=0;
    
    int findTotalSum(TreeNode* root){
        if(!root) return 0;
        
        int leftSubtreeSum=findTotalSum(root->left);
        int rightSubtreeSum=findTotalSum(root->right);
        int sum=root->val+leftSubtreeSum+rightSubtreeSum;
        
        maxP=max(maxP,(totalSum-sum)*sum);
        
        return sum;
    }
    public:
    int maxProduct(TreeNode* root){
        if(!root) return 0;
        
        maxP=0;
        totalSum=findTotalSum(root);
        
        findTotalSum(root);

        return maxP%M;
    }
};
/*
-> Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
:--------------------:
-> Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
*/