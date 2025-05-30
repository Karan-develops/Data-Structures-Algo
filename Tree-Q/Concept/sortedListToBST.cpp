// LC - 109 - Medium - Convert Sorted List to Binary Search Tree
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class ListNode{
    public:
    int data;
    ListNode* next;
};
class BST{
    public:
    TreeNode* sortedListToBST(ListNode* head){
        if(!head) return;
        if(!head->next) return new TreeNode(head->data);

        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        TreeNode* newNode=new TreeNode(slow->data);
        prev->next=NULL;

        newNode->left=sortedListToBST(head);
        newNode->right=sortedListToBST(slow->next);

        return newNode;
    }
};
/*
-> Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
:-------------------:
-> Example 2:
Input: head = []
Output: []
*/