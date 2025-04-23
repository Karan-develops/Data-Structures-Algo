// LC - 700 - Easy - Search in a Binary Search Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution {
    public:
    Node* solve(Node* root,int val){
        if(!root) return NULL;

        if(root->data==val) return root;

        if(root->data>val) return solve(root->left,val);

        return solve(root->right,val);
    }
    Node* searchBST(Node* root, int val) {
        return solve(root,val);
    }
};