// LC - 1367 - Medium - Linked List in Binary Tree
#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution{
    bool check(ListNode* head,TreeNode* root){
        if(!head) return true;
        if(!root) return false;
        
        if(root->val!=head->val){
            return false;
        }

        return check(head->next,root->left) || check(head->next,root->right);
    }
    public:
    bool isSubPath(ListNode* head,TreeNode* root){
        if(!root) return false;

        return check(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};
/*
-> Example 1:
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
:----------------------------:
-> Example 2:
Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
:----------------------------:
-> Example 3:
Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
*/