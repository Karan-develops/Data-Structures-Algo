// LC - 1080 - Medium - Insufficient Nodes in Root to Leaf Paths
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Tree{
    public:
    TreeNode* sufficientSubset(TreeNode* root,int limit){
        // Reached Leaf Node
        if(!root->left && !root->right){
            return root->val<limit?NULL:root;
        }
        
        if(root->left){
            root->left=sufficientSubset(root->left,limit-root->val);
        }
        if(root->right){
            root->right=sufficientSubset(root->right,limit-root->val);
        }

        /* Dry Run -> Example 3 You will see we have to return NULL if 
           tree below current node is insufficient */
        return (!root->left && !root->right)?NULL:root;
    }
};
/*
-> Example 1:
Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]
:----------------------------:
-> Example 2:
Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
Output: [5,4,8,11,null,17,4,7,null,null,null,5]
:----------------------------:
-> Example 3:
Input: root = [1,2,-3,-5,null,4,null], limit = -1
Output: [1,null,-3,4]
*/