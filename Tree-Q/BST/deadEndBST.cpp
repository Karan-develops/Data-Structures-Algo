// GFG - BST with Dead End
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class BST{
    bool isDeadEndUtil(Node* root,int minVal,int maxVal){
    if(!root) return false;

    if (minVal==maxVal) return true;

    return isDeadEndUtil(root->left,minVal,root->data-1) ||
           isDeadEndUtil(root->right,root->data+1,maxVal);
    }
    public:
    bool isDeadEnd(Node *root){
        return isDeadEndUtil(root,1,INT_MAX);
    }
};
/*
-> Example 1:
Input: root[] = [8, 5, 9, 2, 7, N, N, 1]
Output: true
:----------------------:
-> Example 2:
Input: root[] = [8, 7, 10, 2, N, 9, 13]
Output: true
*/