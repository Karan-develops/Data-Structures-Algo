// LC - 2331 - Easy - Edatauate Boolean Binary Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    bool solve(Node* root){
        if(root->data==0) return false;
        if(root->data==1) return true;
        
        bool l=solve(root->left);
        bool r=solve(root->right);
        
        if(root->data==2) return l|r;
        return l&r;
    }
    public:
    bool edatauateTree(Node* root) {
        return solve(root);
    }
};
/*
Example 1:
Input: root = [2,1,3,null,null,0,1]
Output: true

Example 2:
Input: root = [0]
Output: false
*/