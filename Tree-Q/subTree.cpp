// LC - 572 - Easy - Subtree of Another Tree
// 2 Approaches
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
// Approach 1
class Solution{
public:
    bool solve(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        if(root->data!=subRoot->data) return false;

        return solve(root->left,subRoot->left) && solve(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root,TreeNode* subRoot){
        if(!root) return false;
        
        if(root->data==subRoot->data){
            if(solve(root,subRoot)==true) return true;
        }

        bool l=isSubtree(root->left,subRoot);
        bool r=isSubtree(root->right,subRoot);
        return l||r;
    }
};
// Approach 2
class Solution2{
public:
    string solve(TreeNode* root){
        if(!root) return "$";

        return "_"+to_string(root->data)+"_"+solve(root->left)+"_"+solve(root->right);
    }
    bool isSubtree(TreeNode* root,TreeNode* subRoot){
        string rootStr=solve(root);
        string subRootStr=solve(subRoot);

        return rootStr.find(subRootStr)!=string::npos;
    }
};
/*
-> Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
:----------------------:
-> Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
*/