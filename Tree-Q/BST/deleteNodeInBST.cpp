// LC - 450 - Medium - Delete Node in a BST
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BST{
    public:
    TreeNode* deleteNode(TreeNode* root,int key){
        if(!root) return root;

        if(root->val>key){
            root->left=deleteNode(root->left,key);
        } else if(root->val<key){
            root->right=deleteNode(root->right,key);
        } else{
            // key node has zero child
            if(!root->left && !root->right) return NULL;
            // key node has one Child
            if(!root->left || !root->right){
                return root->left?root->left:root->right;
            }

            // Root has two child
            // largest value in left subtree is just smaller than key’s value.
            // OR we can interchange left & right in below code
            TreeNode* temp=root->left;
            
            while(temp->right){
                temp=temp->right;
            }
            
            // Replace that value
            root->val=temp->val;
            // Ab uss value ko hi key maan lo (key change)
            root->left=deleteNode(root->left,temp->val);
        }
        return root;
    }
};
/*
Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
:---------------------------:
Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
:---------------------------:
Example 3:
Input: root = [], key = 0
Output: []
*/